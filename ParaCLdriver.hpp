#pragma once

#include "ParaCL.tab.hh"
#include <FlexLexer.h>

namespace yy {

class Driver {
  FlexLexer *plex_;

public:
  Driver(FlexLexer *plex) : plex_(plex) {}

  parser::token_type yylex(parser::semantic_type *yylval) {
    parser::token_type tt = static_cast<parser::token_type>(plex_->yylex());
    if (tt == yy::parser::token_type::TYPE_NUM)
      yylval->as<int>() = std::stoi(plex_->YYText());
    return tt;
  }

  bool parse() {
    parser parser(this);
    bool res = parser.parse();
    return !res;
  }
};

} // namespace yy