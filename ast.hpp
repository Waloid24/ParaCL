#include <iostream>
#include <cmath>
#include <memory>

enum class nodeType{
    op,
    number
};


struct node { 
    nodeType type_; 
    node(nodeType type): type_(type) {}
    void dump() {
        inorder(this);
    }
    node* left_ = nullptr;
    node* right_ = nullptr;
private:
    void inorder(node* node) {
        if (node == nullptr) return;

        inorder(node->left_);
        std::cout << static_cast<int>(node->type_) << ' ';
        inorder(node->right_);
    }
};



// enum class opType{
//     PLUS,
//     MINUS,
//     MULT,
//     DIVIDE
// };

// class iNode;

// class ast {
//     std::unique_ptr<iNode> left_;
//     std::unique_ptr<iNode> right_;
// public:
//     ast(){}
//     void insert_left(std::unique_ptr<iNode> node) {
//         // left_ = std::make_unique<iNode>(node);
//         left_ = std::move(node);
//     }
//     void insert_right(std::unique_ptr<iNode> node) {
//         right_ = std::move(node);
//     }
// };


// class iNode {
// public:
//     virtual ~iNode(){}
// };

// class numNode;

// class opNode: public iNode {
//     opType opType_;
//     std::unique_ptr<iNode> left_;
//     std::unique_ptr<iNode> right_;
// public:
//     opNode(opType type, std::unique_ptr<iNode> left, std::unique_ptr<iNode> right): 
//     opType_(type), left_(std::make_unique<iNode>(left)), right_(std::make_unique<iNode>(right)) {}
// };


// class numNode: public iNode {
//     double val_ = NAN;
// public:
//     numNode(double val): val_(val) {}
// };