#include <iostream>
#include <fstream>
#include <string>

#include "driver.hpp"
#include "ScopeTree.hpp"
// #include "scanner.cc"

int yyFlexLexer::yywrap() { return 1; }

std::shared_ptr<ScopeNode> globalScope = std::make_shared<ScopeNode>();

std::shared_ptr<ScopeNode>& currentScope = globalScope;

int main(int argc, char *argv[]) { 
  if(argc != 2) {
    std::cout << "Usage: " << argv[0] << " <filename>" << std::endl;
    return 1;
  }
  std::ifstream file(argv[1]);
  if (!file.is_open()) {
      std::cerr << "Error opening file" << std::endl;
      return 1;
  }
  else { std::cout << "The file was opened successfully" << std::endl; }

  FlexLexer *lexer = new yyFlexLexer;
  lexer->switch_streams(&file, nullptr);

  yy::Driver driver(lexer, currentScope);
  currentScope->add_branch(currentScope);

  std::cout << "Start parsing" << std::endl;

  driver.parse();
  file.close();

  delete lexer;
}