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
    #include "Node.hpp"

    extern ScopeNode* currentScope;

    namespace yy { parser::token_type yylex(parser::semantic_type* yyval, Driver* driver); }
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
%nterm <int> open_sc
%nterm <int> close_sc
%nterm <int> scope


%left AND OR
%right ASSIGN
%left EQUAL NONEQUAL
%left LESS LESSEQ GREATER GREATEREQ 
%left PLUS MINUS
%left MULTIPLY DIVIDE

%start program

%%

program: stmt_list                          { currentScope->calculate(); } 
;

scope: open_sc stmt_list close_sc           { $$ = $2; }
;

open_sc: '{'                                { currentScope->create_scope(); }
;

close_sc: '}'                               { currentScope->exit_scope(); }
;

stmt_list: stmt                             { $$ = driver->create_scope($1); }
| stmt_list stmt                            { $$ = driver->create_scope($2); }
;

stmt_1: '{' stmt_list '}'                   { $$ = $2; }

| expr ';'                                  { $$ = $1; }

| IF '(' expr ')' stmt_1 ELSE stmt_1        { $$ = new IfNode($3, $5, $7); }

| WHILE '(' expr ')' stmt_1                 { $$ = new WhileNode($3, $5); }

| assign_stmt                               
;

stmt_2: IF '(' expr ')' stmt                { $$ = NodeFactory::make_if($3, $5, create_scope()); }

| IF '(' expr ')' stmt_1 ELSE stmt_2        { $$ = NodeFactory::make_if($3, $5, $7);}

| WHILE '(' expr ')' stmt_2                 { $$ = NodeFactory::make_while($3, $5); }
;

stmt: stmt_1 | stmt_2
;

assign_stmt: ID ASSIGN expr ';'                { $$ = NodeFactory::make_operator($1, Operations::Assign, $3); }
;

expr: expr AND bool_expr                    { $$ = NodeFactory::make_operator($1, Operations::And, $3); }

| expr OR bool_expr                         { $$ = NodeFactory::make_operator($1, Operations::Or, $3); }

| bool_expr                                 { $$ = $1; }
;

bool_expr: bool_expr GREATEREQ arith_expr        { $$ = NodeFactory::make_operator($1, Operations::GreaterEq, $3); }

| bool_expr LESSEQ arith_expr                 { $$ = NodeFactory::make_operator($1, Operations::LessEq, $3); }

| bool_expr LESS arith_expr                  { $$ = NodeFactory::make_operator($1, Operations::Less, $3); }

| bool_expr GREATER arith_expr                  { $$ = NodeFactory::make_operator($1, Operations::Greater, $3); }

| bool_expr EQUAL arith_expr                 { $$ = NodeFactory::make_operator($1, Operations::Equal, $3); }

| bool_expr NONEQUAL arith_expr                 { $$ = NodeFactory::make_operator($1, Operations::NonEqual, $3); }

| arith_expr                                { $$ = $1; }
;

arith_expr: arith_expr PLUS term            { $$ = NodeFactory::make_operator($1, Operations::Plus, $3); }

| arith_expr MINUS term                      { $$ = NodeFactory::make_operator($1, Operations::Minus, $3); }

| term                                     { $$ = $1; }

;

term: term MULTIPLY primary_expr                { $$ = NodeFactory::make_operator($1, Operations::Multiply, $3); }

| term DIVIDE primary_expr                    { $$ = NodeFactory::make_operator($1, Operations::Divide, $3); }
    
| primary_expr                             { $$ = $1; }
;

primary_expr: MINUS primary_expr             { $$ = NodeFactory::make_operator(0, Operations::UnaryMinus, $2); }

| QUESTION_MARK                            //{ $$ = new inputop("?"); }
       
| "{" expr "}"                             { $$ = $2; }

       
| NUM                                      { $$ = NodeFactory::make_value($1); }

| ID                                       //{ $$ = NodeFactory::make_var($1); }

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