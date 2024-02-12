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
    SCOPE,
    FUNC_BASE
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
    U_MINUS,
    NOT
};

enum class func_type {
    INPUT,
    OUTPUT
};

class Base_node {

    node_type n_type_;

    public:
        Base_node(node_type n_type) : n_type_{n_type} {}
        virtual ~Base_node() {};
        virtual int process_node() = 0;
        node_type get_type() { return n_type_; }

};

class Integer_node final : public Base_node {

    int value_;

    public:
        Integer_node(int value): Base_node{node_type::INTEGER}, value_{value} {}
        ~Integer_node(){};
        int process_node() override { return value_; }
};

class Id_node final: public Base_node {

    std::string name_;
    Var* var_;

    public:

        Id_node(std::string &name, Var* var) : Base_node{node_type::ID}, name_{name}, var_{var} {}
        ~Id_node(){}
        int process_node() override { return var_->value_; }
        void assign_value(int value);
};

class Scope_node final : public Base_node {

    std::vector<Base_node *> branches_;
    Scope_node *prev_;
    Symtab *table_;

    public:
        
        Scope_node(Scope_node *prev) : Base_node{node_type::SCOPE}, branches_{},
                                      prev_{prev}, table_{new Symtab} {}
        ~Scope_node();

        int process_node() override;
        Var* lookup(const std::string& name) const;
        void emplace(const std::string& name, Var* var) { table_->emplace(name, var); }
        Scope_node* reset_scope() { return prev_; }
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
        ~Bin_op_node(){}

        int process_node() override;
        Base_node* get_left_node() { return first_; }
        Base_node* get_right_node() { return second_; }

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
        ~Un_op_node(){}
        int process_node() override;
        Base_node* get_left_node() { return first_; }
};

class If_node final : public Base_node {

    Base_node* condition_;
    Base_node* then_expr_;
    Base_node* else_expr_;

    public:
        If_node(Base_node* condition, Base_node* then_expr, Base_node* else_expr = nullptr) :
                    Base_node{node_type::IF}, condition_{condition}, 
                    then_expr_{then_expr}, else_expr_{else_expr} {}
        
        ~If_node();
        int process_node() override;
};

class While_node final : public Base_node {

    Base_node* condition_;
    Base_node* then_expr_;

    public:
        While_node(Base_node* condition, Base_node* then_expr) :
                    Base_node{node_type::WHILE}, condition_{condition}, then_expr_{then_expr} {}

        int process_node() override;
        ~While_node();
};

class Func_node final : public Base_node {

    func_type f_type_;
    Base_node* expr_;

    public:
        Func_node(func_type f_type) : 
                        Base_node{node_type::FUNC_BASE}, f_type_{f_type}, expr_{nullptr} {}
        Func_node(func_type f_type, Base_node* expr) : 
                        Base_node{node_type::FUNC_BASE}, f_type_{f_type}, expr_{expr} {}
        ~Func_node();
        int process_node() override;
};

}

#endif
