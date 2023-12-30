#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
    private:
        Brain *brain;
    public :
        Cat();
        virtual ~Cat();
        Cat(Cat const &ref);
        Cat&      operator=(Cat const &ref);
        void makeSound() const;
        Brain* getBrain() const;
};

#endif