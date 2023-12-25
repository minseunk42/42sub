#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "animal기본생성자 호출" << std::endl;
    this->type = "...";
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

std::string Animal::getType() const{return this->type;}

void    Animal::makeSound()
{
    std::cout << "..." << std::endl;    
}