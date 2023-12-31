#include "Dog.hpp"
#include "Animal.hpp"

Dog::Dog()
{
    std::cout << "Dog 기본생성자 호출" << std::endl;
    this->type = "Dog";
    this->brain = new Brain();
}

Dog::~Dog()
{
    std::cout << "Dog 소멸자 호출" << std::endl;
    delete this->brain;
}

Dog::Dog(Dog const &ref) : Animal(ref)
{
    std::cout << "Dog 복사생성자 호출" << std::endl;
    this->type = ref.type;
    this->brain = new Brain(*(ref.getBrain()));
}

Dog&      Dog::operator=(Dog const &ref)
{
    std::cout << "Dog 복사대입 연산자 호출" << std::endl;
    Animal:: operator=(ref);
    this->type = ref.type;
    delete this->brain;
    this->brain = new Brain(*(ref.getBrain()));
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