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
    #include "INode.hpp"
    #include <memory>
    
    namespace yy { class Driver; }
 
}

%code
{
    #include "driver.hpp"
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
%token <std::string> ID

%nterm <std::shared_ptr<INode>> stmt_list
%nterm <std::shared_ptr<INode>> stmt
%nterm <std::shared_ptr<INode>> assign_stmt
%nterm <std::shared_ptr<INode>> expr
%nterm <std::shared_ptr<INode>> stmt_1
%nterm <std::shared_ptr<INode>> stmt_2
%nterm <std::shared_ptr<INode>> bool_expr
%nterm <std::shared_ptr<INode>> arith_expr
%nterm <std::shared_ptr<INode>> term
%nterm <std::shared_ptr<INode>> primary_expr
%nterm <std::shared_ptr<INode>> open_sc
%nterm <std::shared_ptr<INode>> close_sc
%nterm <std::shared_ptr<INode>> scope


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

//scope: open_sc stmt_list close_sc           { $$ = $2; }
//;


stmt_list: stmt                             {  }
| stmt_list stmt                            {  }
;

stmt_1: '{' stmt_list '}'                   { currentScope->add_branch($2); }

| expr ';'                                  { $$ = $1; }

| IF '(' expr ')' stmt_1 ELSE stmt_1        { $$ = make_if($3, $5, $7); }

| WHILE '(' expr ')' stmt_1                 { $$ = make_while($3, $5); }

| assign_stmt                               
;

open_sc: '{'                                { currentScope = std::shared_ptr<IScope>(new IScope()); }
;

close_sc: '}'                               { currentScope->exit_scope(); }
;

stmt_2: IF '(' expr ')' stmt                { $$ = make_if($3, $5, 0); }

| IF '(' expr ')' stmt_1 ELSE stmt_2        { $$ = make_if($3, $5, $7);}

| WHILE '(' expr ')' stmt_2                 { $$ = make_while($3, $5); }
;

stmt: stmt_1 | stmt_2
;

assign_stmt: ID ASSIGN expr ';'             //{ $$ = make_operator($1, Operations::Assign, $3); }
;

expr: expr AND bool_expr                    { $$ = make_operator($1, Operations::And, $3); }

| expr OR bool_expr                         { $$ = make_operator($1, Operations::Or, $3); }

| bool_expr                                 { $$ = $1; }
;

bool_expr: bool_expr GREATEREQ arith_expr   { $$ = make_operator($1, Operations::GreaterEq, $3); }

| bool_expr LESSEQ arith_expr               { $$ = make_operator($1, Operations::LessEq, $3); }

| bool_expr LESS arith_expr                 { $$ = make_operator($1, Operations::Less, $3); }

| bool_expr GREATER arith_expr              { $$ = make_operator($1, Operations::Greater, $3); }

| bool_expr EQUAL arith_expr                { $$ = make_operator($1, Operations::Equal, $3); }

| bool_expr NONEQUAL arith_expr             { $$ = make_operator($1, Operations::NonEqual, $3); }

| arith_expr                                { $$ = $1; }
;

arith_expr: arith_expr PLUS term            { $$ = make_operator($1, Operations::Plus, $3); }

| arith_expr MINUS term                     { $$ = make_operator($1, Operations::Minus, $3); }

| term                                      { $$ = $1; }

;

term: term MULTIPLY primary_expr            { $$ = make_operator($1, Operations::Multiply, $3); }

| term DIVIDE primary_expr                  { $$ = make_operator($1, Operations::Divide, $3); }
    
| primary_expr                              { $$ = $1; }
;

primary_expr: MINUS primary_expr            { $$ = make_operator(0, Operations::UnaryMinus, $2); }

| QUESTION_MARK                            //{ $$ = new inputop("?"); }
       
| "{" expr "}"                              { $$ = $2; }

       
| NUM                                       { $$ = make_value($1); }

| ID                                        //{ $$ = make_var($1, ScopeNode* currentScope); }

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