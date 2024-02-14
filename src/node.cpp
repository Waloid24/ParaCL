#include "node.hpp"
#include <iostream>
namespace nodes
{

// Not an anonymous namespace, because we don't want to inflate the code

static Base_node* get_left_node(Base_node* node)
{
    node_type type = node->get_type();

    switch(type)
    {
        case node_type::BIN_OP:
        {
            Bin_op_node* b_node = static_cast<Bin_op_node*>(node);
            return b_node->get_left_node();
        }
        case node_type::UN_OP:
        {
            Un_op_node* b_node = static_cast<Un_op_node*>(node);
            return b_node->get_left_node();
        }
        default:
            return nullptr;
    }
}

static Base_node* get_right_node(Base_node* node)
{
    node_type type = node->get_type();

    if(type == node_type::BIN_OP)
    {
        Bin_op_node* b_node = static_cast<Bin_op_node*>(node);
        return b_node->get_right_node();
    }
    else
    {
        return nullptr;
    }
}

static void delete_tree(Base_node* node)
{
    if (node == nullptr) return;

    node_type type = node->get_type();
    if (type != node_type::BIN_OP && type != node_type::UN_OP)
    {
        delete node;
    }
    else
    {
        delete_tree(get_left_node(node));
        delete_tree(get_right_node(node));

        delete node;
    }
}

void Id_node::assign_value(int value)
{
    var_->change_value(value);
}

int Bin_op_node::process_node() 
{
    int value = 0;
    Id_node* lval = nullptr;
    switch(b_type_)
    {
        case bin_op_type::PLUS:
            return (first_->process_node() + second_->process_node());
        case bin_op_type::MINUS:
            return (first_->process_node() - second_->process_node());
        case bin_op_type::MUL:
            return (first_->process_node() * second_->process_node());
        case bin_op_type::DIV:
            value = second_->process_node();
            if (value)
                return (first_->process_node() / value);
            else
                throw std::runtime_error("Division by zero");
        case bin_op_type::GREATER:
            return (first_->process_node() > second_->process_node());
        case bin_op_type::GREATER_EQUAL:
            return (first_->process_node() >= second_->process_node());
        case bin_op_type::LESS:
            return (first_->process_node() < second_->process_node());
        case bin_op_type::LESS_EQUAL:
            return (first_->process_node() <= second_->process_node());
        case bin_op_type::EQUAL:
            return (first_->process_node() == second_->process_node());
        case bin_op_type::NOT_EQUAL:
            return (first_->process_node() != second_->process_node());
        case bin_op_type::OR:
            return (first_->process_node() || second_->process_node());
        case bin_op_type::AND:
            return (first_->process_node() && second_->process_node());
        case bin_op_type::ASSIGN:
            std::cout << "Into bin_op_type::ASSIGN" << std::endl;
            lval = static_cast<Id_node*>(first_);
            value = second_->process_node();
            lval->assign_value(value);
            return value;
        default:
            throw std::runtime_error("Unexpected error of the binary operator!");
    }
}

//-------------------------------------Un_op_node------------------------------------------
int Un_op_node::process_node()
{
    switch(un_node_)
    {
        case un_op_type::U_MINUS:
            return -(first_->process_node());
        case un_op_type::NOT:
            return !(first_->process_node());
        default:
            throw std::runtime_error("Unexpected error of the unary operator!");
    }
}
//-----------------------------------------------------------------------------------------

//-----------------------------------If node-----------------------------------------------
int If_node::process_node()
{
    std::cout << "Into If_node::process_node()" << std::endl;
    if (condition_ == nullptr || then_expr_ == nullptr)
        throw std::runtime_error("Unexpected absence of condition!");
    int res = 0;

    if (condition_->process_node())
    {
        std::cout << "Into If_node::process_node() into if()" << std::endl;
        res = then_expr_->process_node();
    }
        
    else if (else_expr_ != nullptr)
        res = else_expr_->process_node();
    return res;
}
If_node::~If_node()
{
    delete_tree(condition_);
    delete_tree(then_expr_);
    if (else_expr_ != nullptr)
        delete_tree(else_expr_);
}
//-----------------------------------------------------------------------------------------

//-------------------------------------While node------------------------------------------
int While_node::process_node()
{
    if (condition_ == nullptr)
        throw std::runtime_error("Unexpected absence of condition!");

    while (condition_->process_node())
        then_expr_->process_node();

    return 0;
}
While_node::~While_node()
{
    delete_tree(condition_);
    delete_tree(then_expr_);
}
//-----------------------------------------------------------------------------------------

//----------------------------------------Scope node-----------------------------------------

Var* Scope_node::lookup(const std::string& name) const 
{
    Var* result = nullptr;
    auto scope = this;

    do
    {
        result = scope->table_->lookup(name);
        if (result != nullptr)
            return result;
        scope = scope->prev_;
    }
    while (scope != nullptr);

    return nullptr;
}

void Scope_node::add_branch(Base_node* node)
{
    branches_.push_back(node);
}

int Scope_node::process_node()
{
    for (auto branch : branches_)
    {
        branch->process_node();
    }
    return 0;
}

Scope_node::~Scope_node()
{
    delete table_;
    for (Base_node* elem : branches_)
    {
        delete_tree(elem);
    }
}

//-------------------------------------------Func node--------------------------------------

int Func_node::process_node()
{
    int expr = 0;
    switch (f_type_)
    {
        case func_type::INPUT:
            std::cout << "Func_node::process_node INPUT" << std::endl;
            std::cin >> expr;
            return expr;
        
        case func_type::OUTPUT:
            expr = expr_->process_node();
            std::cout << expr << std::endl;;
            return expr;

        default:
            std::cout << "Unexpected error" << std::endl;
    }
    return expr;
}
Func_node::~Func_node()
{
    delete_tree(expr_);
}

}

