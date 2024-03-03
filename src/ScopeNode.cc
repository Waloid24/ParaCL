#include <iostream>

#include "../include/ScopeNode.hpp"

int variableId = 0;
//---------------------------------------------------------
std::shared_ptr<ScopeNode> ScopeNode::exit_scope() {
    return predessorPtr.lock();
}

int ScopeNode::getIdFromSetVariable(const std::string name) {
    std::cout << "var start name: " << name << std::endl;
    auto variable = lookup(name);
    if(variable == nullptr)
    { 
        std::cout << " new variable" << variableId << std::endl;
        variableId = variableId + 1;
        variable = std::make_shared<Variable>(name, 0, variableId);
        variableTable.push_back(variable);
    }
    std::cout <<"var name:" <<variable->name << std::endl;
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

void ScopeNode::assign_value(int id, int value) {
    for(auto && var: variableTable) {
        if(var->id == id) {
            var->value = value;
        }
    }
    std::cout << "Assign value" << std::endl;
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