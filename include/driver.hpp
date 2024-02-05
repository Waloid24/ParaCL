#pragma once
#include <memory>
#include "grammar.tab.hh"
#include <FlexLexer.h>

namespace yy {

class Driver {

    FlexLexer* plex_;

public:
    Scope_node* cur_scope_;

    Driver(FlexLexer* plex): plex_(plex), cur_scope_{new Scope_node(nullptr)} {}

    parser::token_type yylex(parser::semantic_type* yylval) 
    {
        parser::token_type tt = static_cast<parser::token_type>(plex_->yylex());
        if (tt == yy::parser::token_type::INTEGER)
            yylval->as<int>() = std::stoi(plex_->YYText());
        return tt;
    }

    bool parse() 
    {
        parser parser(this);
        bool res = parser.parse();
        return !res;
    }

    void lookup(Variable var)
    {
        if (std::find(vars.begin(), vars.end(), var.name) != vars.end())
            return true;
        else
            return false;
    }

};

} 