#pragma once

#include "ASTNode.hpp"

#include <iostream>
#include <unordered_map>
#include <functional>

std::ofstream dump_file("output.dat");
//---------------------------------------------------------
class NumNode final: public ASTNode {
    
    int value;

    public:
    NumNode(int value, std::shared_ptr<ScopeNode> scope): value(value), ASTNode(scope) { 
        dump_file << "Value node ctor" << std::endl; 
    }; 

    inline int calculate() { return value; }
    inline void dump_ast() {
        dump_file << "{ type: value_node \n     { value: " << value << "\n      }\n}" << std::endl; 
    }

    ~NumNode() {};
};
//---------------------------------------------------------
class IdNode final: public ASTNode  {
    int id;

    public:
    IdNode(int id, std::shared_ptr<ScopeNode> scope): ASTNode(scope), id(id) {};

    int calculate() { return id; }

    void dump_ast() {
        dump_file << "Id Node" << std::endl;
    };

    ~IdNode() {};
};
//---------------------------------------------------------
std::shared_ptr<IdNode> createSetIdNode(std::string name, std::shared_ptr<ScopeNode> scope)
{
    int id = scope->getIdFromSetVariable(name);
    return std::shared_ptr<IdNode>(new IdNode(id, scope));
};
//---------------------------------------------------------
std::shared_ptr<IdNode> createGetIdNode(std::string name, std::shared_ptr<ScopeNode> scope)
{
    int id = scope->getIdFromGetVariable(name);
    if(id == -1) {
        std::cout << "hfjdkls" << std::endl;
        return nullptr;
    }
    return std::shared_ptr<IdNode>(new IdNode(id, scope));
};

//---------------------------------------------------------
class OperatorNode final: public ASTNode {
    private:
    Operations Op;
    std::shared_ptr<ASTNode> l;
    std::shared_ptr<ASTNode> r;

    // static const std::unordered_map<Operations, std::string> OpStrings;
    static std::unordered_map<Operations, std::function<int(int, int)>> OperationMap;

    int calculate() override;
    void dump_ast() override;

    public:
    OperatorNode(std::shared_ptr<ASTNode> l, Operations Op, std::shared_ptr<ASTNode> r,
    std::shared_ptr<ScopeNode> scope): l(l), Op(Op), r(r), ASTNode(scope) { 
        dump_file << "Operator node ctor" << std::endl;};

    ~OperatorNode() {};
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
        dump_file << "If node ctor" << std::endl;
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
        dump_file << "While node ctor" << std::endl;
    };

    ~WhileNode() {};
};

class AssignmentNode: public ASTNode {
    std::string set_ID;
    // int id;
    std::shared_ptr<ASTNode> expr;

    int calculate() override;
    void dump_ast() override { 
        dump_file << "{ set_ID: " << set_ID << "\n expr value: " << expr->calculate() << "\n}" << std::endl;
    }

    public:
    AssignmentNode(std::string set_ID, std::shared_ptr<ASTNode> expr, 
    std::shared_ptr<ScopeNode> scope): expr(expr), set_ID(set_ID), ASTNode(scope) {
        dump_file << "AssignNode ctor" << std::endl;
    };

    ~AssignmentNode() {};
};

int AssignmentNode::calculate() {
    // берем правого ребенка, getIdFromSetVar, получили id
    // левый ребенок: там считается выражение как оператор нода - value node, у себя 
    // они посчитали calculate вернули int значение
    // присвоить value это int значение

    auto id = scope->getIdFromSetVariable(set_ID);
    scope->assign_value(id, expr->calculate());
    return 0;
}

// class Binary
// class Unary