#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
    protected:
        std::string name;
        int         hit_point;
        int         energy_point;
        int         attack_damage;
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(ClapTrap const &f);
        virtual ~ClapTrap();
        ClapTrap&      operator=(ClapTrap const &fxp);
        virtual void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        int get_hit_point(void) const;
        int get_energy_point(void) const;
        int get_attack_damage(void) const;
};

#endif