#include "Node.hpp"
#include "ScopeTree.hpp"

#include <iostream>
#include <map>
#include <memory>

// ValueNode implementation
int ValueNode::calculate() { return value; }

void ValueNode::print_info() {                                                                                                        
    std::cout << "Current Value Node: " << value << std::endl;
}
//---------------------------------------------------------
// OperatorNode implementation
std::unordered_map<Operations, std::function<int(int, int)>> OperatorNode::OperationMap = {
    {Operations::Assign, [](int a, int b) {return a = b;}}, 
    //найти по ключу переменную и присвоить в значения переменной результат выражения
    {Operations::Plus, [](int a, int b) { return a + b; }},
    {Operations::Minus, [](int a, int b) { return a - b; }},
    {Operations::Multiply, [](int a, int b) { return a * b;}},
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

const std::unordered_map<Operations, std::string> OperatorNode::OpStrings = {
    {Operations::Minus, "-"},
    {Operations::Plus, "+"},
    {Operations::And, "&&"},
    {Operations::Or, "||"},
    {Operations::Assign, "="},
    {Operations::Divide, "/"},
    {Operations::Equal, "=="},
    {Operations::Greater, ">"},
    {Operations::GreaterEq, ">="},
    {Operations::Input, "?"},
    {Operations::Output, "Print"},
    {Operations::Less, "<"},
    {Operations::LessEq, "<="},
    {Operations::NonEqual, "!="}
};


void OperatorNode::print_info() {
    std::cout << "An operation is in progress: " << OpStrings.at(Op) << std::endl;
}

//---------------------------------------------------------
// IfNode implementation
int IfNode::calculate() {}
void IfNode::print_info() {}

//---------------------------------------------------------
// WhileNode implementation
int WhileNode::calculate() {}
void WhileNode::print_info() {}

//---------------------------------------------------------