#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{

const Dog* j = new Dog();
const Dog  &rj = 

j->brain->addIdeas("11");
Dog* jc = new Dog(rj);
j->brain->addIdeas("22");
std::cout << j->brain->getIdeas() << " " << std::endl;
std::cout << jc->brain->getIdeas() << " " << std::endl;
delete j;

return 0;
}