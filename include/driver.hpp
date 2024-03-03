#pragma once

#include "../build/compiler.tab.hh"
#include "ScopeNode.hpp"
#include "Node.hpp"

#include <FlexLexer.h>

namespace yy {

class Driver {
  FlexLexer* plex_;
public:
  std::shared_ptr<ScopeNode> currentScope;
  std::shared_ptr<ScopeNode> globalScope;
  
  std::shared_ptr<GlobalAst> globalAstNode;
  std::shared_ptr<ASTNode> curAstNode;


  Driver(FlexLexer* plex) : plex_(plex) {
    globalScope = std::make_shared<ScopeNode>(nullptr);
    currentScope = globalScope;

    globalAstNode = std::make_shared<GlobalAst>(currentScope);
    curAstNode = globalAstNode;
  };

  parser::token_type yylex(parser::semantic_type *yylval) {
    parser::token_type tt = static_cast<parser::token_type>(plex_->yylex());
    if (tt == yy::parser::token_type::NUM)
      yylval->as<int>() = std::stoi(plex_->YYText());
    
    if(tt == yy::parser::token_type::ID_string)
    {
      std::cout << "yytext: " << plex_->YYText() << std::endl;; 
      yylval->build<std::string>();
      yylval->as<std::string>() = std::string(plex_->YYText());
    }
    return tt;
  };

  bool parse() {
    parser parser(this);
    
    bool res = parser.parse();
    return !res;
  };
};

} // namespace yy