#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
Animal* i = new Cat();
std::cout << meta->getType() << " " << std::endl;
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound();
meta->makeSound();

delete meta;
delete j;
delete i;

std::cout << "-----wrong test-----" << std::endl;

const WrongAnimal* wmeta = new WrongAnimal();
WrongAnimal* wi = new WrongCat();
std::cout << wmeta->getType() << " " << std::endl;
std::cout << wi->getType() << " " << std::endl;
wi->makeSound(); //will output the wrong_cat sound!
wmeta->makeSound();

delete wmeta;
delete wi;

return 0;
}