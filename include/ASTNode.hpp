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

    ASTNode(std::shared_ptr<ScopeNode> curScope, NodeType type): scope(curScope), type(type) {};
    NodeType get_type() { return type; };
    virtual void dump_ast(std::ofstream& dump_file) = 0;
    virtual int calculate() = 0;

    virtual ~ASTNode() {};
};

class GlobalAst : public ASTNode {
    public:
    std::vector<std::shared_ptr<ASTNode>> childs;
    std::shared_ptr<ASTNode> child; 
    std::weak_ptr<ASTNode> predessor;

    GlobalAst(std::shared_ptr<ScopeNode> curScope, std::shared_ptr<ASTNode> predessor): 
    ASTNode(curScope, NodeType::None), predessor(predessor) {}

    void dump_ast(std::ofstream& dump_file) override {
        dump_file << "Global Node" << std::endl;
        for(auto && child_: childs) {
            child_->dump_ast(dump_file);
        }
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