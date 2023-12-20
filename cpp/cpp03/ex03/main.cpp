#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap d1 = DiamondTrap("d1");
    
    std::cout << "hp : " << d1.get_hit_point() << std::endl;
    std::cout << "dmg : " << d1.get_attack_damage() << std::endl;
    std::cout << "eng : " << d1.get_energy_point() << std::endl;
    d1.attack("empty space");
    d1.whoAmI();
}
