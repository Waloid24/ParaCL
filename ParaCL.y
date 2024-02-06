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

%token <int> TYPE_NUM
%token <int> TYPE_ID
%nterm <int> assign
%nterm <int> expression
%nterm <int> arithmetic
%nterm <int> cycle_statement
%nterm <int> if_condition
%nterm <int> while_condition
%nterm <int> body
%nterm <int> if_statement
%nterm <int> boolean
%nterm <int> term
%nterm <int> primary
%nterm <int> statement
%nterm <int> statement_list

%left AND OR
%left EQUAL NOT_EQUAL
%left LESS LESS_EQUAL GREATER GREATER_EQUAL 
%left PLUS MINUS
%left MULTIPLY DIVIDE

%start program

%%

program: statement_list { std::cout << "Parsing complete!" << std::endl; }
;

statement_list: statement | statement_list statement
;

statement: assign | if_statement | cycle_statement | expression SCOLON
;

assign: TYPE_ID ASSIGN expression SCOLON {
    std::cout << $3 << " assigned for " << $1 << std::endl;
    $$ = $3;
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
;

cycle_statement: while_condition body {
    while ($1) {
        std::cout << "Выполняю тело цикла " << std::endl;
        $$ = $2;
    }
}  
;

if_statement: if_condition body ELSE body  { 
    if($1) {
        $$ = $2;
    }
    else $$ = $4;
} 
;

if_condition: IF LPAREN expression RPAREN { $$ = $3; }
;

while_condition: WHILE LPAREN expression RPAREN  { $$ = $3; }
;

body: LBRACE statement_list RBRACE  { $$ = $2; }
| statement { $$ = $1; }
;

boolean: boolean GREATEREQ arithmetic {
    $$ = ($1 >= $3);
    std::cout << "Checking: " << $1 << " vs " << $3 << "; Result: " << $$ << std::endl;
}

| boolean LESSEQ arithmetic {
    $$ = ($1 <= $3);
    std::cout << "Checking: " << $1 << " vs " << $3 << "; Result: " << $$ << std::endl;
}

| boolean LESS arithmetic  {
    $$ = ($1 < $3);
    std::cout << "Checking: " << $1 << " vs " << $3 << "; Result: " << $$ << std::endl;
}

| boolean GREATER arithmetic  {
    $$ = ($1 > $3);
    std::cout << "Checking: " << $1 << " vs " << $3 << "; Result: " << $$ << std::endl;
}

| arithmetic { $$ = $1; }
;

arithmetic: arithmetic PLUS term { $$ = $1 + $3; }

| arithmetic MINUS term { $$ = $1 - $3; }

| term  { $$ = $1; }

;

term: term MULTIPLY primary { $$ = $1 * $3; }

| term DIVIDE primary { $$ = $1 / $3; }
    
| primary { $$ = $1; }
;

primary: MINUS primary { $$ = -$2; }
       
| LPAREN expression RPAREN { $$ = $2; }

       
| TYPE_NUM { 
    $$ = $1;
    std::cout << "Встретили число со значением " << $1 << "\n----------------------------\n" << std::endl; 
}

| TYPE_ID {
    $$ = $1;
    std::cout << "Встретили переменную со значением: " << $1 << std::endl;
}


| PRINT "(" expression ")" {
    $$ = $3;
    std::cout << $3 << std::endl;
}
| QUESTION_MARK "(" TYPE_ID ")" {
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