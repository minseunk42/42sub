#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURE_HPP

class AMateria;
#include <string>

class IMateriaSource
{
    public:
    virtual ~IMateriaSource() {}
    virtual void learnMateria(AMateria*) = 0;
    virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif