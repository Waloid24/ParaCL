%language "c++"

%skeleton "lalr1.cc"
%defines
%define api.value.type variant
%param { yy::Driver* driver }

%code requires
{
    #include <iostream>
    #include <string>

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

%right OR
%right AND
%left GREATER GREATEREQ LESS LESSEQ
%right MINUS

%token
    ASSIGN      "="
    MINUS       "-"
    PLUS        "+"
    SCOLON      ";"
    MULTIPLY    "*" 
    DIVIDE      "/"
    LPAREN      "("
    RPAREN      ")"
    LBRACE      "{"
    RBRACE      "}"
    LESS        "<"
    GREATER     ">"
    GREATEREQ   ">="
    LESSEQ      "<="
    NOTEQUAL    "!="
    EQUAL       "=="
    AND         "&&"
    OR          "||"
    INPUT       "?"

    IF          "if"
    WHILE       "while"
    ELSE        "else"
    PRINT       "print"

    ERR
;

%token <int> TYPE_NUM
%token <int> TYPE_ID
%nterm <int> assign
%nterm <int> expression
%nterm <int> arithmetic
%nterm <int> cycle
%nterm <int> conditional
%nterm <int> boolean
%nterm <int> term
%nterm <int> primary
%nterm <int> statement
%nterm <int> statement_list
%nterm <int> else_maybe

%start program

%%

program: statement_list { std::cout << "Parsing complete!" << std::endl; }
;

statement_list: statement | statement_list statement
;

statement: assign | conditional | cycle | expression SCOLON
;

assign: TYPE_ID ASSIGN expression SCOLON {  
    if ($3 == -1) {
        std::cout << "Enter a value: " << std::endl;
        std::cin >> $3;
    }

    $$ = $3;
    std::cout << $3 << " assigned for " << $1 << std::endl;
    std::cout << "Result: " << $$ << std::endl;
}
;

expression: expression AND boolean {
    $$ = ($1 && $3);
    std::cout << "Checking: " << $1 << " vs " << $3 << "; Result: " << $$ << std::endl;
}

| expression OR boolean {
    $$ = ($1 || $3);
    std::cout << "Checking: " << $1 << " vs " << $3 << "; Result: " << $$ << std::endl;
}

| boolean

| INPUT { $$ = -1; }
;

cycle: WHILE LPAREN expression RPAREN LBRACE statement_list RBRACE {
    std::cout << "Цикл" <<std::endl;
    std::cout << "Условие равно: " << $3 << std::endl;
    if ($3 != 0) {
        std::cout << "Выполняю тело цикла " << std::endl;
        $6;
    }
}
;


conditional: IF LPAREN expression RPAREN LBRACE statement_list RBRACE else_maybe
;

else_maybe: ELSE LBRACE statement_list RBRACE { $$ = $3; }
    | %empty { $$ = 0; }
;

boolean: boolean GREATEREQ arithmetic {
    $$ = ($1 >= $3);
    std::cout << "Checking: " << $1 << " vs " << $3 << "; Result: " << $$ << std::endl;
}

| boolean LESSEQ arithmetic {
    $$ = ($1 <= $3);
    std::cout << "Checking: " << $1 << " vs " << $3 << "; Result: " << $$ << std::endl;
}

| boolean LESS arithmetic {
    $$ = ($1 < $3);
    std::cout << "Checking: " << $1 << " vs " << $3 << "; Result: " << $$ << std::endl;
}

| boolean GREATER arithmetic {
    $$ = ($1 > $3);
    std::cout << "Checking: " << $1 << " vs " << $3 << "; Result: " << $$ << std::endl;
}

| arithmetic { $$ = $1; }
;

arithmetic: arithmetic PLUS term { $$ = $1 + $3; }

| arithmetic MINUS term { $$ = $1 - $3; }

| term

| %empty { $$ = 0; }
;

term: term MULTIPLY primary { $$ = $1 * $3; }

| term DIVIDE primary { $$ = $1 / $3; }
    
| primary
;

primary: MINUS primary { $$ = -$2; }
       
| LPAREN expression RPAREN { $$ = $2; }
       
| TYPE_NUM { 
    $$ = $1;
    std::cout << "Встретили число со значением " << $1 << std::endl; 
}

| TYPE_ID {
    $$ = $1;
    std::cout << "Встретили переменную со значением: " << $1 << std::endl;
}
 

%%

namespace yy {
    parser::token_type yylex(parser::semantic_type* yyval,
                             Driver* driver)
    {
        return driver->yylex(yyval);
    }
    void parser::error(const std::string&) {}
}