#pragma once

#include <string>

class Variable {
    public:
    const std::string name;
    int value;
    int id; 

    Variable(const std::string n = "", int v1 = 0, int v2 = 0) : name(n), value(v1), id(v2) {
        std::cout << "{ Variable was made\n     { name: " << name << "\n    value: " << value << "\n    }\n}" << std::endl; 
    };
};