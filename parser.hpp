#pragma once
#include <string>

#include "INode.hpp"
#include "ScopeNode.hpp"



struct yyRet {
    std::string name;
    int value;
    INode* node;
    ScopeNode* sc;
};

#define YYSTYPE yyRet