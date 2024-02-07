%language "c++"

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
    #include "ParaCLdriver.hpp"

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
%left EQUAL NOT_EQUAL
%left LESS LESS_EQUAL GREATER GREATER_EQUAL 
%left PLUS MINUS
%left MULTIPLY DIVIDE

%start program

%%

program: stmt_list { std::cout << "Parsing complete!" << std::endl; }
;

stmt_list: stmt | stmt_list stmt
;

stmt_1: '{' stmt_list '}' { $$ = $2; }
        | expr SCOLON { $$ = $1; }
        | IF '(' expr ')' stmt_1 ELSE stmt_1
        {
            if ($3) 
            {
                std::cout << "if " << $3 << std::endl;
                $$ = $5;
            }
            else 
            {
                $$ = $7;
            }
            std::cout << "If-else stmt" << std::endl;
        }
        | WHILE '(' expr ')' stmt_1 
        {
            while ($3)
            {
                $$ = $5;
            }
            std::cout << "While stmt-1" << std::endl;
        }
        | assign_stmt
;

stmt_2: IF '(' expr ')' stmt
        {
            if ($3) { $$ = $5; };
            std::cout << "If-stmt" << std::endl;
        }

        | IF '(' expr ')' stmt_1 ELSE stmt_2
        {
            if ($3) { $$ = $5; } else { $$ = $7; };
            std::cout << "If-else stmt" << std::endl;
        }

        | WHILE '(' expr ')' stmt_2 
        {
            while ($3) { $$ = $5; };
            std::cout << "While-stmt" << std::endl;
        }
;

stmt: stmt_1 | stmt_2
;

assign_stmt: ID ASSIGN expr SCOLON {
    $$ = $3;
    std::cout << $3 << " assigned for " << $1 << std::endl;
    std::cout << "Result: " << $$ << std::endl;
}
;

expr: expr AND bool_expr {
    $$ = ($1 && $3);
    std::cout << "Checking: " << $1 << " vs " << $3 << "; Result: " << $$ << std::endl;
}

| expr OR bool_expr {
    $$ = ($1 || $3);
    std::cout << "Checking: " << $1 << " vs " << $3 << "; Result: " << $$ << std::endl;
}

| bool_expr
;

bool_expr: bool_expr GREATEREQ arith_expr {
    $$ = ($1 >= $3);
    std::cout << "Checking: " << $1 << " vs " << $3 << "; Result: " << $$ << std::endl;
}

| bool_expr LESSEQ arith_expr {
    $$ = ($1 <= $3);
    std::cout << "Checking: " << $1 << " vs " << $3 << "; Result: " << $$ << std::endl;
}

| bool_expr LESS arith_expr  {
    $$ = ($1 < $3);
    std::cout << "Checking: " << $1 << " vs " << $3 << "; Result: " << $$ << std::endl;
}

| bool_expr GREATER arith_expr  {
    $$ = ($1 > $3);
    std::cout << "Checking: " << $1 << " vs " << $3 << "; Result: " << $$ << std::endl;
}

| bool_expr EQUAL arith_expr  {
    $$ = ($1 == $3);
    std::cout << "Checking: " << $1 << " vs " << $3 << "; Result: " << $$ << std::endl;
}

| bool_expr NONEQUAL arith_expr  {
    $$ = ($1 > $3);
    std::cout << "Checking: " << $1 << " vs " << $3 << "; Result: " << $$ << std::endl;
}

| arith_expr { $$ = $1; }
;

arith_expr: arith_expr PLUS term { $$ = $1 + $3; }

| arith_expr MINUS term { $$ = $1 - $3; }

| term  { $$ = $1; }

;

term: term MULTIPLY primary_expr { $$ = $1 * $3; }

| term DIVIDE primary_expr { $$ = $1 / $3; }
    
| primary_expr { $$ = $1; }
;

primary_expr: MINUS primary_expr { $$ = -$2; }

| QUESTION_MARK {
    std::cout << "Enter a value: ";
    std::cin >> $$;
}
       
| LPAREN expr RPAREN { $$ = $2; }

       
| NUM { 
    $$ = $1;
}

| ID {
    $$ = $1;
}

| PRINT primary_expr { 
    $$ = $2;
    std::cout << $2 << std::endl;
}
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