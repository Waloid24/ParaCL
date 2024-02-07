#include "../include/symtab.hpp"

Var* Symtab::lookup(const Var &name) const
{
    auto result = syms_.find();
    if (result != syms_.end())
        return *result;
    else
        return nullptr;
}