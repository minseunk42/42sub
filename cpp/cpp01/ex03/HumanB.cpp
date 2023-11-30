#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string name)
{
    this->name = name;
    this->wp = new Weapon("");
    this->is_never_armed = true;
}

HumanB::~HumanB()
{
    if (this->is_never_armed)
        delete this->wp;
}

void HumanB::setWeapon(Weapon &wp)
{
    delete this->wp;
    this->wp = &wp;
    this->is_never_armed = false;
}

void HumanB::attack()
{
    if (this->wp->getType().empty())
        std::cout << this->name << " is unarmed." << std::endl;
    else
        std::cout << this->name << " attacks with their " << this->wp->getType() << std::endl;
}
