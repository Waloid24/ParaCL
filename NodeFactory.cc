#include "Node.hpp"
#include <iostream>

// ValueNode implementation
int ValueNode::calculate() {
    return value;
}

void ValueNode::print_info() {                                                                                                        
    std::cout << "Current Value Node: " << value << std::endl;
}
//---------------------------------------------------------
// OperatorNode implementation
int OperatorNode::calculate() {}
void OperatorNode::print_info() {}

//---------------------------------------------------------
// IfNode implementation
int IfNode::calculate() {}
void IfNode::print_info() {}

//---------------------------------------------------------
// WhileNode implementation
int WhileNode::calculate() {}
void WhileNode::print_info() {}

//---------------------------------------------------------
// ScopeNode implementation
INode* ScopeNode::set_scope() {};
INode* ScopeNode::destroy_scope() {};

void ScopeNode::add_to_scope(IScope* stmt) {
    statements.push_back(stmt);
};

INode* ScopeNode::lookup() {};
bool ScopeNode::check_visibility() {};

int ScopeNode::calculate() {}
void ScopeNode::print_info() {}

//---------------------------------------------------------
// fabric ctors implementation

INode* make_value(int val) { 
    return new ValueNode{val}; 
}

INode* make_operator(INode* l, Operations Op, INode* r) {
    return new OperatorNode{l, Op, r};
}

INode* make_if(INode* condition, INode* block) {
    return new IfNode{condition, block};
}

INode* make_while(INode* condition, INode* block) {
    return new WhileNode{condition, block};
}

IScope* create_scope() {
    return new ScopeNode();
}

