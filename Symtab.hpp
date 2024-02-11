#pragma once

#include <stack>
#include <unordered_map>
#include <string>

struct Symbol {
    std::string name;
    std::string type;
    int address;
};

class ScopeManager {
private:
    std::stack<std::unordered_map<std::string, Symbol>> symbolTables;

public:
    void enterScope() {
        symbolTables.push(std::unordered_map<std::string, Symbol>());
    }

    void exitScope() {
        if (!symbolTables.empty()) {
            symbolTables.pop();
        }
    }

    void insertSymbol(const std::string& name, const std::string& type, int address) {
        if (!symbolTables.empty()) {
            Symbol newSymbol = {name, type, address};
            symbolTables.top()[name] = newSymbol;
        }
    }

    Symbol* lookupSymbol(const std::string& name) {
        while (!symbolTables.empty()) {
            auto& symbolTable = symbolTables.top();
            for (auto& symbol : symbolTable) {
                if (symbol.first == name) {
                    return &symbol.second;
                }
            }
            symbolTables.pop();
        }
        return nullptr;
    }
};

