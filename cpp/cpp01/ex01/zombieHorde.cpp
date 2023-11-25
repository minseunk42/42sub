#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie *zh = new Zombie[N];
    std::stringstream ss;

    for(int i = 0; i < N; i++)
    {
        ss << i;
        zh[i].set_name(name + ss.str());
        ss.str("");
    }
    return (&zh[0]);
}