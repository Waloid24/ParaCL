
%language "c++"

%skeleton "lalr1.cc"
%defines
%define api.value.type variant
%param {yy::NumDriver* driver}

%code requires
{
#include <iostream>
#include <string>
#include <ast.hpp>

namespace yy { class NumDriver; }


}

%code
{
#include "driver.hpp"

namespace yy {

parser::token_type yylex(parser::semantic_type* yylval,                         
                         NumDriver* driver);
}

}

%token
  EQUAL   "="
  PLUS    "+"
  MINUS   "-"
  MULT    "*"
  DIV     "/"
  SCOLON  ";"
  ERR
;

%token <int> NUMBER
%nterm <std::shared_ptr<iNode>> expressions expr term factor

%left '+' '-' 
%left '*' '/' 

%start expressions

%%

expressions: expr { 
    #ifdef DEBUG_GRAMMAR
      dumpTree($1, 0);  
    #else
      std::cout << eval($1) << std::endl;
    #endif
  }
;


/*
statement_list: statement
              | statement_list statement
*/

/*
statement: expr SCOLON
      {
        std::cout << dumpTree($1, 0) << std::endl;   
      }
;
*/

expr:      expr PLUS term        { $$ = newOp(op_t::PLUS, $1, $3);}
        |  expr MINUS term       { $$ = newOp(op_t::MINUS, $1, $3);}        
        |  term                  { $$ = $1;}   
;

term : term MULT factor { $$ = newOp(op_t::MULT, $1, $3);}   
     | term DIV factor { $$ = newOp(op_t::DIV, $1, $3);}   
     | factor
     ;
 
factor : NUMBER { $$ = newNumber($1); }
;

%%

namespace yy {

parser::token_type yylex(parser::semantic_type* yylval,                         
                         NumDriver* driver)
{
  return driver->yylex(yylval);
}

void parser::error(const std::string&){}
}