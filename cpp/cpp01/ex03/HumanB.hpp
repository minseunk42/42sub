#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanB
{
    private:
        Weapon *wp;
        std::string name;
        bool    is_never_armed;
        HumanB();
    public:
        HumanB(std::string name);
        ~HumanB();
        void setWeapon(Weapon &wp);
        void attack();
};

#endif
