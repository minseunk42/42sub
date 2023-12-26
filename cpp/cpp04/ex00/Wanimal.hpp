#ifndef WANIMAL_HPP
# define WANIMAL_HPP

# include <iostream>

class Wanimal
{
    protected:
        std::string type;
    public:
        Wanimal();
        virtual ~Wanimal();
        Wanimal(Wanimal const &ref);
        Wanimal&      operator=(Wanimal const &ref);
        std::string getType() const;
        void    makeSound() const;
};

#endif