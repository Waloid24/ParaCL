#pragma once

#include "compiler.tab.hh"
#include <FlexLexer.h>
#include "INode.hpp"
#include "ScopeTree.hpp"

namespace yy {

class Driver {
  FlexLexer *plex_;
  std::shared_ptr<ScopeNode>& currentScope;

public:
  Driver(FlexLexer *plex, std::shared_ptr<ScopeNode>& currentScope) : plex_(plex), currentScope(currentScope) {}

  parser::token_type yylex(parser::semantic_type *yylval) {
    parser::token_type tt = static_cast<parser::token_type>(plex_->yylex());
    if (tt == yy::parser::token_type::NUM)
      yylval->as<int>() = std::stoi(plex_->YYText());
    return tt;
  }

  bool parse() {
    parser parser(this);
    // std::cout << "in bool parse()" << std::endl;
    
    bool res = parser.parse();
    return !res;
  }

  // void create_scope() {
  //   if(currentScope != nullptr) {
  //     currentScope->create_scope(currentScope);
  //   }
  // }

  // void exit_scope() {
  //   if(currentScope != nullptr) {
  //     currentScope->exit_scope(currentScope);
  //   }
  // }

  // // Вызывает подсчет для всех типов узлов
  // void calculate() { 
  //   return currentScope->calculate();
  // }





};

} // namespace yy