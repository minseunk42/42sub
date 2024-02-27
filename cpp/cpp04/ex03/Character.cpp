#include "Character.hpp"

Character::Character()
{
    std::cout << "Character 기본생성자 호출" << std::endl;
    for (int i = 0; i < MAX_INVEN; i++)
        this->inven[i] = 0;
    this->name = "default";
}

Character::Character(std::string name)
{
    std::cout << "Character 생성자 호출" << std::endl;
    for (int i = 0; i < MAX_INVEN; i++)
        this->inven[i] = 0;
    this->name = name;
}

Character::~Character()
{
    std::cout << "Character 소멸자 호출" << std::endl;
}

Character::Character(Character const &ref)
{
    std::cout << "Character 복사생성자 호출" << std::endl;
    this->name = ref.name;
    for (int i = 0; i < MAX_INVEN; i++)
    {
        if (ref.inven[i])
        {
            inven[i] = ref.inven[i]->clone();
            ref.inven[i]->setCloned(inven[i]);
        }
        else
            inven[i] = 0;
    }
}

Character&      Character::operator=(Character const &ref)
{
    std::cout << "Character 복사대입 연산자 호출" << std::endl;
    if (this == &ref)
        return *this;
    this->name = ref.name;
    for (int i = 0; i < MAX_INVEN; i++)
    {
        if (ref.inven[i])
        {
            inven[i] = ref.inven[i]->clone();
            ref.inven[i]->setCloned(inven[i]);
        }
        else
            inven[i] = 0;
    }    
    return *this;
}

std::string const & Character::getName() const
{
    return this->name;
}

void Character::equip(AMateria* m)
{
    if (!m)
        return;
    for (int i = 0; i < MAX_INVEN; i++)
    {
        if (!inven[i])
        {
            inven[i] = m;
            break;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx >= MAX_INVEN)
        return;
    this->inven[idx] = 0;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= MAX_INVEN)
        return;
    this->inven[idx]->use(target);
}
