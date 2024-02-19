#pragma once

#include "INode.hpp"

#include <iostream>
#include <unordered_map>
#include <functional>

std::ofstream dump_file("output.dat");
//---------------------------------------------------------
class NumNode final: public INode {
    
    int value;

    public:
    NumNode(int value): value(value) { dump_file << "Value node ctor" << std::endl; }; 

    inline int calculate() { return value; }
    inline void dump_ast() {
        dump_file << "{ type: value_node \n     { value: " << value << "\n      }\n}" << std::endl; 
    }

    ~NumNode() {};
};
//---------------------------------------------------------
class IdNode final: public INode {
    std::shared_ptr<Variable> var;

    public:
    IdNode(std::string name) {
        var->name = name;
    };

    inline int calculate() {
        
    };
    inline void dump_ast() {};

    ~IdNode() {};
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
    OperatorNode(std::shared_ptr<INode> l, Operations Op, std::shared_ptr<INode> r): l(l), Op(Op), r(r) { 
        dump_file << "Operator node ctor" << std::endl;};

    ~OperatorNode() {};
};
//---------------------------------------------------------
class IfNode final: public INode {

    std::shared_ptr<INode> l;
    std::shared_ptr<INode> r;
    std::shared_ptr<INode> e;

    int calculate() override;
    void dump_ast() override;

    public:
    IfNode(std::shared_ptr<INode> l, std::shared_ptr<INode> r, std::shared_ptr<INode> e): l(l), r(r), e(e) {
        dump_file << "If node ctor" << std::endl;
    };

    ~IfNode() {};
};
//---------------------------------------------------------
class WhileNode final: public INode {
    std::shared_ptr<INode> condition;
    std::shared_ptr<INode> block;

    int calculate() override;
    void dump_ast() override;

    public:
    WhileNode(std::shared_ptr<INode> condition, std::shared_ptr<INode> block): condition(condition), block(block) {
        dump_file << "While node ctor" << std::endl;
    };

    ~WhileNode() {};
};
//---------------------------------------------------------
std::shared_ptr<INode> make_value(int value) {
    return std::make_shared<NumNode>(value);
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

std::shared_ptr<INode> make_var(std::string name, std::shared_ptr<INode> curScope) {
    return 0;// return std::make_shared<IdNode>(name, curScope);
};