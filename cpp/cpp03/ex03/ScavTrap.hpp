#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
    protected:
        static const unsigned int st_hp = 100;
        static const unsigned int st_ep = 50;
        static const unsigned int st_ad = 20;
    public:
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(ScavTrap const &f);
        ~ScavTrap();
        ScavTrap&      operator=(ScavTrap const &fxp);
        void guardGate();
        void attack(const std::string& target);
        unsigned int get_energy_point(void) const;
};

#endif