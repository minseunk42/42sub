#include "Zombie.hpp"

void Zombie::announce( void )
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string Zombie::get_name() const { return name; }

void Zombie::set_name(const std::string &name) {
 this->name = name; 
}

Zombie::Zombie(std::string name)
{
    this->name = name;
}

Zombie::~Zombie()
{
    std::cout << "zombie " << this->name << " is dead" << std::endl;
}