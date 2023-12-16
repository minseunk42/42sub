#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(FragTrap const &f);
        ~FragTrap();
        FragTrap&      operator=(FragTrap const &fxp);
        void highFivesGuys(void);
};

#endif