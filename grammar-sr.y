
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
  LBRAC   "("
  RBRAC   ")"
  SCOLON  ";"
  ERR
;

%token <int> NUMBER
%nterm <std::shared_ptr<iNode>> expressions expr term factor

%left '+' '-' 
%left '*' '/' 
%left UMINUS

%start lines

%%

lines: lines expressions '\n' 
     | expressions '\n' 
;

expressions: expr SCOLON  { 
    #ifdef DEBUG_GRAMMAR
      dumpTree($1, 0);  
    #else
      std::cout << eval($1) << std::endl;
    #endif
  }
;

expr:      expr PLUS term           { $$ = newOp(op_t::PLUS, $1, $3);}
        |  expr MINUS term          { $$ = newOp(op_t::MINUS, $1, $3);}  
        |  term                   
;

term : term MULT factor             { $$ = newOp(op_t::MULT, $1, $3);}   
     | term DIV factor              { $$ = newOp(op_t::DIV, $1, $3);}   
     | factor
     ;
 
factor :  NUMBER                    { $$ = newNumber($1); }
        | LBRAC expr RBRAC          { $$ = $2; }
        | MINUS NUMBER %prec UMINUS { $$ = newNumber(-$2); }

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