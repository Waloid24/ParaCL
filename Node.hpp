#pragma once

#include "INode.hpp"
#include "Symtab.hpp"

#include <vector>
#include <unordered_map>
#include <functional>
//---------------------------------------------------------


//---------------------------------------------------------
class ValueNode final: public INode {
    private:
    int value;

    public:
    ValueNode(int value): value(value) {}; 

    int calculate() override;
    void print_info() override;
};
//---------------------------------------------------------
class OperatorNode final: public INode {
    private:
    Operations Op;
    INode* l;
    INode* r;

    static const std::map<Operations, std::string> OpStrings;
    static std::unordered_map<Operations, std::function<int(int, int)>> OperationMap;

    int calculate() override;
    void print_info() override;

    public:
    OperatorNode(INode* l, Operations Op, INode* r): l(l), Op(Op), r(r) {};
};
//---------------------------------------------------------
class IfNode final: public INode {
    INode* l;
    INode* r;

    int calculate() override;
    void print_info() override;

    public:
    IfNode(INode* l, INode* r): l(l), r(r) {};
};
//---------------------------------------------------------
class WhileNode final: public INode {
    INode* condition;
    INode* block;

    int calculate() override;
    void print_info() override;

    public:
    WhileNode(INode* condition, INode* block): condition(condition), block(block) {};
};
//---------------------------------------------------------
