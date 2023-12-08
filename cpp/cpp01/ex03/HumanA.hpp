#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanA
{
    private:
        std::string name;
        Weapon &wp;
    public:
        HumanA(std::string name, Weapon &wp);
        void attack();
};

#endif
