#include "driver.hpp"

namespace yy {

Driver::~Driver()
{
    input_file_.close();
    
    delete cur_scope_;
    delete plex_;
}

bool Driver::parse() 
{
    parser parser{this};
    bool res = parser.parse();
    return !res;
}

parser::token_type Driver::yylex(parser::semantic_type* yylval, parser::location_type* yyloc) 
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

    *yyloc = plex_->get_current_location();

    return tt;
}

void Driver::add_branch(nodes::Base_node* scope)
{
    if(scope != nullptr)
        cur_scope_->add_branch(scope);
}

int Driver::process() const 
{
    return cur_scope_->process_node();
}

void Driver::report_syntax_error(parser::context const& ctx) const
{
    size_t lineno = plex_->get_current_line();
    yy::parser::location_type location = ctx.location();
    size_t end_column = location.end.column;

    enum { TOKENMAX = 10 };
    yy::parser::symbol_kind_type expected[TOKENMAX];
    int num = ctx.expected_tokens (expected, TOKENMAX);

    std::cerr << Ascii_console::bold() <<  file_name_ << ":" << lineno << ":" << end_column << ":" << Ascii_console::red() << " error: " << Ascii_console::def() << "exprected \"" << yy::parser::symbol_name(expected[0]) << "\" \n";

    for (int i = 1; i < num; ++i)
    {
        std::cout << " or \"" << yy::parser::symbol_name(expected[i]) << "\" \n";
    }

    throw std::runtime_error("Compilation failed!");
}

void Driver::report_name_error(yy::parser::location_type &loc, std::string &name) const
{
    size_t lineno = plex_->get_current_line();
    size_t begin_column = loc.begin.column;

    std::cerr << Ascii_console::bold() << file_name_ << ":" << lineno << ":" << begin_column << ":" << Ascii_console::red() << " error: " << Ascii_console::def() << "\'" << Ascii_console::bold() << name << Ascii_console::def() << "\' was not declared in this scope" << std::endl;
    throw std::runtime_error("Undeclared variable!");
}

const char* Ascii_console::get_color(color_type mod)
{
    switch(mod)
    {
        case color_type::RED:
            return "\033[31m";
        case color_type::GREEN:
            return "\033[32m";
        default:
            return nullptr;
    }
}

const char* Ascii_console::get_mod(mod_type mod)
{
    switch(mod)
    {
        case mod_type::BOLD:
            return "\033[1m";
        case mod_type::ITALIC:
            return "\033[3m";
        default:
            return nullptr;
    }
}

const char* Ascii_console::red()
{
    return get_color(color_type::RED);
}

const char* Ascii_console::green()
{
    return get_color(color_type::GREEN);
}

const char* Ascii_console::bold()
{
    return get_mod(mod_type::BOLD);
}

const char* Ascii_console::italic()
{
    return get_mod(mod_type::BOLD);
}

const char* Ascii_console::def()
{
    return "\033[0m";
}
}
