#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
    private:
        std::string name;
    protected:
        static const unsigned int dt_hp = ft_hp;
        static const unsigned int dt_ep = st_ep;
        static const unsigned int dt_ad = ft_ad;
    public:
        DiamondTrap();
        DiamondTrap(std::string name);
        DiamondTrap(DiamondTrap const &f);
        ~DiamondTrap();
        DiamondTrap&      operator=(DiamondTrap const &fxp);
        void whoAmI(void);
};

#endif