#include <iostream>
#include <fstream>
#include <string>

#include "driver.hpp"
#include "Node.cc"

int yyFlexLexer::yywrap() { return 1; }

ScopeNode* globalScope;

ScopeNode* currentScope = globalScope;

int main(int argc, char *argv[]) { 
  if(argc != 2) {
    std::cout << "Usage: " << argv[0] << " <filename>" << std::endl;
    return 1;
  }

  std::string filename = argv[1];
  std::ifstream file(filename);
  
  if (!file.is_open()) {
      std::cerr << "Error opening file" << std::endl;
      return 1;
  }
  else { dump_file << "The file was opened successfully" << std::endl; }

  FlexLexer *lexer = new yyFlexLexer;
  lexer->switch_streams(&file, nullptr);

  yy::Driver driver(lexer, currentScope);
  
  currentScope->create_scope();

  dump_file << "Start parsing" << std::endl;

  driver.parse();
  file.close();

  delete lexer;
}