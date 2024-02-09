#include <iostream>
#include <memory>
#include "../include/driver.hpp"

int yyFlexLexer::yywrap() { return 1; }

int main() {
  FlexLexer *lexer = new yyFlexLexer;
  yy::Driver driver(lexer);
  driver.parse();
  delete lexer;
}