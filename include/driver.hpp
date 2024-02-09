#pragma once
#include <memory>
#include <FlexLexer.h>
#include "grammar.tab.hh"



namespace yy {

class Driver {

    FlexLexer* plex_;


public:
    nodes::Scope_node* cur_scope_;

    Driver(FlexLexer* plex): plex_(plex), cur_scope_{new nodes::Scope_node(nullptr)} {}

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

    Var* lookup(const std::string& name)
    {
        return (cur_scope_->lookup(name));
    }

    void emplace(const std::string& name, Var* var)
    {
        cur_scope_->emplace(name, var);
    }

    void add_branch(nodes::Base_node* scope)
    {
        if(scope != nullptr)
            cur_scope_->add_branch(scope);
    }

    int process() const 
    {
        return cur_scope_->process_node();
    }
};

} 