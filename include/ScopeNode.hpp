#pragma once

#include <vector>
#include <memory>

#include "Symtab.hpp"

class ScopeNode final : public std::enable_shared_from_this<ScopeNode> {
    public:
    std::vector<std::shared_ptr<Variable>> variableTable;
    std::vector<std::shared_ptr<ScopeNode>> successorsVector;
    std::weak_ptr<ScopeNode> predessorPtr;

    ScopeNode(std::shared_ptr<ScopeNode> curScope) {
        
        variableTable = std::vector<std::shared_ptr<Variable>>();
        successorsVector = std::vector<std::shared_ptr<ScopeNode>>();
        
        predessorPtr = curScope;
    };

    void pushToSuccessors(std::shared_ptr<ScopeNode> childScope)
    {
        successorsVector.push_back(childScope);
    }

    std::shared_ptr<ScopeNode> exit_scope();
    int getIdFromSetVariable(const std::string name);
    int getIdFromGetVariable(const std::string name);
    std::shared_ptr<Variable> lookup(const std::string name); 
    std::shared_ptr<Variable> lookup(int id);
};

