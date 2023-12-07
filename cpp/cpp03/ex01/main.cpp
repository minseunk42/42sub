#include "ClapTrap.hpp"

int main()
{
    ClapTrap p1 = ClapTrap("p1");
    ClapTrap p2 = ClapTrap("p2");
    p1.attack("p2");
    p1.attack("p2");
    p1.attack("p2");
    p1.attack("p2");
    p1.attack("p2");
    p1.attack("p2");
    p1.attack("p2");
    p1.attack("p2");
    p1.attack("p2");
    p1.attack("p2");
    p1.attack("p2");
    p2.takeDamage(9);
    p2.beRepaired(1);
    p2.attack("p1");
    p2.takeDamage(2);
    p2.attack("p1");
}