#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal 기본생성자 호출" << std::endl;
    this->type = "WrongAnimal";
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal 소멸자 호출" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &ref)
{
    std::cout << "WrongAnimal 복사생성자 호출" << std::endl;
    this->type = ref.type;
}

WrongAnimal&      WrongAnimal::operator=(WrongAnimal const &ref)
{
    std::cout << "WrongAnimal 복사대입 연산자 호출" << std::endl;
    this->type = ref.type;
    return *this;
}

void    WrongAnimal::makeSound() const
{
    std::cout << "...(WrongAnimal)" << std::endl;    
}

std::string WrongAnimal::getType() const{return this->type;}