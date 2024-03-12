
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
// forward decl of a<trgument to parser
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

state: expr SCOLON state
      {
        std::cout << ";" << std::endl;
        head->dump();
      }
;

expr: expr PLUS expr          { 
                                node* head = new node(nodeType::op);
                                head->left_ = new node(nodeType::number);
                                head->right_ = new node(nodeType::number);
                                head->dump();
                              }
    | expr MINUS expr         { 
                                node* head = new node(nodeType::op);
                                head->left_ = new node(nodeType::number);
                                head->right_ = new node(nodeType::number);
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