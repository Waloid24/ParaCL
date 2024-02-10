#include <iostream>
#include <memory>
#include "../include/driver.hpp"

int yyFlexLexer::yywrap() { return 1; }

int main(int argc, char* argv[]) {

    // if (argc != 2)
    // {
    //     std::cerr << "You should enter: ./ParaCL <program_name>" << std::endl;
    //     return 1;
    // }

    yy::Driver driver(argv[1]);
    try
    {
        driver.parse();
    }
    catch(const std::exception& e)
    {
        std::cout << "Some error" << std::endl;
        std::cerr << e.what() << std::endl;
        return 1;
    }
    std::cout << "Without error" << std::endl;
    return 0;
}