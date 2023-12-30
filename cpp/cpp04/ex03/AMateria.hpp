#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <string>

class AMateria
{
    protected:
        std::string type;
    public:
        AMateria();
        ~AMateria();
        AMateria(AMateria const &ref);
        AMateria&  operator=(AMateria const &ref);
        AMateria(std::string const & type);
        std::string const & getType() const; //Returns the materia type
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

#endif