#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>
# include <sstream>

class Zombie
{
private:
    std::string name;
public:
    Zombie(std::string name);
    Zombie();
    ~Zombie();
	std::string get_name() const;
	void set_name(const std::string &name);
    void announce( void );
};

Zombie* zombieHorde( int N, std::string name );

#endif