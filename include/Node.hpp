#pragma once

#include "ASTNode.hpp"
#include "ScopeNode.hpp"

#include <iostream>
#include <unordered_map>
#include <functional>

// std::ofstream std::cout("output.dat");
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
        std::cout << "hfjdkls" << std::endl;
        return nullptr;
    }

    return std::make_shared<IdNode>(id, scope);
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
    inline void dump_ast() override {
        std::cout << "Operator Node" << std::endl;
    };

    public:
    OperatorNode(std::shared_ptr<ASTNode> l, Operations Op, std::shared_ptr<ASTNode> r,
    std::shared_ptr<ScopeNode> scope): l(l), Op(Op), r(r), ASTNode(scope) { 
        std::cout << "Operator node ctor" << std::endl;};

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
    const std::string set_ID;
    // int id;
    std::shared_ptr<ASTNode> expr;

    inline int calculate() override;
    inline void dump_ast() override { 
        std::cout << "{ set_ID: " << set_ID << "\n expr value: " << expr->calculate() << "\n}" << std::endl;
    };

    public:
    AssignmentNode(std::string set_ID, std::shared_ptr<ASTNode> expr, 
    std::shared_ptr<ScopeNode> scope): expr(expr), set_ID(set_ID), ASTNode(scope) {
        std::cout << "AssignNode ctor" << std::endl;
    };

    ~AssignmentNode() {};
};
//---------------------------------------------------------
inline int AssignmentNode::calculate() {
    auto id = scope->getIdFromSetVariable(set_ID);
    scope->assign_value(id, expr->calculate());
    return 0;
};

// class Binary
// class Unary