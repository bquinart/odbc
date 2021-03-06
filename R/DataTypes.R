#' Return the corresponding ODBC data type for an R object
#'
#' This is used when creating a new table with `dbWriteTable()`.
#' Databases with default methods defined are
#' - MySQL
#' - PostgreSQL
#' - SQL Server
#' - SQLite
#' - Spark
#' - Hive
#' - Impala
#'
#' If you are using a different database and `dbWriteTable()` fails with a SQL
#' parsing error the default method is not appropriate, you will need to write
#' a new method.
#'
#' @section Defining a new dbDataType method:
#'
#' The object type for your connection will be the database name retrieved by
#' `dbGetInfo(con)$dbms.name`. Use the documentation provided with your
#' database to determine appropriate values for each R data type. An example
#' method definition of a fictional `foo` database follows.
#' ```
#' con <- dbConnect(odbc::odbc(), "FooConnection")
#' dbGetInfo(con)$dbms.name
#' #> [1] "foo"
#'
#' `odbcDataType.foo <- function(con, obj, ...) {
#'   switch_type(obj,
#'     factor = "VARCHAR(255)",
#'     datetime = "TIMESTAMP",
#'     date = "DATE",
#'     binary = "BINARY",
#'     integer = "INTEGER",
#'     double = "DOUBLE",
#'     character = "VARCHAR(255)",
#'     logical = "BIT",
#'     list = "VARCHAR(255)",
#'     stop("Unsupported type", call. = FALSE)
#'   )
#' }
#' ```
#' @param con A driver connection object, as returned by `dbConnect()`.
#' @param obj An R object.
#' @param ... Additional arguments passed to methods.
#' @return Corresponding SQL type for the `obj`.
#' @export
odbcDataType <- function(con, obj, ...) UseMethod("odbcDataType")

#' @export
odbcDataType.default <- function(con, obj, ...) {
  switch_type(obj,
    factor = "VARCHAR(255)",
    datetime = "TIMESTAMP",
    date = "DATE",
    binary = "BINARY",
    integer = "INTEGER",
    double = "DOUBLE",
    character = "VARCHAR(255)",
    logical = "VARCHAR(5)", # Needs to be able to handle NA as well as TRUE, FALSE
    list = "VARCHAR(255)",
    stop("Unsupported type", call. = FALSE)
  )
}

#' @export
`odbcDataType.Spark SQL` <- function(con, obj, ...) {
  switch_type(obj,
    factor = "VARCHAR(255)",
    datetime = "DATE",
    date = "DATE",
    binary = "BINARY",
    integer = "INT",
    double = "DOUBLE",
    character = "VARCHAR(255)",
    logical = "BOOLEAN",
    list = "VARCHAR(255)",
    stop("Unsupported type", call. = FALSE)
  )
}

#' @export
`odbcDataType.Hive` <- function(con, obj, ...) {
  switch_type(obj,
    factor = "STRING",
    datetime = "TIMESTAMP",
    date = "DATE",
    binary = "BINARY",
    integer = "INT",
    double = "DOUBLE",
    character = "STRING",
    logical = "BOOLEAN",
    list = "STRING",
    stop("Unsupported type", call. = FALSE)
  )
}

# TODO: Revisit binary type (Impala)
#' @export
`odbcDataType.Impala` <- function(con, obj, ...) {
  switch_type(obj,
              factor = "STRING",
              datetime = "STRING",
              date = "VARCHAR(10)",
              integer = "INT",
              double = "DOUBLE",
              character = "STRING",
              logical = "BOOLEAN",
              list = "STRING",
              stop("Unsupported type", call. = FALSE)
  )
}

#' @export
`odbcDataType.MySQL` <- function(con, obj, ...) {
  switch_type(obj,
    factor = "TEXT",
    datetime = "DATETIME",
    date = "DATE",
    binary = "BLOB",
    integer = "INTEGER",
    double = "DOUBLE",
    character = "TEXT",
    logical = "TINYINT",
    list = "TEXT",
    stop("Unsupported type", call. = FALSE)
  )
}

#' @export
`odbcDataType.PostgreSQL` <- function(con, obj, ...) {
  switch_type(obj,
    factor = "TEXT",
    datetime = "TIMESTAMP",
    date = "DATE",
    binary = "bytea",
    integer = "INTEGER",
    double = "DOUBLE PRECISION",
    character = "TEXT",
    logical = "BOOLEAN",
    list = "TEXT",
    stop("Unsupported type", call. = FALSE)
  )
}

#' @export
`odbcDataType.Microsoft SQL Server` <- function(con, obj, ...) {
  switch_type(obj,
    factor = varchar(obj),
    datetime = "DATETIME",
    date = "DATE",
    binary = varbinary(obj),
    integer = "INT",
    double = "FLOAT",
    character = varchar(obj),
    logical = "BIT",
    list = varchar(obj),
    stop("Unsupported type", call. = FALSE)
  )
}

