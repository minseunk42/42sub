#include "Wcat.hpp"

Wcat::Wcat()
{
    std::cout << "Cat기본생성자 호출" << std::endl;
    this->type = "Wcat";
}

Wcat::~Wcat()
{
    std::cout << "Cat소멸자 호출" << std::endl;
}

Wcat::Wcat(Wcat const &ref)
{
    std::cout << "Cat복사생성자 호출" << std::endl;
    this->type = ref.type;
}

Wcat&      Wcat::operator=(Wcat const &ref)
{
    std::cout << "Cat복사대입 생성자 호출" << std::endl;
    this->type = ref.type;
    return *this;
}

void    Wcat::makeSound() const
{
    std::cout << "야옹" << std::endl;    
}