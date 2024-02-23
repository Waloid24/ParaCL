#include "Node.hpp"

#include <iostream>
#include <map>
#include <memory>

//---------------------------------------------------------
// OperatorNode implementation
std::unordered_map<Operations, std::function<int(int, int)>> OperatorNode::OperationMap = {
    {Operations::Plus, [](int a, int b) { return a + b; }},
    {Operations::Minus, [](int a, int b) { return a - b; }},
    {Operations::Multiply, [](int a, int b) { return a * b;}},
    {Operations::Divide, [](int a, int b) { return a / b;}},
    // дописать операции
};

int OperatorNode::calculate() {
    if (OperationMap.find(Op) != OperationMap.end()) {
        return OperationMap[Op](l->calculate(), r->calculate());
    } else {
        std::cerr << "Unsupported operation" << std::endl;
        return 0;
    }
}

//---------------------------------------------------------
// IfNode implementation
int IfNode::calculate() {return 0;}
void IfNode::dump_ast() {}

//---------------------------------------------------------
// WhileNode implementation
int WhileNode::calculate() {return 0;}
void WhileNode::dump_ast() {}

