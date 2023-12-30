#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
    protected:
        std::string type;
    public:
        WrongAnimal();
        virtual ~WrongAnimal();
        WrongAnimal(WrongAnimal const &ref);
        WrongAnimal&      operator=(WrongAnimal const &ref);
        std::string getType() const;
        void    makeSound() const;
};

#endif