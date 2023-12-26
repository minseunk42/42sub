#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "animal기본생성자 호출" << std::endl;
    this->type = "Animal";
}

Animal::~Animal()
{
    std::cout << "animal소멸자 호출" << std::endl;
}

Animal::Animal(Animal const &ref)
{
    std::cout << "animal복사생성자 호출" << std::endl;
    this->type = ref.type;
}

Animal&      Animal::operator=(Animal const &ref)
{
    std::cout << "animal복사대입 생성자 호출" << std::endl;
    this->type = ref.type;
    return *this;
}

void    Animal::makeSound() const
{
    std::cout << "...(animal)" << std::endl;    
}

std::string Animal::getType() const{return this->type;}