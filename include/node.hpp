#ifndef NODE_HPP
#define NODE_HPP

#include "symtab.hpp"

using namespace nodes
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

enum class un_op_node {
    U_PLUS,
    U_MINUS,
    NOT
}

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
        Integer_node(int value): value_{value} {}

        int process_node() override { return value_; }
};

class Var final {

    std::string name_;
    int value_;

    public:
        Var(std::string name, int value = 0) : name_{name}, value_{value} {}
        void change_value(int value) { value_ = value; }
};

class Id_node final: public Base_node {

    std::string name_;
    Var* var_;

    public:

        Id_node(std::string name, Var* var) : name_{name}, var_{var} {}
        int process_node() override;
        void assign_value();
};

class Scope_node final : public Base_node {

    std::vector<Base_node *> instructions;
    Scope_node *prev_;
    Symtab *table_;

    public:
        
        Scope_node(Scope_node *prev): Base_node{node_type::SCOPE}, instructions{},
                                      prev_{prev}, table_{} {};

        int process_node() override;
        Var* lookup(const std::string& name) const;
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

    un_op_node un_node_;
    Base_node* first_;

    public:
        Un_op_node(un_op_node un_node, Base_node* first) :
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

}

class While_node final : public Base_node {

    Base_node* condition_;
    Base_node* then_expr_;

    public:
        While_node(Base_node* condition, Base_node* then_expr) :
                    condition_{condition}, then_expr_{then_expr} {}

        int process_node() override;

};

}

#endif