#' @export
`odbcDataType.SQLite` <- function(con, obj, ...) {
  switch_type(obj,
    factor = "TEXT",
    datetime = "NUMERIC",
    date = "NUMERIC",
    binary = "BLOB",
    integer = "INTEGER",
    double = "REAL",
    character = "TEXT",
    logical = "NUMERIC",
    list = "TEXT",
    stop("Unsupported type", call. = FALSE)
  )
}

#' @export
`odbcDataType.NetezzaSQL <- function(con, obj, ...) {
  switch_type(
    obj,
    factor = "NVARCHAR",
    datetime = "TIMESTAMP",
    date = "DATE",
    binary = "VARBINARY",
    integer = "INTEGER",
    double = "DOUBLE",
    character = "NVARCHAR",
    logical = "BOOLEAN",
    list = "NVARCHAR",
    stop("Unsupported type", call. = FALSE)
  )
}

switch_type <- function(obj, ...) {
  switch(object_type(obj), ...)
}

object_type <- function(obj) {
  if (is.factor(obj)) return("factor")
  if (is(obj, "POSIXct")) return("datetime")
  if (is(obj, "Date")) return("date")
  if (is(obj, "blob")) return("binary")

  return(typeof(obj))
}

varchar <- function(x, type = "varchar") {
  max_length <- max(nchar(as.character(x)), na.rm = TRUE)
  paste0(type, "(", max(255, max_length), ")")
}

varbinary <- function(x, type = "varbinary") {
  max_length <- max(lengths(x), na.rm = TRUE)
  paste0(type, "(", max(255, max_length), ")")
}

#' Test round tripping a simple table
#'
#' This tests all the supported data types, including missing values. It first
#' writes them to the database, then reads them back and verifies the data is
#' identical to the original.
#'
#' This function is not exported and should only be used during tests and as a
#' sanity check when writing new `odbcDataType()` methods.
#'
#' @param con An established DBI connection.
#' @param columns Table columns to exclude (default) or include, dependent on
#' the value of `invert`. One of `datetime`, `date`, `binary`,
#' `integer`, `double`, `character`, `logical`.
#' @param invert If `TRUE`, change the definition of columns to be inclusive,
#' rather than exclusive.
#' @examples
#' \dontrun{
#' test_roundtrip(con)
#'
#' # exclude a few columns
#' test_roundtrip(con, c("integer", "double"))
#'
#' # Only test a specific column
#' test_roundtrip(con, "integer", invert = FALSE)
#' }
#' @importFrom stats runif
test_roundtrip <- function(con = DBItest:::connect(DBItest:::get_default_context()), columns = "", invert = TRUE) {
  dbms <- dbGetInfo(con)$dbms.name
  testthat::context(paste0("roundtrip[", dbms, "]"))
  res <- list()
  testthat::test_that(paste0("[", dbms, "] round tripping data.frames works"), {
    on.exit(try(DBI::dbRemoveTable(con, "test_table"), silent = TRUE))
    set.seed(42)

    iris <- datasets::iris

    # We can't use the data.frame constructor directly as list columns don't work there.
    sent <- list(

      # We always return strings as factors
      #factor = iris$Species,

      datetime = as.POSIXct(as.numeric(iris$Petal.Length * 10), origin = "2016-01-01", tz = "UTC"),
      date = as.Date(iris$Sepal.Width * 100, origin = Sys.time()),
      binary = blob::as.blob(lapply(seq_len(NROW(iris)), function(x) as.raw(sample(0:100, size = sample(0:25, 1))))),
      integer = as.integer(iris$Petal.Width * 100),
      double = iris$Sepal.Length,
      character = as.character(iris$Species),
      logical = sample(c(TRUE, FALSE), size = nrow(iris), replace = T)
    )
    attributes(sent) <- list(names = names(sent), row.names = c(NA_integer_, -length(sent[[1]])), class = "data.frame")

    # Add a proportion of NA values to a data frame
    add_na <- function(x, p = .1) { is.na(x) <- runif(length(x)) < p; x}
    sent[] <- lapply(sent, add_na, p = .1)
    if (isTRUE(invert)) {
      sent <- sent[, !names(sent) %in% columns]
    } else {
      sent <- sent[, names(sent) %in% columns]
    }

    DBI::dbWriteTable(con, "test_table", sent, overwrite = TRUE)
    received <- DBI::dbReadTable(con, "test_table")
    testthat::expect_equal(sent, received)
    res <<- list(sent = sent, received = received)
  })
  invisible(res)
}
