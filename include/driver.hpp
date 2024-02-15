#pragma once
#include <memory>
#include <fstream>
#include <string>
#include <FlexLexer.h>

#include "lexer.hpp"
#include "node.hpp"
#include "grammar.tab.hh"

#include <memory>

namespace yy {

class Driver {

    const char* file_name_;
    Lexer* plex_;
    std::ifstream input_file_;

public:
    nodes::Scope_node* cur_scope_;

    Driver(const char* file_name)
    : file_name_{file_name}
    , plex_{new Lexer}
    , cur_scope_{new nodes::Scope_node(nullptr)}
    {
        input_file_.open(file_name_);
        plex_->switch_streams(input_file_, std::cout);
    }
    ~Driver();

    //receiving and processing a token
    parser::token_type yylex(parser::semantic_type* yylval, parser::location_type* yyloc);
    //parsing
    bool parse();
    //searching for a name in character tables
    Var* lookup(const std::string& name) { return (cur_scope_->lookup(name)); }
    //inserting a name into a character table
    void emplace(const std::string& name, Var* var) { cur_scope_->emplace(name, var); }
    //add new branch
    void add_branch(nodes::Base_node* scope);
    //starting node processing in AST
    int process() const;
    //redefining the standard error handling function
    void report_syntax_error(parser::context const& ctx) const;
    //handling errors regarding an undefined name
    void report_name_error(yy::parser::location_type &loc, std::string &name) const;
};

enum class color_type {
    RED,
    GREEN,
    DEFAULT
};

enum class mod_type {
    BOLD,
    ITALIC,
    DEFAULT
};

class Ascii_console {
    static const char* get_color(color_type color);
    static const char* get_mod(mod_type mod);
    public:
        static const char* red();
        static const char* green();
        static const char* bold();
        static const char* italic();
        static const char* def();
};

} 