#include "Ice.hpp"

Ice::Ice()
{
    std::cout << "Ice 기본생성자 호출" << std::endl;
    this->type = "ice";
    this->cloned = 0;
}

Ice::~Ice()
{
    std::cout << "Ice 소멸자 호출" << std::endl;
    if (this->cloned)
        delete this->cloned;
}

Ice::Ice(Ice const &ref) : AMateria(ref)
{
    std::cout << "Ice 복사생성자 호출" << std::endl;
}

Ice&      Ice::operator=(Ice const &ref)
{
    std::cout << "Ice 복사대입 연산자 호출" << std::endl;
    if (this == &ref)
        return *this;
    AMateria:: operator=(ref);
    return *this;
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria* Ice::clone() const
{
    return new Ice();
}
