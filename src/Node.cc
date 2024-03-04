#include <iostream>
#include <unordered_map>
#include <memory>

#include "../include/Node.hpp"

//---------------------------------------------------------
// OperatorNode implementation
std::unordered_map<BinaryOp, std::function<int(int, int)>> BinaryNode::OperationMap = {
    {BinaryOp::Plus, [](int a, int b) { return a + b; }},
    {BinaryOp::Minus, [](int a, int b) { return a - b; }},
    {BinaryOp::Multiply, [](int a, int b) { return a * b; }},
    {BinaryOp::Divide, [](int a, int b) { return a / b; }},
    {BinaryOp::Less, [](int a, int b) { return (a < b); }},
    {BinaryOp::Greater, [](int a, int b) { return (a > b); }},
    {BinaryOp::LessEq, [](int a, int b) { return (a <= b); }},
    {BinaryOp::GreaterEq, [](int a, int b) { return (a >= b); }},
    {BinaryOp::Equal, [](int a, int b) { return (a == b); }},
    {BinaryOp::NonEqual, [](int a, int b) { return (a != b); }},
    {BinaryOp::And, [](int a, int b) { return (a && b); }},
    {BinaryOp::Or, [](int a, int b) { return (a || b); }},
};

int BinaryNode::calculate() {
    if (OperationMap.find(Op) != OperationMap.end()) {
        return OperationMap[Op]((l->get_type() == NodeType::Id) ? scope->lookup(l->calculate())->value :
        l->calculate(), (r->get_type() == NodeType::Id) ? scope->lookup(r->calculate())->value : r->calculate());

    } else {
        std::cerr << "Unsupported operation" << std::endl;
        return 0;
    }
}
//---------------------------------------------------------
// UnaryNode implementation
int UnaryNode::calculate() {
    int operandValue = operand->calculate();

    switch (Op) {
        case UnaryOp::Minus:
            return -operandValue;
        case UnaryOp::Increment:
            return operandValue + 1;
        case UnaryOp::Decrement:
            return operandValue - 1;
        // case UnaryOp::Negate:
        //     return !operandValue;
        default:
            throw std::runtime_error("Unknown UnaryOpType");
    }
}

