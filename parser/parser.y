%language "c++"
%skeleton "lalr1.cc"

%defines
%define api.value.type variant
%param {yy::Driver* driver}

%code requires
{
    #include <iostream>
    #include <string>

    // forward decl of argument to parser
    namespace yy { class Driver; }
}

%code
{
    #include "parser/driver.hpp"

    namespace yy {

        parser::token_type yylex(parser::semantic_type* yylval, Driver* driver);
    
    }

}

%token
    IF              "if"
    ELSE            "else"
    WHILE           "while"

    OUTPUT          "print"
    INPUT           "?"

    LRB             "("
    RRB             ")"
    LCB             "{"
    RCB             "}"
    SCOLON          ";"

    LESS            "<"
    LESS_EQUAL      "<="
    GREATER         ">"
    GREATER_EQUAL   ">="
    EQUAL           "=="
    NOT_EQUAL       "!="

    AND             "&&"
    OR              "||"
    
    ASSIGN          "="

    MINUS           "-"
    PLUS            "+"

    MUL             "*"
    DIV             "/"
    
    ERR
;

%token <int> INTEGER
%token <std::string> ID

/*
%nterm <int> program
%nterm <int> stms
%nterm <int> scope
%nterm <int> statement
%nterm <int> simple_statement
%nterm <int> assign
%nterm <int> lval
%nterm <int> expression
%nterm <int> boolean
%nterm <int> arithmetic
%nterm <int> term
%nterm <int> primary
*/

/* Priority * and / is higher than + and - */
%left AND OR
%left EQUAL NOT_EQUAL
%left LESS LESS_EQUAL GREATER GREATER_EQUAL 
%left PLUS MINUS
%left MUL DIV

/* the start symbol for the grammar is 'statement', isn't the
 * first nonterminal specified in the grammar specification section. */
%start program

%%

program: stms
;

stms:     statement
        | stms scope
        | stms statement
;

scope: "{" stms "}"
;

statement:    open_statement
            | closed_statement
;

open_statement:   IF "(" expression ")" simple_statement
                | IF "(" expression ")" open_statement
                | IF "(" expression ")" closed_statement ELSE open_statement
                | WHILE "(" expression ")" open_statement
;

closed_statement:     simple_statement
                    | IF "(" expression ")" closed_statement ELSE closed_statement
                    | WHILE "(" expression ")" closed_statement
;

simple_statement:     assign
                    | expression ";"
;

assign: lval ASSIGN expression SCOLON 
;

lval: ID
;

expression:   expression "&&" boolean
            | expression "||" boolean
            | boolean
;

boolean:      boolean "==" arithmetic
            | boolean "!=" arithmetic
            | boolean ">" arithmetic
            | boolean ">=" arithmetic
            | boolean "<" arithmetic
            | boolean "<=" arithmetic 
            | arithmetic
;

arithmetic:   arithmetic "+" term
            | arithmetic "-" term
            | term
;

term:         term "*" primary
            | term "/" primary
            | primary 
;

primary:      "-" primary
            | "(" expression ")"
            | INTEGER
            | ID
            | OUTPUT "(" expression ")"
            | INPUT "(" expression ")"
;

%%

namespace yy {

parser::token_type yylex(parser::semantic_type* yylval,                         
                         Driver* driver)
{
  return driver->yylex(yylval);
}

void parser::error(const std::string&){}
}