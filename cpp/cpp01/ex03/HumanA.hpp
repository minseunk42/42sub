#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanA
{
    private:
        Weapon &wp;
        std::string name;
        HumanA();
    public:
        HumanA(std::string name, Weapon &wp);
        void attack();
};

#endif
