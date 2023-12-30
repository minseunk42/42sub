#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : AMateria
{
    private:
    public:
        Ice();
        Ice(Ice const &ref);
        ~Ice();
        Ice&  operator=(Ice const &ref);
};

#endif