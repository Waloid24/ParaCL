#pragma once

#include "ASTNode.hpp"
#include "ScopeNode.hpp"

#include <iostream>
#include <unordered_map>
#include <functional>

//---------------------------------------------------------
class NumNode final: public ASTNode {
    // NodeType type = NodeType::Num;
    int value;

    public:
    NumNode(int value, std::shared_ptr<ScopeNode> scope): value(value), ASTNode(scope, NodeType::Num) {}; 

    inline int calculate() { return value; }
    inline void dump_ast() {
        std::cout << "{ type: value_node \n     { value: " << value << "\n      }\n}" << std::endl; 
    }

    ~NumNode() {};
};
//---------------------------------------------------------
class IdNode final: public ASTNode  {
    int id;

    public:
    IdNode(int id, std::shared_ptr<ScopeNode> scope): id(id), ASTNode(scope, NodeType::Id) {};

    inline int calculate() { return id; }
    
    
    inline void dump_ast() {
        std::cout << "Id Node" << std::endl;
    };

    ~IdNode() {};
};
//---------------------------------------------------------
inline std::shared_ptr<ASTNode> createSetIdNode(const std::string name, std::shared_ptr<ScopeNode> scope)
{
    int id = scope->getIdFromSetVariable(name);
    return std::shared_ptr<ASTNode>(new IdNode(id, scope));
};
//---------------------------------------------------------
inline std::shared_ptr<ASTNode> createGetIdNode(const std::string name, std::shared_ptr<ScopeNode> scope)
{
    int id = scope->getIdFromGetVariable(name);
    return std::shared_ptr<ASTNode>(new IdNode(id, scope));
};
//---------------------------------------------------------
class BinaryNode final: public ASTNode {
    BinaryOp Op;
    std::shared_ptr<ASTNode> l;
    std::shared_ptr<ASTNode> r;

    static std::unordered_map<BinaryOp, std::function<int(int, int)>> OperationMap;

    int calculate() override;
    inline void dump_ast() override {
        std::cout << "Operator Node" << std::endl;
    };

    public:
    BinaryNode(std::shared_ptr<ASTNode> l, BinaryOp Op, std::shared_ptr<ASTNode> r,
    std::shared_ptr<ScopeNode> scope): l(l), Op(Op), r(r), ASTNode(scope, NodeType::Operation) { 

    };

    ~BinaryNode() {};
};
//---------------------------------------------------------
class IfNode final: public ASTNode {
    std::shared_ptr<ASTNode> condition;
    std::shared_ptr<ASTNode> body;
    std::shared_ptr<ASTNode> else_block;

    public:
    IfNode(std::shared_ptr<ASTNode> condition, std::shared_ptr<ASTNode> body, std::shared_ptr<ASTNode> else_block, 
    std::shared_ptr<ScopeNode> scope): condition(condition), body(body), else_block(else_block), 
    ASTNode(scope, NodeType::If) {
        std::cout << "If node ctor" << std::endl;
    };

    int calculate() override {
        if(condition->calculate()) {
            return body->calculate();
        }
        else {
            return else_block->calculate();
        }
    }
    void dump_ast() override {
        std::cout << "If Node" << std::endl;
    }

    ~IfNode() {};
};
//---------------------------------------------------------
class WhileNode final: public ASTNode {
    // NodeType type = NodeType::While;

    std::shared_ptr<ASTNode> condition;
    std::shared_ptr<ASTNode> block;

    public:
    WhileNode(std::shared_ptr<ASTNode> condition, std::shared_ptr<ASTNode> block, 
    std::shared_ptr<ScopeNode> scope): condition(condition), block(block), ASTNode(scope, NodeType::While) {
        std::cout << "While node ctor" << std::endl;
    };

    int calculate() override {
        while(condition->calculate()) {
            return block->calculate();
        }
        return 0;
    }
    void dump_ast() override {
        std::cout << "While Node" << std::endl;
    }

    ~WhileNode() {};
};
//---------------------------------------------------------
class AssignmentNode: public ASTNode {
    // NodeType type = NodeType::Assign;

    std::shared_ptr<ASTNode> lval;
    std::shared_ptr<ASTNode> right;

    inline int calculate() override;
    inline void dump_ast() override { 
        
    };

    public:
    AssignmentNode(std::shared_ptr<ASTNode>  lval, std::shared_ptr<ASTNode> exprNode, 
    std::shared_ptr<ScopeNode> scope): right(exprNode), lval(lval), 
    ASTNode(scope, NodeType::Assign) { };

    ~AssignmentNode() {};
};
//---------------------------------------------------------
inline int AssignmentNode::calculate() {
    // scope->assign_value(lval->calculate(), right->calculate());
    scope->lookup(lval->calculate())->value = (right->get_type() == NodeType::Id) ? 
    scope->lookup(right->calculate())->value : right->calculate();
    return 0;
};
//---------------------------------------------------------
class UnaryNode: public ASTNode {
    // NodeType type = NodeType::Operation;
    UnaryOp Op;
    std::shared_ptr<ASTNode> operand;

    public:
    UnaryNode(UnaryOp Op, std::shared_ptr<ASTNode> operand, std::shared_ptr<ScopeNode> scope): Op(Op), 
    operand(operand), ASTNode(scope, NodeType::Operation) {};

    int calculate() override;

    void dump_ast() override {

    };
};
//---------------------------------------------------------
class InputNode: public ASTNode {
    // NodeType type = NodeType::Input;
    int value;

    public:
    InputNode(std::shared_ptr<ScopeNode> scope): ASTNode(scope, NodeType::Input) {};

    int calculate() override {
        std::cin >> value;
        return value;
    };

    void dump_ast() override {

    };

};
//---------------------------------------------------------
class OutputNode: public ASTNode {
    std::shared_ptr<ASTNode> child;
    
    public:
    OutputNode(std::shared_ptr<ASTNode> child, std::shared_ptr<ScopeNode> scope): 
    child(child), ASTNode(scope, NodeType::Output) {};

    int calculate() override {
        
        std::cout << scope->lookup(child->calculate())->value << std::endl;
        return 0;
    };

    void dump_ast() override {
        std::cout << "Output Node" << std::endl;
    };

};
//---------------------------------------------------------