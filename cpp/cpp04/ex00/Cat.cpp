#include "Cat.hpp"
#include "Animal.hpp"

Cat::Cat()
{
    std::cout << "Cat 기본생성자 호출" << std::endl;
    this->type = "Cat";
}

Cat::~Cat()
{
    std::cout << "Cat 소멸자 호출" << std::endl;
}

Cat::Cat(Cat const &ref) : Animal(ref)
{
    std::cout << "Cat 복사생성자 호출" << std::endl;
}

Cat&      Cat::operator=(Cat const &ref)
{
    std::cout << "Cat 복사대입 연산자 호출" << std::endl;
    Animal:: operator=(ref);
    return *this;
}

void    Cat::makeSound() const
{
    std::cout << "야옹" << std::endl;    
}