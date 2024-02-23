#pragma once

#include "ASTNode.hpp"

#include <vector>
#include <memory>
#include <algorithm>
#include <ctime> 
#include <cstdlib>
#include <iostream>

#include "Symtab.hpp"

extern std::ofstream dump_file;
int UNDECLARED_VAR = -1; 

class ScopeNode final : public std::enable_shared_from_this<ScopeNode> {
    private:
    std::vector<std::shared_ptr<Variable>> variableTable;
    std::vector<std::shared_ptr<ScopeNode>> successorsVector;
    std::weak_ptr<ScopeNode> predessorPtr;

    static int variableId;

    public:
    ScopeNode(std::shared_ptr<ScopeNode> curScope) {
        variableTable = std::vector<std::shared_ptr<Variable>>();
        successorsVector = std::vector<std::shared_ptr<ScopeNode>>();
        predessorPtr = curScope;
        predessorPtr.lock()->successorsVector.push_back(shared_from_this());
    }

    std::shared_ptr<ScopeNode> exit_scope();
    int getIdFromSetVariable(const std::string name);
    int getIdFromGetVariable(const std::string name);
    std::shared_ptr<Variable> lookup(const std::string name); 
    void assign_value(int id, int value);
};

//---------------------------------------------------------
std::shared_ptr<ScopeNode> ScopeNode::exit_scope() {
    return predessorPtr.lock();
}

int ScopeNode::getIdFromSetVariable(const std::string name) {
    // ищем в таблице - lookup
    // не нашли тогда добавлем, если нашли вернуть id
    auto variable = predessorPtr.lock()->lookup(name);
    if(variable != nullptr) {
        return variable->id;
    }
    else {
        std::shared_ptr<Variable> variable = std::make_shared<Variable>(name, 0, ScopeNode::variableId++);
        variableTable.push_back(variable);
        return 0;
    }
}

int ScopeNode::getIdFromGetVariable(const std::string name) {
    // ищем в таблице
    // не нашли -> ошибка
    // если нашли - вернуть id
    auto variable = predessorPtr.lock()->lookup(name);
    if(variable != nullptr) {
        return variable->id;
    }
    else {
        std::cout << "undeclared variable error" << std::endl;
        return UNDECLARED_VAR;
    }
}

std::shared_ptr<Variable> ScopeNode::lookup(const std::string name) {
    for(auto && var: variableTable) {
        if(var->name == name) {
            return var;
        }
    }
    if (!predessorPtr.expired()) {
        if (auto predessor = predessorPtr.lock()) {
            return predessor->lookup(name);
        }
    }
    return nullptr;
    // ищет в кокретном scope и потом вызывает себя рекурсино для всех predessors
}

void ScopeNode::assign_value(int id, int value) {
    for(auto && var: variableTable) {
        if(var->id == id) {
            var->value = value;
        }
    }
}