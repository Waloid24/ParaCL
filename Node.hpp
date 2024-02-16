#pragma once

#include "INode.hpp"
// #include "Symtab.hpp"

#include <vector>
#include <unordered_map>
#include <functional>
//---------------------------------------------------------
class ValueNode final: public INode {
    
    int value;

    public:
    ValueNode(int value): value(value){}; 

    int calculate() override;
    void print_info() override;
};
//---------------------------------------------------------
class OperatorNode final: public INode {
    private:

    Operations Op;
    INode* l;
    INode* r;

    static const std::unordered_map<Operations, std::string> OpStrings;
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
    INode* e;

    int calculate() override;
    void print_info() override;

    public:
    IfNode(INode* l, INode* r, INode* e): l(l), r(r), e(e) {};
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
INode* make_value(int value) {
    return new ValueNode(value);
}

INode* make_operator(INode* left, Operations op, INode* right) {
    return new OperatorNode(left, op, right);
}

INode* make_while(INode* condition, INode* statement) {
    return new WhileNode(condition, statement);
}

INode* make_if(INode* condition, INode* statement, INode* else_stmt) {
    return new IfNode(condition, statement, else_stmt);
}
// ScopeNode* create_scope(){
//     return new ScopeNode();
// }