#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
    protected:
        static const unsigned int ft_hp = 100;
        static const unsigned int ft_ep = 100;
        static const unsigned int ft_ad = 30;
    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(FragTrap const &f);
        ~FragTrap();
        FragTrap&      operator=(FragTrap const &fxp);
        void highFivesGuys(void);
};

#endif