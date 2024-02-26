#pragma once

#include "ASTNode.hpp"
#include "ScopeNode.hpp"

#include <iostream>
#include <unordered_map>
#include <functional>

// std::ofstream dump_file("output.dat");
//---------------------------------------------------------
class NumNode final: public ASTNode {
    
    int value;

    public:
    NumNode(int value, std::shared_ptr<ScopeNode> scope): value(value), ASTNode(scope) { 
        std::cout << "Num node ctor" << std::endl; 
    }; 

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
    IdNode(int id, std::shared_ptr<ScopeNode> scope): ASTNode(scope), id(id) {};

    inline int calculate() { return id; }

    inline void dump_ast() {
        std::cout << "Id Node" << std::endl;
    };

    ~IdNode() {};
};
//---------------------------------------------------------
inline std::shared_ptr<IdNode> createSetIdNode(const std::string name, std::shared_ptr<ScopeNode> scope)
{
    int id = scope->getIdFromSetVariable(name);
    return std::make_shared<IdNode>(id, scope);
};
//---------------------------------------------------------
inline std::shared_ptr<IdNode> createGetIdNode(const std::string name, std::shared_ptr<ScopeNode> scope)
{
    std::cout << "get Id Node" << std::endl;
    int id = scope->getIdFromGetVariable(name);

    if(id == -1) {
        return nullptr;
    }

    return std::make_shared<IdNode>(id, scope);
};

//---------------------------------------------------------
class BinaryNode final: public ASTNode {
    private:
    BinaryOp Op;
    std::shared_ptr<ASTNode> l;
    std::shared_ptr<ASTNode> r;

    // static const std::unordered_map<Operations, std::string> OpStrings;
    static std::unordered_map<BinaryOp, std::function<int(int, int)>> OperationMap;

    int calculate() override;
    inline void dump_ast() override {
        std::cout << "Operator Node" << std::endl;
    };

    public:
    BinaryNode(std::shared_ptr<ASTNode> l, BinaryOp Op, std::shared_ptr<ASTNode> r,
    std::shared_ptr<ScopeNode> scope): l(l), Op(Op), r(r), ASTNode(scope) { 
        std::cout << "Operator node ctor" << std::endl;};

    ~BinaryNode() {};
};
//---------------------------------------------------------
class IfNode final: public ASTNode {
    std::shared_ptr<ASTNode> l;
    std::shared_ptr<ASTNode> r;
    std::shared_ptr<ASTNode> e;

    int calculate() override;
    void dump_ast() override;

    public:
    IfNode(std::shared_ptr<ASTNode> l, std::shared_ptr<ASTNode> r, std::shared_ptr<ASTNode> e, 
    std::shared_ptr<ScopeNode> scope): l(l), r(r), e(e), ASTNode(scope) {
        std::cout << "If node ctor" << std::endl;
    };

    ~IfNode() {};
};
//---------------------------------------------------------
class WhileNode final: public ASTNode {
    std::shared_ptr<ASTNode> condition;
    std::shared_ptr<ASTNode> block;

    int calculate() override;
    void dump_ast() override;

    public:
    WhileNode(std::shared_ptr<ASTNode> condition, std::shared_ptr<ASTNode> block, 
    std::shared_ptr<ScopeNode> scope): condition(condition), block(block), ASTNode(scope) {
        std::cout << "While node ctor" << std::endl;
    };

    ~WhileNode() {};
};
//---------------------------------------------------------
class AssignmentNode: public ASTNode {
    std::shared_ptr<ASTNode> left;
    std::shared_ptr<ASTNode> right;

    inline int calculate() override;
    inline void dump_ast() override { 
        std::cout << "{ set_ID: " << left << "\n expr value: " << right->calculate() << "\n}" << std::endl;
    };

    public:
    AssignmentNode(std::shared_ptr<ASTNode> IDNode, std::shared_ptr<ASTNode> exprNode, 
    std::shared_ptr<ScopeNode> scope): right(exprNode), left(IDNode), 
    ASTNode(scope) {
        std::cout << "AssignNode ctor" << std::endl;
    };

    ~AssignmentNode() {};
};
//---------------------------------------------------------
inline int AssignmentNode::calculate() {
    scope->assign_value(left->calculate(), right->calculate());
    return 0;
};
//---------------------------------------------------------
class UnaryNode: public ASTNode {
    private:
    UnaryOp Op;
    std::shared_ptr<ASTNode> operand;

    public:
    UnaryNode(UnaryOp Op, std::shared_ptr<ASTNode> operand, std::shared_ptr<ScopeNode> scope): Op(Op), 
    operand(operand), ASTNode(scope) {};

    int calculate() override;

    void dump_ast() override {

    };
};
//---------------------------------------------------------
class InputNode: public ASTNode {
    private:
    int value;

    public:
    InputNode(std::shared_ptr<ScopeNode> scope): ASTNode(scope) {};

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
    OutputNode(std::shared_ptr<ASTNode> child, std::shared_ptr<ScopeNode> scope): child(child), ASTNode(scope) {
    };

    int calculate() override {
        std::cout << child->calculate();
        return 0;
    };

    void dump_ast() override {
        std::cout << "Output Node" << std::endl;
    };

};
//---------------------------------------------------------
//print
//cout << child->calculate()