#pragma once
#include <iostream>
#include <cmath>
#include <memory>

enum class node_t{
    op,
    number
};

enum class op_t{
    PLUS,
    MINUS
};

class iNode {    
protected:
    std::shared_ptr<iNode> left_;
    std::shared_ptr<iNode> right_;
public:
    iNode(){}
    iNode(std::shared_ptr<iNode> left, std::shared_ptr<iNode> right): 
        left_(left), 
        right_(right) {}
    virtual void dump(int) const = 0;
    virtual ~iNode(){}

    virtual double eval() const = 0;

    friend void dumpTree(std::shared_ptr<iNode> node, int indent) {
        if (node == nullptr) return;   
        dumpTree(node->left_, indent + 4);
        node->dump(indent);
        dumpTree(node->right_, indent + 4);
    }
};

class opNode: public iNode { 
    op_t op_;
public:
    opNode(op_t op, std::shared_ptr<iNode> left, std::shared_ptr<iNode> right): 
        op_(op), 
        iNode(left, right) {}
    double eval() const override {
        double left_value = left_ ? left_->eval(): 0.0;
        double right_value = right_ ? right_->eval(): 0.0;

        switch (op_)
        {
            case op_t::PLUS:
                return left_value + right_value;
            break;
            case op_t::MINUS:
                return left_value - right_value;
            break;
            default:
                return 0.0;
            break;
        }
    }
    void dump(int indent) const override {
        std::cout << std::string(indent, ' ') << "OP: ";
        switch (op_)
        {
            case op_t::PLUS:
                std::cout << "+" << std::endl;
                break;
            case op_t::MINUS:
                std::cout << "-" << std::endl;
            break;
            default:
                break;
        }
    }
};

class numNode: public iNode { 
    int value_;
public:
    numNode(int value): 
        value_(value), 
        iNode(nullptr, nullptr) {}
    double eval() const override {
        return static_cast<double>(value_); 
    }
    void dump(int indent) const override {
        std::cout << std::string(indent, ' ') << "Number: " << value_ << std::endl;
    }
};

inline double eval(std::shared_ptr<iNode> node) {
    if (node == nullptr)
        return 0.0; 
    return node->eval(); 
}

inline std::shared_ptr<iNode> newOp(op_t type, std::shared_ptr<iNode> left, std::shared_ptr<iNode> right) {
    // std::cout << "newOp: " << static_cast<int>(type) << std::endl;
    return std::make_shared<opNode>(type, left, right);
}

inline std::shared_ptr<iNode> newNumber(int value) {
    // std::cout << "newNum: " << value << std::endl;
    return std::make_shared<numNode>(value);
}

