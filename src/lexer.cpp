#include "lexer.hpp"

using namespace yy;

void Lexer::update_location()
{
    std::size_t line = lineno(); 
    cur_loc_.lines(line - cur_line_);
    cur_loc_.step();
    if (line - cur_line_ == 0)
        cur_loc_.columns(YYLeng());
    
    cur_line_ = line;
}

std::size_t Lexer::get_current_line()
{
    return cur_line_;
}

yy::parser::location_type Lexer::get_current_location()
{
    return cur_loc_;
}
