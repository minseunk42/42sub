#include "AMateria.hpp"

AMateria::AMateria()
{
    std::cout << "AMateria 기본생성자 호출" << std::endl;
    this->type = "AMateria";
}

AMateria::AMateria(std::string const & type)
{
    std::cout << "AMateria 생성자 호출" << std::endl;
    this->type = type;
}

AMateria::~AMateria()
{
    std::cout << "AMateria 소멸자 호출" << std::endl;
}

AMateria::AMateria(AMateria const &ref)
{
    std::cout << "AMateria 복사생성자 호출" << std::endl;
    this->type = ref.type;
}

AMateria&      AMateria::operator=(AMateria const &ref)
{
    std::cout << "AMateria 복사대입 연산자 호출" << std::endl;
    if (this == &ref)
        return *this;
    this->type = ref.type;
    return *this;
}

std::string const & AMateria::getType() const
{
    return this->type;
}

void AMateria::use(ICharacter& target)
{
    (void)target;
    std::cout << "AMateria use" << std::endl;
}

void    AMateria::setCloned(AMateria *cloned)
{
    AMateria* temp = this->cloned;
    if (!temp)
        this->cloned = cloned;
    while (temp != 0)
        temp = this->cloned->cloned;
    temp = cloned;
}

AMateria* AMateria::getCloned()
{
    return (this->cloned);
}
