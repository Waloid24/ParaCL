#pragma once

#include "INode.hpp"

// #include <vector>
#include <unordered_map>
// #include <functional>
//---------------------------------------------------------
class ValueNode final: public INode {
    
    int value;

    public:
    ValueNode(int value): value(value) {}; 

    int calculate() {
        return value;
    }
    void dump_ast() {
        std::cout << "Current Value Node: " << value << std::endl;
    }

    ~ValueNode() {};
};
//---------------------------------------------------------
class OperatorNode final: public INode {
    private:

    Operations Op;
    std::shared_ptr<INode> l;
    std::shared_ptr<INode> r;

    static const std::unordered_map<Operations, std::string> OpStrings;
    static std::unordered_map<Operations, std::function<int(int, int)>> OperationMap;

    int calculate() override;
    void dump_ast() override;

    public:
    OperatorNode(std::shared_ptr<INode> l, Operations Op, std::shared_ptr<INode> r): l(l), Op(Op), r(r) {};

    ~OperatorNode() {
        // l.reset();
        // r.reset();
    };
};
//---------------------------------------------------------
class IfNode final: public INode {

    std::shared_ptr<INode> l;
    std::shared_ptr<INode> r;
    std::shared_ptr<INode> e;

    int calculate() override;
    void dump_ast() override;

    public:
    IfNode(std::shared_ptr<INode> l, std::shared_ptr<INode> r, std::shared_ptr<INode> e): l(l), r(r), e(e) {};

    ~IfNode() {};
};
//---------------------------------------------------------
class WhileNode final: public INode {
    std::shared_ptr<INode> condition;
    std::shared_ptr<INode> block;

    int calculate() override;
    void dump_ast() override;

    public:
    WhileNode(std::shared_ptr<INode> condition, std::shared_ptr<INode> block): condition(condition), block(block) {};

    ~WhileNode() {};
};
//---------------------------------------------------------
std::shared_ptr<INode> make_value(int value) {
    return std::make_shared<ValueNode>(value);
}

std::shared_ptr<INode> make_operator(std::shared_ptr<INode> left, Operations op, std::shared_ptr<INode> right) {
    return std::make_shared<OperatorNode>(left, op, right);
}

std::shared_ptr<INode> make_while(std::shared_ptr<INode> condition, std::shared_ptr<INode> statement) {
    return std::make_shared<WhileNode>(condition, statement);
}

std::shared_ptr<INode> make_if(std::shared_ptr<INode> condition, std::shared_ptr<INode> statement, std::shared_ptr<INode> else_stmt) {
    return std::make_shared<IfNode>(condition, statement, else_stmt);
}

// std::shared_ptr<INode> make_var(std::string, ScopeNode* curScope) {
    
// };