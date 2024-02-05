#ifndef SYMTAB_HPP
#define SYMTAB_HPP

#include <unordered_map>

namespace ... {

class Symtab {

    std::unordered_map<Name, Type_name> syms;

    public:

        lookup_name(const Name &name)
        {
            return syms.contains(name);
        }

        
};

}

#endif