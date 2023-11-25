#include "Zombie.hpp"

void randomChump( std::string name )
{
    Zombie ztemp(name);
    ztemp.announce();
}