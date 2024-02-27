#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
    protected:
        std::string type;
        AMateria    *cloned;
    public:
        AMateria();
        virtual ~AMateria();
        AMateria(AMateria const &ref);
        AMateria&  operator=(AMateria const &ref);
        AMateria(std::string const & type);
        std::string const & getType() const; //Returns the materia type
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
        AMateria *getCloned();
        void    setCloned(AMateria *cloned);
};

#endif