#pragma once

class INode {
    public:
    virtual void print_info() = 0;
    virtual int calculate() = 0;

    virtual ~INode() {};
};

class IScope: public INode {
    public:
    virtual INode* set_scope() = 0;
    virtual INode* destroy_scope() = 0;
    virtual void add_to_scope(IScope* stmt) = 0;
    virtual INode* lookup() = 0;
    virtual bool check_visibility() = 0;

    virtual ~IScope() {};
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