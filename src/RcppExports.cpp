// This file was generated by Rcpp::compileAttributes
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include "odbconnect_types.h"
#include <Rcpp.h>

using namespace Rcpp;

// list_drivers
Rcpp::DataFrame list_drivers();
RcppExport SEXP odbconnect_list_drivers() {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    __result = Rcpp::wrap(list_drivers());
    return __result;
END_RCPP
}
// odbconnect_connect
connection_ptr odbconnect_connect(std::string const& connection_string);
RcppExport SEXP odbconnect_odbconnect_connect(SEXP connection_stringSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< std::string const& >::type connection_string(connection_stringSEXP);
    __result = Rcpp::wrap(odbconnect_connect(connection_string));
    return __result;
END_RCPP
}
// connection_info
Rcpp::List connection_info(connection_ptr const& p);
RcppExport SEXP odbconnect_connection_info(SEXP pSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< connection_ptr const& >::type p(pSEXP);
    __result = Rcpp::wrap(connection_info(p));
    return __result;
END_RCPP
}
// connection_quote
std::string connection_quote(connection_ptr const& p);
RcppExport SEXP odbconnect_connection_quote(SEXP pSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< connection_ptr const& >::type p(pSEXP);
    __result = Rcpp::wrap(connection_quote(p));
    return __result;
END_RCPP
}
// connection_special
std::string connection_special(connection_ptr const& p);
RcppExport SEXP odbconnect_connection_special(SEXP pSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< connection_ptr const& >::type p(pSEXP);
    __result = Rcpp::wrap(connection_special(p));
    return __result;
END_RCPP
}
// connection_release
void connection_release(connection_ptr p);
RcppExport SEXP odbconnect_connection_release(SEXP pSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< connection_ptr >::type p(pSEXP);
    connection_release(p);
    return R_NilValue;
END_RCPP
}
// connection_begin
void connection_begin(connection_ptr const& p);
RcppExport SEXP odbconnect_connection_begin(SEXP pSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< connection_ptr const& >::type p(pSEXP);
    connection_begin(p);
    return R_NilValue;
END_RCPP
}
// connection_commit
void connection_commit(connection_ptr const& p);
RcppExport SEXP odbconnect_connection_commit(SEXP pSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< connection_ptr const& >::type p(pSEXP);
    connection_commit(p);
    return R_NilValue;
END_RCPP
}
// connection_rollback
void connection_rollback(connection_ptr const& p);
RcppExport SEXP odbconnect_connection_rollback(SEXP pSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< connection_ptr const& >::type p(pSEXP);
    connection_rollback(p);
    return R_NilValue;
END_RCPP
}
// connection_valid
bool connection_valid(connection_ptr const& p);
RcppExport SEXP odbconnect_connection_valid(SEXP pSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< connection_ptr const& >::type p(pSEXP);
    __result = Rcpp::wrap(connection_valid(p));
    return __result;
END_RCPP
}
// connection_sql_tables
std::vector<std::string> connection_sql_tables(connection_ptr const& p, std::string const& catalog_name, std::string const& schema_name, std::string const& table_name, std::string const& table_type);
RcppExport SEXP odbconnect_connection_sql_tables(SEXP pSEXP, SEXP catalog_nameSEXP, SEXP schema_nameSEXP, SEXP table_nameSEXP, SEXP table_typeSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< connection_ptr const& >::type p(pSEXP);
    Rcpp::traits::input_parameter< std::string const& >::type catalog_name(catalog_nameSEXP);
    Rcpp::traits::input_parameter< std::string const& >::type schema_name(schema_nameSEXP);
    Rcpp::traits::input_parameter< std::string const& >::type table_name(table_nameSEXP);
    Rcpp::traits::input_parameter< std::string const& >::type table_type(table_typeSEXP);
    __result = Rcpp::wrap(connection_sql_tables(p, catalog_name, schema_name, table_name, table_type));
    return __result;
END_RCPP
}
// connection_sql_columns
Rcpp::DataFrame connection_sql_columns(connection_ptr const& p, std::string const& column_name, std::string const& catalog_name, std::string const& schema_name, std::string const& table_name);
RcppExport SEXP odbconnect_connection_sql_columns(SEXP pSEXP, SEXP column_nameSEXP, SEXP catalog_nameSEXP, SEXP schema_nameSEXP, SEXP table_nameSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< connection_ptr const& >::type p(pSEXP);
    Rcpp::traits::input_parameter< std::string const& >::type column_name(column_nameSEXP);
    Rcpp::traits::input_parameter< std::string const& >::type catalog_name(catalog_nameSEXP);
    Rcpp::traits::input_parameter< std::string const& >::type schema_name(schema_nameSEXP);
    Rcpp::traits::input_parameter< std::string const& >::type table_name(table_nameSEXP);
    __result = Rcpp::wrap(connection_sql_columns(p, column_name, catalog_name, schema_name, table_name));
    return __result;
END_RCPP
}
// result_release
void result_release(result_ptr r);
RcppExport SEXP odbconnect_result_release(SEXP rSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< result_ptr >::type r(rSEXP);
    result_release(r);
    return R_NilValue;
END_RCPP
}
// result_active
bool result_active(result_ptr const& r);
RcppExport SEXP odbconnect_result_active(SEXP rSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< result_ptr const& >::type r(rSEXP);
    __result = Rcpp::wrap(result_active(r));
    return __result;
END_RCPP
}
// result_completed
bool result_completed(result_ptr const& r);
RcppExport SEXP odbconnect_result_completed(SEXP rSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< result_ptr const& >::type r(rSEXP);
    __result = Rcpp::wrap(result_completed(r));
    return __result;
END_RCPP
}
// new_result
result_ptr new_result(connection_ptr const& p, std::string const& sql);
RcppExport SEXP odbconnect_new_result(SEXP pSEXP, SEXP sqlSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< connection_ptr const& >::type p(pSEXP);
    Rcpp::traits::input_parameter< std::string const& >::type sql(sqlSEXP);
    __result = Rcpp::wrap(new_result(p, sql));
    return __result;
END_RCPP
}
// result_fetch
List result_fetch(result_ptr const& r, const int n_max);
RcppExport SEXP odbconnect_result_fetch(SEXP rSEXP, SEXP n_maxSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< result_ptr const& >::type r(rSEXP);
    Rcpp::traits::input_parameter< const int >::type n_max(n_maxSEXP);
    __result = Rcpp::wrap(result_fetch(r, n_max));
    return __result;
END_RCPP
}
// result_column_info
Rcpp::DataFrame result_column_info(result_ptr const& r);
RcppExport SEXP odbconnect_result_column_info(SEXP rSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< result_ptr const& >::type r(rSEXP);
    __result = Rcpp::wrap(result_column_info(r));
    return __result;
END_RCPP
}
// result_bind
void result_bind(result_ptr const& r, List const& params);
RcppExport SEXP odbconnect_result_bind(SEXP rSEXP, SEXP paramsSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< result_ptr const& >::type r(rSEXP);
    Rcpp::traits::input_parameter< List const& >::type params(paramsSEXP);
    result_bind(r, params);
    return R_NilValue;
END_RCPP
}
// result_execute
void result_execute(result_ptr const& r);
RcppExport SEXP odbconnect_result_execute(SEXP rSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< result_ptr const& >::type r(rSEXP);
    result_execute(r);
    return R_NilValue;
END_RCPP
}
// result_insert_dataframe
void result_insert_dataframe(result_ptr const& r, DataFrame const& df);
RcppExport SEXP odbconnect_result_insert_dataframe(SEXP rSEXP, SEXP dfSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< result_ptr const& >::type r(rSEXP);
    Rcpp::traits::input_parameter< DataFrame const& >::type df(dfSEXP);
    result_insert_dataframe(r, df);
    return R_NilValue;
END_RCPP
}
// result_rows_affected
int result_rows_affected(result_ptr const& r);
RcppExport SEXP odbconnect_result_rows_affected(SEXP rSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< result_ptr const& >::type r(rSEXP);
    __result = Rcpp::wrap(result_rows_affected(r));
    return __result;
END_RCPP
}
// result_row_count
int result_row_count(result_ptr const& r);
RcppExport SEXP odbconnect_result_row_count(SEXP rSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< result_ptr const& >::type r(rSEXP);
    __result = Rcpp::wrap(result_row_count(r));
    return __result;
END_RCPP
}
// column_types
void column_types(DataFrame const& df);
RcppExport SEXP odbconnect_column_types(SEXP dfSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< DataFrame const& >::type df(dfSEXP);
    column_types(df);
    return R_NilValue;
END_RCPP
}
