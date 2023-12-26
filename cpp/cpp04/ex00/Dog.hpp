#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
    public :
        Dog();
        virtual ~Dog();
        Dog(Dog const &ref);
        Dog&      operator=(Dog const &ref);
        void makeSound() const;
};

#endif