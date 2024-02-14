#include <string>
#include "symtab.hpp"

Var* Symtab::lookup(const std::string &name) const
{
    auto result = syms_.find(name);
    if (result != syms_.end())
        return result->second;
    else
        return nullptr;
}

Symtab::~Symtab()
{
    for (auto pair : syms_)
    {
        if (pair.second != nullptr)
            delete pair.second;
    }
}