#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
    private:
        Brain *brain;
    public :
        Dog();
        virtual ~Dog();
        Dog(Dog const &ref);
        Dog&      operator=(Dog const &ref);
        void makeSound() const;
        Brain* getBrain() const;
};

#endif