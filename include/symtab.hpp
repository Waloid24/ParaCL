#ifndef SYMTAB_HPP
#define SYMTAB_HPP

#include <unordered_map>
#include <utility>

namespace ... {

class Symtab {

    std::unordered_map<std::string, Var*> syms_;

    public:

        Var* lookup(const Var &name) const;

        bool emplace(const Var &var, const std::string &name)
        {
            return (syms_.emplace(std::make_pair(name, var))).second;
        }

        change_value(const Var);

        

        
};

}

#endif