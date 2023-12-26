#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat기본생성자 호출" << std::endl;
    this->type = "Cat";
}

Cat::~Cat()
{
    std::cout << "Cat소멸자 호출" << std::endl;
}

Cat::Cat(Cat const &ref)
{
    std::cout << "Cat복사생성자 호출" << std::endl;
    this->type = ref.type;
}

Cat&      Cat::operator=(Cat const &ref)
{
    std::cout << "Cat복사대입 생성자 호출" << std::endl;
    this->type = ref.type;
    return *this;
}

void    Cat::makeSound() const
{
    std::cout << "야옹" << std::endl;    
}