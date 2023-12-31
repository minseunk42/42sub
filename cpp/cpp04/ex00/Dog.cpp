#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog 기본생성자 호출" << std::endl;
    this->type = "Dog";
}

Dog::~Dog()
{
    std::cout << "Dog 소멸자 호출" << std::endl;
}

Dog::Dog(Dog const &ref) : Animal(ref)
{
    std::cout << "Dog 복사생성자 호출" << std::endl;
    this->type = ref.type;
}

Dog&      Dog::operator=(Dog const &ref)
{
    std::cout << "Dog 복사대입 연산자 호출" << std::endl;
    Animal:: operator=(ref);
    this->type = ref.type;
    return *this;
}

void    Dog::makeSound() const
{
    std::cout << "멍멍" << std::endl;    
}