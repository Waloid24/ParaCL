#pragma once

#include <string>

class Variable {
    public:
    std::string name;
    int value;
    // int key; 

    Variable(const std::string& n = "", int v1 = 0) : name(n), value(v1) {
        std::cout << "{ Variable was made\n     { name: " << name << "\n    value: " << value << "\n    }\n}" << std::endl; 
    };
};