
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

std::shared_ptr<iNode> head;
}

%token
  EQUAL   "="
  MINUS   "-"
  PLUS    "+"
  SCOLON  ";"
  ERR
;

%token <int> NUMBER
%nterm <int> expr

%left '+' '-'

%%

program: statement_list 

statement_list: statement
              | statement_list statement

statement: expr SCOLON
      {
        std::cout << eval(head) << std::endl;     
      }
;

state: expr SCOLON state

expr: expr PLUS expr          { 
                                head = newOp(op_t::PLUS, newNumber($1), newNumber($3));
                              }
    | expr MINUS expr         { 
                                head = newOp(op_t::MINUS, newNumber($1), newNumber($3));
                              }
    | NUMBER                  { $$ = $1;}
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