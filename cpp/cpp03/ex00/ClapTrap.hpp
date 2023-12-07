#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
    private:
        std::string name;
        int         hit_point;
        int         energy_point;
        int         attack_damage;
        ClapTrap();
    public:
        ClapTrap(std::string name);
        ClapTrap(ClapTrap const &f);
        ~ClapTrap();
        ClapTrap&      operator=(ClapTrap const &fxp);
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif