#pragma once

#include <vector>
#include <memory>
#include <algorithm>
#include <ctime> 
#include <cstdlib>

class Variable {
    public:
    std::string name;
    int value;
    int key; // unique int
    // line? 

    Variable(const std::string& n, int v1, int v2) : name(n), value(v1), key(v2) {}
};

class ScopeNode final {
    private:
    std::vector<std::shared_ptr<Variable>> variableTable;
    std::vector<std::shared_ptr<ScopeNode>> successorsVector;
    std::weak_ptr<ScopeNode> predessorPtr;

    public:
    ScopeNode() {
        variableTable = std::vector<std::shared_ptr<Variable>>();
        successorsVector = std::vector<std::shared_ptr<ScopeNode>>();
        predessorPtr = std::weak_ptr<ScopeNode>();
    }
    
    void add_branch(std::shared_ptr<ScopeNode>& currentScopePtr) {
        auto newScope = std::shared_ptr<ScopeNode>(new ScopeNode());
        currentScopePtr->successorsVector.push_back(newScope);
        currentScopePtr = newScope;
    }

    void exit_scope(std::shared_ptr<ScopeNode>& currentScopePtr) {
        currentScopePtr = predessorPtr.lock();
    }
    
    int add_variable(std::shared_ptr<ScopeNode>& currentScopePtr, std::string variable, int value) {
        //чекаю видимость (со всеми родительскими обл видимости) 
        //если не видима -> добавляю в таблицу символов конкретной обл видимости
        if(check_visibility(variable, currentScopePtr)) {
            for(const auto& var: currentScopePtr->variableTable) {
                if(var->name == variable) {
                    return var->key;
                }
            }
        }
        else {
            
            std::srand(static_cast<unsigned int>(std::time(nullptr)));
            int newKey;
            bool keyExists;

            do {
                newKey = std::rand(); 
                
                keyExists = false;
                for(const auto& var : currentScopePtr->variableTable) {
                    if(var->key == newKey) {
                        keyExists = true;
                        break;
                    }
                }
            } while(keyExists);

            currentScopePtr->variableTable.push_back(std::make_shared<Variable>(variable, value, newKey));
            return newKey;
        } 
    }
// check_visibility и check_variable отличаются тем что в check_visibility проверяются текущий scope 
// и родительские вплоть до глобального
    bool check_visibility(std::string variable, std::shared_ptr<ScopeNode>& currentScopePtr) {
        //for с поиском по ключу
        while(currentScopePtr->predessorPtr.lock() != nullptr) {
            for(const auto& var: currentScopePtr->variableTable) {
                if(var->name == variable) {
                    return true;
                }
            }
            currentScopePtr = predessorPtr.lock();
        }
        return false;
    }



};