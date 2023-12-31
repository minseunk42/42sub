#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
class AMateria;

class MateriaSource : IMateriaSource
{
    private:
    public:
        MateriaSource();
        ~MateriaSource();
        MateriaSource(MateriaSource const &ref);
        MateriaSource&  operator=(MateriaSource const &ref);
    public:
        void    learnMateria(AMateria*);
        AMateria*   createMateria(std::string const & type);
};

#endif