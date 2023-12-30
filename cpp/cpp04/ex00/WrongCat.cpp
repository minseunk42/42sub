#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout << "WCat 기본생성자 호출" << std::endl;
    this->type = "WrongCat";
}

WrongCat::~WrongCat()
{
    std::cout << "WCat 소멸자 호출" << std::endl;
}

WrongCat::WrongCat(WrongCat const &ref)
{
    std::cout << "WCat 복사생성자 호출" << std::endl;
    this->type = ref.type;
}

WrongCat&      WrongCat::operator=(WrongCat const &ref)
{
    std::cout << "WCat 복사대입 연산자 호출" << std::endl;
    this->type = ref.type;
    return *this;
}

void    WrongCat::makeSound() const
{
    std::cout << "야옹" << std::endl;    
}