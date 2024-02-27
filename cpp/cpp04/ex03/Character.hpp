#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"
# include "Ice.hpp"
# include "Cure.hpp"
# include <iostream>

class Character : public ICharacter
{
    private:
        std::string name;
        AMateria    *inven[4];
        static const int   MAX_INVEN = 4;
        Character();
    public:
        Character(std::string name);
        Character(Character const &ref);
        Character&  operator=(Character const &ref);
        ~Character();
    public:
        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};

#endif