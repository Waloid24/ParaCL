#pragma once

class INode {
    public:
    virtual void print_info() = 0;
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
    Output
};

//---------------------------------------------------------
//fabric ctors
INode* make_value(int);
INode* make_operator(INode* l, Operations Op, INode* r);
INode* make_while(INode* l, INode* s);
INode* make_if(INode* l, INode* s);
IScope* create_scope();