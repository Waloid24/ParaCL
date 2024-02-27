#pragma once

#include <vector>
#include <memory>

#include "Symtab.hpp"

class ScopeNode final : public std::enable_shared_from_this<ScopeNode> {
    public:
    std::vector<std::shared_ptr<Variable>> variableTable;
    std::vector<std::shared_ptr<ScopeNode>> successorsVector;
    std::weak_ptr<ScopeNode> predessorPtr;

    static int variableId;

    public:
    ScopeNode(std::shared_ptr<ScopeNode> curScope) {
        
        variableTable = std::vector<std::shared_ptr<Variable>>();
        successorsVector = std::vector<std::shared_ptr<ScopeNode>>();
        predessorPtr = curScope;
        
        if (curScope) {
            predessorPtr.lock()->successorsVector.push_back(shared_from_this());
        }

        // std::cout << "ScopeNode Ctor" << std::endl;
    };

    std::shared_ptr<ScopeNode> exit_scope();
    int getIdFromSetVariable(const std::string name);
    int getIdFromGetVariable(const std::string name);
    std::shared_ptr<Variable> lookup(const std::string name); 
    void assign_value(int id, int value);
};

