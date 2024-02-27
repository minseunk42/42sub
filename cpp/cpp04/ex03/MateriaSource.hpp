#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria    *msrc[4];
        AMateria    *srcs[4];
        static const int   MAX_SRC = 4;
    public:
        MateriaSource();
        ~MateriaSource();
        MateriaSource(MateriaSource const &ref);
        MateriaSource&  operator=(MateriaSource const &ref);
    public:
        void        learnMateria(AMateria*);
        AMateria*   createMateria(std::string const & type);
};

#endif