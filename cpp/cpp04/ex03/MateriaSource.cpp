#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    std::cout << "MateriaSource 기본생성자 호출" << std::endl;
    for (int i = 0; i < MAX_SRC; i++)
    {
        this->srcs[i] = 0;
        this->msrc[i] = 0;
    }
}

MateriaSource::~MateriaSource()
{
    std::cout << "MateriaSource 소멸자 호출" << std::endl;
    for (int i = 0; i < MAX_SRC; i++)
    {
        if (srcs[i])
            delete srcs[i];
    }
}

MateriaSource::MateriaSource(MateriaSource const &ref)
{
    std::cout << "MateriaSource 복사생성자 호출" << std::endl;
    (void)ref;
}

MateriaSource&      MateriaSource::operator=(MateriaSource const &ref)
{
    std::cout << "MateriaSource 복사대입 연산자 호출" << std::endl;
    if (this == &ref)
        return *this;
    return *this;
}


void        MateriaSource::learnMateria(AMateria* m)
{
    if (!m)
        return;
    for (int i = 0; i < MAX_SRC; i++)
    {
        if (!msrc[i])
        {
            srcs[i] = m;
            msrc[i] = m->clone();
            m->setCloned(msrc[i]);
            break;
        }
    }
}

AMateria*   MateriaSource::createMateria(std::string const & type)
{
    AMateria *out = 0;
    for (int i = 0; i < MAX_SRC; i++)
    {
        if (msrc[i]->getType() == type)
        {
            out = msrc[i]->clone();
            msrc[i]->setCloned(out);
            break;
        }
    }
    return (out);
}

