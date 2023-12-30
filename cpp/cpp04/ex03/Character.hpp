#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include <string>

class Character : ICharacter
{
    private:
        std::string name;
    public:
        Character();
        Character(std::string name);
        Character(Character const &ref);
        Character&  operator=(Character const &ref);
        ~Character();

        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};

#endif