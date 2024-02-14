%option c++
%option yylineno
size_t line = lineno();
%option noyywrap nounput noinput batch debug

%option yyclass="yy::Lexer"

%{

#include "grammar.tab.hh"
#include "../include/lexer.hpp"

#define YY_USER_ACTION update_location();
%}

WS      [ \t\n\v]+
DIGIT   [0-9]
DIGIT1  [1-9]
ID      [a-zA-Z][a-zA-Z0-9]*

/* The rules are tried in the order of their appearance: from the first to the last */

%%

{WS}                /* skip blanks and tabs */

"if"                return yy::parser::token_type::IF;
"else"              return yy::parser::token_type::ELSE;
"while"             return yy::parser::token_type::WHILE;

"print"             return yy::parser::token_type::OUTPUT;
"?"                 return yy::parser::token_type::INPUT;

"("                 return yy::parser::token_type::LRB; /* left  round bracket */
")"                 return yy::parser::token_type::RRB; /* right round bracket */
"{"                 return yy::parser::token_type::LCB; /* left  curly bracket */
"}"                 return yy::parser::token_type::RCB; /* right curly bracket */
";"                 return yy::parser::token_type::SCOLON;

"<"                 return yy::parser::token_type::LESS;
"<="                return yy::parser::token_type::LESS_EQUAL;
">"                 return yy::parser::token_type::GREATER;
">="                return yy::parser::token_type::GREATER_EQUAL;
"=="                return yy::parser::token_type::EQUAL;
"!="                return yy::parser::token_type::NOT_EQUAL;

"&&"                return yy::parser::token_type::AND;
"||"                return yy::parser::token_type::OR;
"!"                 return yy::parser::token_type::NOT;

"="                 return yy::parser::token_type::ASSIGN;

"+"                 return yy::parser::token_type::PLUS;
"-"                 return yy::parser::token_type::MINUS;

"*"                 return yy::parser::token_type::MUL;
"/"                 return yy::parser::token_type::DIV;

{DIGIT1}{DIGIT}*    return yy::parser::token_type::INTEGER;
{DIGIT}             return yy::parser::token_type::INTEGER;
{ID}                return yy::parser::token_type::ID;
.                   return yy::parser::token_type::ERR; /* any character (byte) except newline */

%%