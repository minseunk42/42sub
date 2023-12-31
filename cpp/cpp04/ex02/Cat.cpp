#include "Cat.hpp"
#include "Animal.hpp"

Cat::Cat()
{
    std::cout << "Cat 기본생성자 호출" << std::endl;
    this->type = "Cat";
    this->brain = new Brain();
}

Cat::~Cat()
{
    std::cout << "Cat 소멸자 호출" << std::endl;
    delete this->brain;
}

Cat::Cat(Cat const &ref) : Animal(ref)
{
    std::cout << "Cat 복사생성자 호출" << std::endl;
    this->type = ref.type;
    this->brain = new Brain(*(ref.getBrain()));
}

Cat&      Cat::operator=(Cat const &ref)
{
    std::cout << "Cat 복사대입 연산자 호출" << std::endl;
    Animal:: operator=(ref);
    this->type = ref.type;
    delete this->brain;
    this->brain = new Brain(*(ref.getBrain()));
    return *this;
}

void    Cat::makeSound() const
{
    std::cout << "야옹" << std::endl;    
}

Brain* Cat::getBrain() const
{
    return this->brain;
}