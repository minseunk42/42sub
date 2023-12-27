#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{

    protected:
        std::string type;
    public:
        Animal();
        virtual ~Animal();
        Animal(Animal const &ref);
        Animal&      operator=(Animal const &ref);
        std::string getType() const;
        virtual void    makeSound() const;
};

#endif