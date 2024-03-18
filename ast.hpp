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
    virtual void dump() const = 0;
    virtual ~iNode(){}

    virtual double eval() const = 0;
    // friend double dump(std::shared_ptr<iNode> node) {
    //     if (node == nullptr) return 0.0;
    //     eval(node->left_);
    //     node->dump();
    //     eval(node->left_);         
    // }
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
    void dump() const override {
        std::string name;
        switch (op_)
        {
            case op_t::PLUS:
                name = "PLUS";
                break;
            case op_t::MINUS:
                name = "MINUS";
            break;
            default:
                break;
        }
        std::cout << "OP: " << name << std::endl;
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
    void dump() const override {
        std::cout << "Number: " << value_ << std::endl;
    }
};

inline double eval(std::shared_ptr<iNode> node) {
    if (node == nullptr)
        return 0.0; 
    return node->eval(); 
}

inline std::shared_ptr<iNode> newOp(op_t type, std::shared_ptr<iNode> left, std::shared_ptr<iNode> right) {
    return std::make_shared<opNode>(type, left, right);
}

inline std::shared_ptr<iNode> newNumber(int value) {
    return std::make_shared<numNode>(value);
}
