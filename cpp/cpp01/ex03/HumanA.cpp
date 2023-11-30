#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &wp) : name(name), wp(wp){}


void HumanA::attack()
{
    if (this->wp.getType().empty())
        std::cout << this->name << " is unarmed." << std::endl;
    else
        std::cout << this->name << " attacks with their " << this->wp.getType() << std::endl;
}
