#include <iostream>
#include <fstream>
#include <string>

#include "ParaCLdriver.hpp"

// here we can return non-zero if lexing is not done inspite of EOF detected
int yyFlexLexer::yywrap() { return 1; }

int main(int argc, char *argv[]) { 
  // if(argc != 2) {
  //   std::cout << "Usage: " << argv[0] << " <filename>" << std::endl;
  //   return 1;
  // }
  // std::ifstream file(argv[1]);
  // if (!file.is_open()) {
  //     std::cerr << "Error opening file" << std::endl;
  //     return 1;
  // }
  // else { std::cout << "The file was opened successfully" << std::endl; }
  
  FlexLexer *lexer = new yyFlexLexer;
  yy::Driver driver(lexer);
  std::cout << "Start parsing" << std::endl;
  driver.parse();
  // file.close();
  delete lexer;
}