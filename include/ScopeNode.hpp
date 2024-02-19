#pragma once

#include "INode.hpp"

#include <vector>
#include <memory>
#include <algorithm>
#include <ctime> 
#include <cstdlib>
#include <iostream>

#include "Symtab.hpp"

extern std::ofstream dump_file;

class ScopeNode final: public INode {
    private:
    std::vector<std::shared_ptr<Variable>> variableTable;
    std::vector<std::shared_ptr<INode>> successorsVector;
    std::weak_ptr<ScopeNode> predessorPtr;

    public:
    ScopeNode() {
        variableTable = std::vector<std::shared_ptr<Variable>>();
        successorsVector = std::vector<std::shared_ptr<INode>>();
        predessorPtr = std::weak_ptr<ScopeNode>();
    }

    inline int calculate();
    inline void dump_ast();
    inline std::shared_ptr<ScopeNode> create_scope();
    inline void add_branch(std::shared_ptr<INode> node);
    inline void exit_scope(std::shared_ptr<ScopeNode>& currentScopePtr);
    inline void add_variable(std::shared_ptr<ScopeNode>& currentScopePtr, std::shared_ptr<Variable> variable);
    inline bool check_in_table(std::shared_ptr<ScopeNode>& currentScopePtr, std::shared_ptr<Variable> variable);
};
//---------------------------------------------------------
inline int ScopeNode::calculate() {
    for(auto && successor: successorsVector) {
        dump_file << "Calculate in current scope" << std::endl;
        return successor->calculate();
    }
    return 0;
}

inline void ScopeNode::dump_ast() {
    for(auto && successor: successorsVector) {
        successor->dump_ast();
    }
    dump_file << "In ScopeNode" << std::endl;
}

inline std::shared_ptr<ScopeNode> ScopeNode::create_scope() {
    return std::make_shared<ScopeNode>();
}

inline void ScopeNode::add_branch(std::shared_ptr<INode> node) {
    successorsVector.push_back(node);
}

inline void ScopeNode::exit_scope(std::shared_ptr<ScopeNode>& currentScopePtr) {
    currentScopePtr = predessorPtr.lock();
}

inline void ScopeNode::add_variable(std::shared_ptr<ScopeNode>& currentScopePtr, std::shared_ptr<Variable> variable) {
    currentScopePtr->variableTable.push_back(std::make_shared<Variable>(variable->name));
}

inline bool ScopeNode::check_in_table(std::shared_ptr<ScopeNode>& currentScopePtr, std::shared_ptr<Variable> variable) {
    while(currentScopePtr->predessorPtr.lock() != nullptr) {
        for(const auto& var: currentScopePtr->variableTable) {
            if(var->name == variable->name) {
                return true;
            }
        }
        currentScopePtr = predessorPtr.lock();
    }
    return false;
}