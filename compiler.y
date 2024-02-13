%language "c++"

%require "3.2"
%skeleton "lalr1.cc"
%defines
%define api.value.type variant
%param { yy::Driver* driver }

%code requires
{
    
    #include <iostream>
    #include <string>
    #include <unordered_map>

    namespace yy { class Driver; }
 
}

%code
{
    #include "driver.hpp"
    #include "INode.hpp"

    namespace yy {
        parser::token_type yylex(parser::semantic_type* yyval,
                                 Driver* driver);
    }
 
}

%token
    ASSIGN          "="
    MINUS           "-"
    PLUS            "+"
    SCOLON          ";"
    MULTIPLY        "*" 
    DIVIDE          "/"
    LPAREN          "("
    RPAREN          ")"
    LBRACE          "{"
    RBRACE          "}"
    LESS            "<"
    GREATER         ">"
    GREATEREQ       ">="
    LESSEQ          "<="
    NONEQUAL        "!="
    EQUAL           "=="
    AND             "&&"
    OR              "||"
    QUESTION_MARK   "?"

    IF              "if"
    WHILE           "while"
    ELSE            "else"
    PRINT           "print"
    ERR
;

%token <int> NUM
%token <int> ID

%nterm <int> stmt_list
%nterm <int> stmt
%nterm <int> assign_stmt
%nterm <int> expr
%nterm <int> stmt_1
%nterm <int> stmt_2
%nterm <int> bool_expr
%nterm <int> arith_expr
%nterm <int> term
%nterm <int> primary_expr

%left AND OR
%right ASSIGN
%left EQUAL NOT_EQUAL
%left LESS LESS_EQUAL GREATER GREATER_EQUAL 
%left PLUS MINUS
%left MULTIPLY DIVIDE

%start program

%%

program: stmt_list                          { current_scope->calculate(); } 
;

scope: open_sc stmt_list close_sc           { $$ = $3; }
;

open_sc: '{'                                { current_scope = create_scope(); }
;

clode_sc: '}'                               { current_scope = current_scope->}
;

stmt_list: stmt                             { }
| stmt_list stmt                            { $$ = new block($1, $2); }
;

stmt_1: '{' stmt_list '}'                 //  { $$ = $2; }

| expr ';'                                 // { $$ = new exprop($1); }

| IF '(' expr ')' stmt_1 ELSE stmt_1       // { $$ = new ifop($3, $5, $7); }

| WHILE '(' expr ')' stmt_1               //  { $$ = new whileop($3, $5); }

| assign_stmt                               
;

stmt_2: IF '(' expr ')' stmt               // { $$ = new ifop($3, $5, new block()); }

| IF '(' expr ')' stmt_1 ELSE stmt_2      //  { $$ = new ifop($3, $5, $7); }

| WHILE '(' expr ')' stmt_2              //   { $$ = new whileop($3, $5); }
;

stmt: stmt_1 | stmt_2
;

assign_stmt: ID '=' expr ';'            //    { $$ = new assignop($1, $3); }
;

expr: expr AND bool_expr                  //  { $$ = new logicalop("&&", $1, $3); }

| expr OR bool_expr                         //{ $$ = new logicalop("||", $1, $3); }

| bool_expr
;

bool_expr: bool_expr '>=' arith_expr       // { $$ = new comprop(">=", $1, $3); }

| bool_expr '<=' arith_expr                // { $$ = new comprop("<=", $1, $3); }

| bool_expr '<' arith_expr                  //{ $$ = new comprop("<", $1, $3); }

| bool_expr '>' arith_expr                //  { $$ = new comprop(">", $1, $3); }

| bool_expr '==' arith_expr              //   { $$ = new comprop("==", $1, $3); }

| bool_expr '!=' arith_expr                // { $$ = new comprop("!=", $1, $3); }

| arith_expr                               // { $$ = $1; }
;

arith_expr: arith_expr "+" term           // { $$ = new arithop("+", $1, $3); }

| arith_expr "-" term                     // { $$ = new arithop("-", $1, $3); }

| term                                    // { $$ = $1; }

;

term: term "*" primary_expr               // { $$ = new arithop("*", $1, $3); }

| term "/" primary_expr                   // { $$ = new arithop("/", $1, $3); }
    
| primary_expr                            // { $$ = $1; }
;

primary_expr: "-" primary_expr             //{ $$ = new unaryop("-", $2); }

| QUESTION_MARK                            //{ $$ = new inputop("?"); }
       
| "{" expr "}"                            // { $$ = $2; }

       
| NUM                                      //{ $$ = new number($1); }

| ID                                       //{ $$ = new value($1); }

| PRINT primary_expr                       //{ $$ = new outputop($2); }
;

;
%%



namespace yy {
    parser::token_type yylex(parser::semantic_type* yyval,
                             Driver* driver)
    {
        return driver->yylex(yyval);
    }
    void parser::error(const std::string&) {}
}