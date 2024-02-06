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
    struct VariableStore {
        std::unordered_map<std::string, int> variables;
    };
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
    NOTEQUAL        "!="
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
%nterm <int> while_stmt
%nterm <int> if_stmt
%nterm <int> if_cond
%nterm <int> while_cond
%nterm <int> block
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

stmt: assign_stmt | if_stmt | while_stmt | expr SCOLON
;

assign_stmt: ID ASSIGN expr SCOLON {
    std::cout << $3 << " assigned for " << $1 << std::endl;
    $$ = $3;
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

while_stmt: while_cond block {
    while ($1) {
        std::cout << "Выполняю тело цикла " << std::endl;
        $$ = $2;
    }
}  
;

if_stmt: if_cond block ELSE block  { 
    if($1) {
        $$ = $2;
    }
    else $$ = $4;
} 
;

if_cond: IF LPAREN expr RPAREN { $$ = $3; }
;

while_cond: WHILE LPAREN expr RPAREN  { $$ = $3; }
;

block: LBRACE stmt_list RBRACE  { $$ = $2; }
| stmt { $$ = $1; }
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
       
| LPAREN expr RPAREN { $$ = $2; }

       
| NUM { 
    $$ = $1;
    std::cout << "Встретили число со значением " << $1 << "\n----------------------------\n" << std::endl; 
}

| ID {
    $$ = $1;
    std::cout << "Встретили переменную со значением: " << $1 << std::endl;
}


| PRINT LPAREN expr RPAREN {
    $$ = $3;
    std::cout << $3 << std::endl;
}
| QUESTION_MARK LPAREN ID RPAREN {
    std::cout << "Введите значение для переменной: ";
    std::cin >> $$;
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