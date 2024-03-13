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

    friend void eval(std::shared_ptr<iNode> node) {
        if (node == nullptr) return;

        eval(node->left_);
        node->dump();
        // std::cout << static_cast<int>(node->type_) << ' ';
        eval(node->right_);
    }
};

class opNode: public iNode { 
    op_t op_;
public:
    opNode(op_t op, std::shared_ptr<iNode> left, std::shared_ptr<iNode> right): 
        op_(op), 
        iNode(left, right) {}
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
    void dump() const override {
        std::cout << "Number: " << value_ << std::endl;
    }
};

std::shared_ptr<iNode> newOp(op_t type, std::shared_ptr<iNode> left, std::shared_ptr<iNode> right) {
    return std::make_shared<opNode>(type, left, right);
}


std::shared_ptr<iNode> newNumber(int value) {
    return std::make_shared<numNode>(value);
}
