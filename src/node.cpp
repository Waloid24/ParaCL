#include "../include/node.hpp"

void Id_node::assign_value(int value)
{
    var_->change_value(value);
}

int Bin_op_node::process_node() 
{
    int value = 0;
    switch(b_type_)
    {
        case bin_op_type::PLUS:
            return first_->process_node() + second_->process_node();
        case bin_op_type::MINUS:
            return first_->process_node() - second_->process_node();
        case bin_op_type::MUL:
            return first_->process_node() * second_->process_node();
        case bin_op_type::DIV:
            value = second_->process_node();
            if (value == 0)
                throw std::runtime_error("Division by zero");
            return first_->process_node() / value;
        case bin_op_type::GREATER:
            return first_->process_node() > second_->process_node();
        case bin_op_type::GREATER_EQUAL:
            return first_->process_node() >= second_->process_node();
        case bin_op_type::LESS:
            return first_->process_node() < second_->process_node();
        case bin_op_type::LESS_EQUAL:
            return first_->process_node() <= second_->process_node();
        case bin_op_type::NOT_EQUAL:
            return first_->process_node() != second_->process_node();
        case bin_op_type::OR:
            return first_->process_node() || second_->process_node();
        case bin_op_type::AND:
            return first_->process_node() && second_->process_node();
        case bin_op_type::ASSIGN:
            Id_node* lval = static_cast<Id_node*> first_;
            value = second_->process_node();
            first_->assign_value(value);
            return value;
        default:
            throw std::runtime_error("Unexpected error of the binary operator!");
    }
}

int Un_op_node::process_node()
{
    switch(un_node_)
    {
        case un_op_node::U_PLUS:
            return first_->process_node();
        case un_op_node::U_MINUS:
            return -(first_->process_node());
        case un_op_node::NOT:
            return !(first_->process_node());
        default:
            throw std::runtime_error("Unexpected error of the unary operator!");
    }
}

int If_node::process_node()
{
    if (condition_ == nullptr || then_expr_ == nullptr)
        throw std::runtime_error("Unexpected absence of condition!");
    int res = 0;

    if (condition_->process_node())
        res = then_expr_->process_node();
    else if (else_expr_ != nullptr)
        res = else_expr_->process_node();
    return res;
}

int While_node::process_node()
{
    if (condition_ == nullptr)
        throw std::runtime_error("Unexpected absence of condition!");

    while (condition_->process_node())
        then_expr_->process_node();

    return ????;
}

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
    while (scope != nullptr)

    return nullptr;
}

void Scope_node::emplace(const Var* var, const std::string& name)
{
    if (!table_->emplace(var))
        throw std::runtime_error("Unexpected error when inserting characters into the table");

    table_->emplace(var, name);
}
