#include "Wanimal.hpp"

Wanimal::Wanimal()
{
    std::cout << "Wanimal기본생성자 호출" << std::endl;
    this->type = "Wanimal";
}

Wanimal::~Wanimal()
{
    std::cout << "Wanimal소멸자 호출" << std::endl;
}

Wanimal::Wanimal(Wanimal const &ref)
{
    std::cout << "Wanimal복사생성자 호출" << std::endl;
    this->type = ref.type;
}

Wanimal&      Wanimal::operator=(Wanimal const &ref)
{
    std::cout << "Wanimal복사대입 생성자 호출" << std::endl;
    this->type = ref.type;
    return *this;
}

void    Wanimal::makeSound() const
{
    std::cout << "...(Wanimal)" << std::endl;    
}

std::string Wanimal::getType() const{return this->type;}