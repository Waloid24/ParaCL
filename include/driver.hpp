#pragma once

#include "compiler.tab.hh"
#include "ScopeNode.hpp"

#include <FlexLexer.h>

namespace yy {

class Driver {
  FlexLexer *plex_;
  ScopeNode* currentScope;

public:
  Driver(FlexLexer *plex, ScopeNode* currentScope) : plex_(plex), currentScope(currentScope) {}

  parser::token_type yylex(parser::semantic_type *yylval) {
    parser::token_type tt = static_cast<parser::token_type>(plex_->yylex());
    if (tt == yy::parser::token_type::NUM)
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