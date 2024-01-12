#include <iostream>
#include <memory>
#include <FlexLexer.h>

// here we can return non-zero if lexing is not done inspite of EOF detected
int yyFlexLexer::yywrap() { return 1; }

int main() {
  auto lexer = std::make_unique<FlexLexer>();
  while (lexer->yylex() != 0) {
    // do nothing for now, all is in rules
  }
}