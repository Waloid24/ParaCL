#pragma once

class INode {
    // храним ссылку на конкретный scope (всем родительским узел тогда тоже принадлежит)
    
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
    Output, 
    UnaryMinus
};


enum class NodeType {

};
//---------------------------------------------------------
//fabric ctors
INode* make_value(int);
INode* make_operator(INode* l, Operations Op, INode* r);
INode* make_while(INode* l, INode* s);
INode* make_if(INode* l, INode* s);
// ScopeNode* create_scope();