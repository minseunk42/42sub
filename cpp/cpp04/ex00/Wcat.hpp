#ifndef WCAT_HPP
# define WCAT_HPP

# include "Wanimal.hpp"

class Wcat : public Wanimal
{
    public :
        Wcat();
        virtual ~Wcat();
        Wcat(Wcat const &ref);
        Wcat&      operator=(Wcat const &ref);
        void makeSound() const;
};

#endif