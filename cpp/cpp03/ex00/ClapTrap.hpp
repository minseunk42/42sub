#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
    private:
        std::string     name;
        unsigned int    hit_point;
        unsigned int    energy_point;
        unsigned int    attack_damage;
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(ClapTrap const &f);
        ~ClapTrap();
        ClapTrap&      operator=(ClapTrap const &fxp);
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        unsigned int get_hit_point(void) const;
        unsigned int get_energy_point(void) const;
        unsigned int get_attack_damage(void) const;
};

#endif
