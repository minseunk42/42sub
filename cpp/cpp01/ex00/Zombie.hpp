#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
private:
    std::string name;
public:
    Zombie(std::string name);
    ~Zombie();
	std::string get_name() const;
	void set_name(const std::string &name);
    void announce( void );
};

Zombie* newZombie( std::string name );
void    randomChump( std::string name );

#endif