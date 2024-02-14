#ifndef LEXER_HPP
#define LEXER_HPP

#ifndef yyFlexLexer
#include <FlexLexer.h>
#endif

#include "grammar.tab.hh"

namespace yy {

class Lexer : public yyFlexLexer {

    yy::parser::location_type cur_loc_;
    std::size_t cur_line_;

    public:
        Lexer() : cur_loc_{0}, cur_line_{1} {}
        virtual ~Lexer() = default;

        yy::parser::location_type get_current_location();
        std::size_t get_current_line();
        void update_location();
        int yylex() override;
};

}



#endif