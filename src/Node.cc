#include "Node.hpp"

#include <iostream>
#include <map>
#include <memory>

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


void OperatorNode::dump_ast() {
    std::cout << "An operation is in progress: " << OpStrings.at(Op) << std::endl;
}

//---------------------------------------------------------
// IfNode implementation
int IfNode::calculate() {return 0;}
void IfNode::dump_ast() {}

//---------------------------------------------------------
// WhileNode implementation
int WhileNode::calculate() {return 0;}
void WhileNode::dump_ast() {}

