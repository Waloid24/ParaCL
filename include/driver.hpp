#pragma once
#include <memory>
#include <FlexLexer.h>
#include <fstream>
#include "grammar.tab.hh"

namespace yy {

class Driver {

    const char* file_name_;
    FlexLexer* plex_;
    std::ifstream input_file_;

public:
    nodes::Scope_node* cur_scope_;

    Driver(const char* file_name)
    : file_name_{file_name}
    , plex_{new yyFlexLexer}
    , cur_scope_{new nodes::Scope_node(nullptr)}
    {
        input_file_.open(file_name_);
        plex_->switch_streams(input_file_, std::cout);
    }
    ~Driver()
    {
        input_file_.close();
        
        delete cur_scope_;
        delete plex_;
    }

    parser::token_type yylex(parser::semantic_type* yylval) 
    {
        parser::token_type tt = static_cast<parser::token_type>(plex_->yylex());

        if (tt == yy::parser::token_type::INTEGER)
            yylval->as<int>() = std::stoi(plex_->YYText());
        if (tt == yy::parser::token_type::ID)
        {
            std::string name(plex_->YYText());
            parser::semantic_type tmp;
            tmp.as<std::string>() = name;
            yylval->swap<std::string>(tmp);
        }
        return tt;
    }

    bool parse() 
    {
        parser parser{this};
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
        std::cout << "Into driver->process()!" << std::endl;
        return cur_scope_->process_node();
    }
};

} 