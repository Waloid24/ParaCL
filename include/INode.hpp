#pragma once
#include <memory> 
#include <fstream>

class INode {    
    public:
    virtual void dump_ast() = 0;
    virtual int calculate() = 0;

    virtual ~INode() {};
};

enum class Operations {
    Assign, 
    Minus,
    Plus,
    Multiply,
    Divide,
    Less,
    Greater,
    GreaterEq,
    LessEq,
    Equal,
    NonEqual,
    And, 
    Or,
    Input,
    Output, 
    UnaryMinus
};

//---------------------------------------------------------
//fabric ctors
std::shared_ptr<INode> make_value(int);
std::shared_ptr<INode> make_operator(std::shared_ptr<INode> l, Operations Op, std::shared_ptr<INode> r);
std::shared_ptr<INode> make_while(std::shared_ptr<INode> l, std::shared_ptr<INode> s);
std::shared_ptr<INode> make_if(std::shared_ptr<INode> l, std::shared_ptr<INode> s, std::shared_ptr<INode> e);
std::shared_ptr<INode> make_var(std::string, std::shared_ptr<INode> curScope);