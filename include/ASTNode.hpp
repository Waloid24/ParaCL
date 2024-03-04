#pragma once

#include <memory> 
#include <fstream>
#include <iostream>

#include "ScopeNode.hpp" 

enum class NodeType {
    None,
    Num,
    Id, 
    Assign, 
    Operation, 
    If, 
    While,
    Input,
    Output,
};

class ASTNode {  
    protected:
    NodeType type;

    public:
    std::shared_ptr<ScopeNode> scope;   

    ASTNode(std::shared_ptr<ScopeNode> curScope, NodeType type): scope(curScope), type(type) {
        // std::cout << "AST Node Ctor" << std::endl;
    };
    NodeType get_type() { return type; };
    virtual void dump_ast() = 0;
    virtual int calculate() = 0;

    virtual ~ASTNode() {};
};

class GlobalAst : public ASTNode {
    public:
    std::vector<std::shared_ptr<ASTNode>> childs;
    std::shared_ptr<ASTNode> child; 

    GlobalAst(std::shared_ptr<ScopeNode> curScope): ASTNode(curScope, NodeType::None) {
    }
    void dump_ast() override {
        std::cout << "Global Node" << std::endl;
    };

    int calculate() override {
        for(auto && child_: childs) {
            child_->calculate();
        }
        return 0;
    };

    void create_child(std::shared_ptr<ASTNode> child) {
        childs.push_back(child);
    };
};

enum class BinaryOp {
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
};

enum class UnaryOp {
    Minus,
    Increment,
    Decrement,
    Negate, 
};

//---------------------------------------------------------