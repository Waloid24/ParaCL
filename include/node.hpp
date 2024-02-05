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

class Base_node {

    public:
        Base_node() {}
        virtual ~Base_node() {};
        virtual int process_node() = 0;

};

class Integer_node : public Base_node {

    int value_;

    public:
        Integer_node(int value): value_{value} {}

        int process_node() override
        {
            return value_;
        }
};

class Id_node : public Base_node {
    
    name_;

    public:

        int process_node() override 
        {
            if (!driver->find_name(name_))
            {
                driver->insert(name_);
            }
            else
            {
                
            }
        }

};

class Scope_node : public Base_node {

    std::vector<Base_node *> instructions;
    Scope_node *prev_;
    Symtab *table_;

    public:
        
        Scope_node(Scope_node *prev): Base_node{node_type::SCOPE}, instructions{},
                                      prev_{prev}, table_{} {};

        void push(const Base_node *node)
        {
            instructions.push(node);
        }

        void reset_scope()
        {
            return prev_;
        }

};


}

#endif
