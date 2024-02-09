#ifndef NODE_HPP
#define NODE_HPP

#include <vector>
#include <string>
#include <stdexcept>
#include "symtab.hpp"

namespace nodes
{

enum class node_type {
    INTEGER,
    ID,
    BIN_OP,
    IF,
    WHILE,
    UN_OP,
    SCOPE
};

enum class bin_op_type {
    PLUS,
    MINUS,
    MUL,
    DIV,

    GREATER,
    GREATER_EQUAL,
    LESS,
    LESS_EQUAL,
    EQUAL,
    NOT_EQUAL,
    
    OR,
    AND,
    
    ASSIGN
};

enum class un_op_type {
    U_PLUS,
    U_MINUS,
    NOT
};

class Base_node {

    node_type n_type_;

    public:
        Base_node(node_type n_type) : n_type_{n_type} {}
        virtual ~Base_node() {};
        virtual int process_node() = 0;

};

class Integer_node final : public Base_node {

    int value_;

    public:
        Integer_node(int value): Base_node{node_type::INTEGER}, value_{value} {}

        int process_node() override { return value_; }
};

class Id_node final: public Base_node {

    std::string name_;
    Var* var_;

    public:

        Id_node(std::string &name, Var* var) : Base_node{node_type::ID}, name_{name}, var_{var} {}
        int process_node() override;
        void assign_value(int value);
};

class Scope_node final : public Base_node {

    std::vector<Base_node *> branches_;
    Scope_node *prev_;
    Symtab *table_;

    public:
        
        Scope_node(Scope_node *prev) : Base_node{node_type::SCOPE}, branches_{},
                                      prev_{prev}, table_{} {}

        int process_node() override;
        Var* lookup(const std::string& name) const;
        void emplace(const std::string& name, Var* var) { table_->emplace(name, var); }
        Scope_node* reset_scope();
        void add_branch(Base_node* node);
};

class Bin_op_node final : public Base_node {

    bin_op_type b_type_;
    Base_node* first_;
    Base_node* second_;

    public:

        Bin_op_node(bin_op_type b_type, Base_node* first, Base_node* second) :
                    Base_node{node_type::BIN_OP}, b_type_{b_type}, first_{first}, second_{second} 
        {
            if (first_ == nullptr || second_ == nullptr)
            {
                throw std::runtime_error("The binary operator has no argument (nullptr)!");
            }
        }

        int process_node() override;

};

class Un_op_node final : public Base_node {

    un_op_type un_node_;
    Base_node* first_;

    public:
        Un_op_node(un_op_type un_node, Base_node* first) :
                    Base_node{node_type::UN_OP}, un_node_{un_node}, first_{first}
        {
            if (first_ == nullptr)
            {
                throw std::runtime_error("The unary operator has no argument (nullptr)!");
            }
        }
        int process_node() override;
};

class If_node final : public Base_node {

    Base_node* condition_;
    Base_node* then_expr_;
    Base_node* else_expr_;

    public:
        If_node(Base_node* condition, Base_node* then_expr, Base_node* else_expr = nullptr) :
                    Base_node{node_type::IF}, condition_{condition}, 
                    then_expr_{then_expr}, else_expr_{else_expr} {}
        
        int process_node() override;

};

class While_node final : public Base_node {

    Base_node* condition_;
    Base_node* then_expr_;

    public:
        While_node(Base_node* condition, Base_node* then_expr) :
                    Base_node{node_type::WHILE}, condition_{condition}, then_expr_{then_expr} {}

        int process_node() override;

};

}

#endif
