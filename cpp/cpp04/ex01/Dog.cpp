#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog기본생성자 호출" << std::endl;
    this->type = "Dog";
}

Dog::~Dog()
{
    std::cout << "Dog소멸자 호출" << std::endl;
}

Dog::Dog(Dog const &ref) : Animal(ref)
{
    std::cout << "Dog복사생성자 호출" << std::endl;
    this->type = ref.type;
}

Dog&      Dog::operator=(Dog const &ref)
{
    std::cout << "Dog복사대입 생성자 호출" << std::endl;
    this->type = ref.type;
    return *this;
}

void    Dog::makeSound() const
{
    std::cout << "멍멍" << std::endl;    
}