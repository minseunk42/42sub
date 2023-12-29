#include "Dog.hpp"

Dog::Dog() : Animal ()
{
    std::cout << "Dog 기본생성자 호출" << std::endl;
    this->type = "Dog";
    this->brain = new Brain();
}

Dog::~Dog()
{
    std::cout << "Dog소멸자 호출" << std::endl;
    delete this->brain;
}

Dog::Dog(Dog const &ref) : Animal(ref)
{
    std::cout << "Dog복사생성자 호출" << std::endl;
    this->type = ref.type;
    delete this->brain;
    this->brain = new Brain();
    *brain = *ref.brain;
}

Dog&      Dog::operator=(Dog const &ref)
{
    std::cout << "Dog복사대입 생성자 호출" << std::endl;
    this->type = ref.type;
    delete this->brain;
    this->brain = new Brain();
    *brain = *ref.brain;
    return *this;
}

void    Dog::makeSound() const
{
    std::cout << "멍멍" << std::endl;    
}

Brain* Dog::getBrain() const
{
    return this->brain;
}
