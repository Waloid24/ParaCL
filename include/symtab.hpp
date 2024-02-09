#ifndef SYMTAB_HPP
#define SYMTAB_HPP

#include <unordered_map>
#include <utility>

class Var final {

    int value_;

    public:
        Var() : value_{} {}
        Var(int value) : value_{value} {}
        void change_value(int value) { value_ = value; }
};

class Symtab {

    std::unordered_map<std::string, Var*> syms_;

    public:

        Symtab(){}

        Var* lookup(const std::string &name) const;

        void emplace(const std::string &name, Var* var)
        {
            syms_[name] = var;
        }

        void change_value(const Var);        
};

#endif