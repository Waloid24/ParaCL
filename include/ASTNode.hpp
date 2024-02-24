#pragma once

#include <memory> 
#include <fstream>
#include <iostream>

#include "ScopeNode.hpp" 

class ASTNode {  
    public:
    std::shared_ptr<ScopeNode> scope;   
    ASTNode(std::shared_ptr<ScopeNode> curScope): scope(curScope) {};

    virtual void dump_ast() = 0;
    virtual int calculate() = 0;

    virtual ~ASTNode() {};
};

class GlobalAst : public ASTNode {
    std::vector<ASTNode> childs;

    public:
    GlobalAst(std::shared_ptr<ScopeNode> curScope): ASTNode(curScope) {}
    void dump_ast() override {
        std::cout << "Global Node" << std::endl;
    };
    int calculate() override {
        for(auto && child: childs) {
            child.calculate();
        }
        return 0;
    };
};

enum class Operations {
    Minus,
    Plus,
    Multiply,
    Divide,
    Less,
    Greater,
    GreaterEq,
    LessEq,
    Equal,
    NonEqual,
    And, 
    Or,
    Input,
    Output, 
    UnaryMinus
};

//---------------------------------------------------------