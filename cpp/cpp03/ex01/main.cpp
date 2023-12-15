#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ClapTrap c1 = ClapTrap("c1");
    ScavTrap s1 = ScavTrap("s1");
    ScavTrap s2 = ScavTrap("s2");

    s1.attack("c1");
    c1.takeDamage(s1.get_attack_damage());
    c1.beRepaired(1);
    c1.attack("p1");
    s1.attack("s2");
    s2.takeDamage(s1.get_attack_damage());
    s2.attack("s1");
    s1.takeDamage(s2.get_attack_damage());
    s1.attack("s2");
    s2.takeDamage(s1.get_attack_damage());
    s1.attack("s2");
    s2.takeDamage(s1.get_attack_damage());
    s1.attack("s2");
    s2.takeDamage(s1.get_attack_damage());
    s2.beRepaired(1);
    s1.attack("s2");
    s2.takeDamage(s1.get_attack_damage());
    s2.beRepaired(1);
    s1.attack("s2");
    s2.takeDamage(s1.get_attack_damage());
    s2.beRepaired(1);
}