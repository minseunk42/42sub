#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{

Dog* j = new Dog();
j->brain->addIdeas("11");
Dog* jc = new Dog(*j);
j->brain->addIdeas("22");
std::cout << j->brain->getIdeas() << " " << std::endl;
std::cout << jc->brain->getIdeas() << " " << std::endl;
delete j;
delete jc;

return 0;
}