#ifndef SYMTAB_HPP
#define SYMTAB_HPP

#include <unordered_map>
#include <utility>

class Var final {

    int value_;

    public:
        Var(int value) : value_{value} {}
        void change_value(int value) { value_ = value; }
};

class Symtab {

    std::unordered_map<std::string, Var*> syms_;

    public:

        Symtab(){}

        Var* lookup(const std::string &name) const;

        void emplace(const std::string &name, const Var* var)
        {
            syms_.emplace(std::make_pair(name, var));
        }

        void change_value(const Var);        
};

#endif