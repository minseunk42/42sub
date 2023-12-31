#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "animal 기본생성자 호출" << std::endl;
    this->type = "Animal";
}

Animal::~Animal()
{
    std::cout << "animal 소멸자 호출" << std::endl;
}

Animal::Animal(Animal const &ref)
{
    std::cout << "animal 복사생성자 호출" << std::endl;
    this->type = ref.type;
}

Animal&      Animal::operator=(Animal const &ref)
{
    std::cout << "animal 복사대입 연산자 호출" << std::endl;
    this->type = ref.type;
    return *this;
}

std::string Animal::getType() const{return this->type;}