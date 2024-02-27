#include "Cure.hpp"

Cure::Cure()
{
    std::cout << "Cure 기본생성자 호출" << std::endl;
    this->type = "cure";
    this->cloned = 0;
}

Cure::~Cure()
{
    std::cout << "Cure 소멸자 호출" << std::endl;
    if (this->cloned)
        delete this->cloned;
}

Cure::Cure(Cure const &ref) : AMateria(ref)
{
    std::cout << "Cure 복사생성자 호출" << std::endl;
}

Cure&      Cure::operator=(Cure const &ref)
{
    std::cout << "Cure 복사대입 연산자 호출" << std::endl;
    if (this == &ref)
        return *this;
    AMateria:: operator=(ref);
    return *this;
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

AMateria* Cure::clone() const
{
    return (new Cure());
}
