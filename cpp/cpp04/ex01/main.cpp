#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return -1;

    if (std::string(av[1]) == "1")
    {
        std::cout << "<basic test>" << std::endl;

        const Animal* j = new Dog();
        const Animal* i = new Cat();
        delete j;//should not create a leak
        delete i;
    }
    else if (std::string(av[1]) == "2")
    {
        std::cout << "<deep copy test>" << std::endl;
        Cat* c1 = new Cat();
        c1->getBrain()->addIdeas("i am cat");
        
        Cat* c2 = new Cat(*c1);
        c1->getBrain()->addIdeas("give me fish");

        std::cout << std::endl << "c1 brain" << std::endl;
        std::cout << c1->getBrain()->getIdeas() << " " << std::endl;
        std::cout << "c2 brain" << std::endl;
        std::cout << c2->getBrain()->getIdeas() << " " << std::endl;
        delete c1;
        delete c2;
    }
    else if (std::string(av[1]) == "3")
    {
        Cat *c = new Cat();
        c->getBrain()->addIdeas("i am cat");
        *c = *c;
        std::cout << c->getBrain()->getIdeas() << " " << std::endl;
        delete c;
    }
    else
    {
        std::cout << "<subtype polymorphism test>" << std::endl;
        Animal *arr[2];
        for (int i = 0; i < 2; i++)
        {
            if (i % 2 == 0)
                arr[i] = new Cat();
            else
                arr[i] = new Dog();
        }
        arr[0]->makeSound();
        arr[1]->makeSound();
        for (int i = 0; i < 2; i++)
            delete arr[i];        
    }
    return 0;
}