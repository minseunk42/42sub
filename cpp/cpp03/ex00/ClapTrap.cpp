#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){}

ClapTrap::ClapTrap(std::string name)
{
    std::cout << "생성자 호출" << std::endl;
    this->name = name;
    this->hit_point = 10;
    this->energy_point = 10;
    this->attack_damage = 0;
}

ClapTrap::ClapTrap(ClapTrap const &cref)
{
    std::cout << "복사 생성자 호출" << std::endl;
    this->name = cref.name;
    this->hit_point = 10;
    this->energy_point = 10;
    this->attack_damage = 0;
}

ClapTrap::~ClapTrap()
{
    std::cout << "소멸자 호출" << std::endl;
}

ClapTrap&      ClapTrap::operator=(ClapTrap const &cref)
{
    std::cout << "복사대입 연산자 호출" << std::endl;
    this->name = cref.name;
    this->hit_point = 10;
    this->energy_point = 10;
    this->attack_damage = 0;
    return *this;
}

void ClapTrap::attack(const std::string& target)
{
    if (!this->energy_point)
    {
        std::cout << "ClapTrap " << this->name << " has not enough energy" << std::endl;
        return;
    }
    if (!this->hit_point)
    {
        std::cout << "ClapTrap " << this->name << " is dead" << std::endl;
        return;
    }
    std::cout << "ClapTrap" << this->name \
    << " attacks target " << target \
    << " , causing " << this->attack_damage << " points of damage!" << std::endl;
    this->energy_point -= 1;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "ClapTrap " << this->name \
    << " taked " << amount << " of damage" << std::endl;
    this->hit_point -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (!this->energy_point)
    {
        std::cout << "ClapTrap " << this->name << " has not enough energy" << std::endl;
        return;
    }
    if (!this->hit_point)
    {
        std::cout << "ClapTrap " << this->name << " is dead" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << this->name \
    << " is repaired " << amount << " of hp" << std::endl;
    this->hit_point += amount;
    this->energy_point -= 1;
}