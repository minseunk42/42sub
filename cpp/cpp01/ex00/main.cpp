#include "Zombie.hpp"

int main()
{
    randomChump("zombie_st");

    Zombie  *zh = newZombie("zombie_hp");
    zh->announce();
    delete zh;
}
