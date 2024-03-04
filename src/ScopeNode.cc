#include <iostream>

#include "../include/ScopeNode.hpp"

int variableId = 0;
//---------------------------------------------------------
std::shared_ptr<ScopeNode> ScopeNode::exit_scope() {
    return predessorPtr.lock();
}

int ScopeNode::getIdFromSetVariable(const std::string name) {
    auto variable = lookup(name);
    if(variable == nullptr)
    { 
        variableId = variableId + 1;
        variable = std::make_shared<Variable>(name, 0, variableId);
        variableTable.push_back(variable);
    }
    return variable->id;
}

int ScopeNode::getIdFromGetVariable(const std::string name) {
    auto variable = lookup(name);
    if(variable != nullptr) {
        return variable->id;
    }
    else {
        std::cout << "undeclared variable error" << std::endl;
        return -1;
    }
}

std::shared_ptr<Variable> ScopeNode::lookup(const std::string name) {
    for(auto && var: variableTable) {
        if(var->name == name) {
            return var;
        }
    }
    if (predessorPtr.lock() == nullptr) {
        if (auto predessor = predessorPtr.lock()) {
            return predessor->lookup(name);
        }
    }
    return nullptr;
}

std::shared_ptr<Variable> ScopeNode::lookup(int id) {
    for(auto && var: variableTable) {
        if(var->id == id) {
            return var;
        }
    }
    if (predessorPtr.lock() == nullptr) {
        if (auto predessor = predessorPtr.lock()) {
            return predessor->lookup(id);
        }
    }
    return nullptr;
}