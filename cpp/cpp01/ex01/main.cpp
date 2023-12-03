#include "Zombie.hpp"
#include <stdlib.h>

int main()
{
    Zombie *zh;
    int     N = 10;

    zh = zombieHorde(N, "zombie");
    zh[5].announce();
    zh[9].announce();
    delete[]zh;
}
