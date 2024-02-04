#include <memory>

#include <ParaCL_lexer.hpp>

int yyFlexLexer::yywrap() {return 1; }

int main() {
    auto lexer = std::make_unique<NumLexer>();
    while (lexer->yylex() != 0) {
        lexer->print_current();
    }
}