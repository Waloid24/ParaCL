#pragma once

#include "INode.hpp"

#include <vector>

class ScopeNode: public IScope {
    public:
    ScopeNode() {};

    private:
    std::vector<IScope*> statements;

    public:
    void add_to_scope(IScope* stmt) override;

    
    INode* set_scope() override;
    INode* destroy_scope() override;
    
    INode* lookup() override;
    bool check_visibility() override;

    int calculate() override;
    void print_info() override;
};

class ValueNode: public INode {
    private:
    int value;

    public:
    ValueNode(int value): value(value) {}; 

    int calculate() override;
    void print_info() override;
};

class OperatorNode: public INode {
    private:
    Operations Op;
    INode* l;
    INode* r;

    int calculate() override;
    void print_info() override;

    public:
    OperatorNode(INode* l, Operations Op, INode* r): l(l), Op(Op), r(r) {};
};

class IfNode: public INode {
    INode* l;
    INode* r;

    int calculate() override;
    void print_info() override;

    public:
    IfNode(INode* l, INode* r): l(l), r(r) {};
};

class WhileNode: public INode {
    INode* condition;
    INode* block;

    int calculate() override;
    void print_info() override;

    public:
    WhileNode(INode* condition, INode* block): condition(condition), block(block) {};
};

