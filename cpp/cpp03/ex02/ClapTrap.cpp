#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "ct 기본생성자 호출" << std::endl;
    this->name = "no_name";
    this->hit_point = 10;
    this->energy_point = 10;
    this->attack_damage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
    std::cout << "ct생성자 호출" << std::endl;
    this->name = name;
    this->hit_point = 10;
    this->energy_point = 10;
    this->attack_damage = 0;
}

ClapTrap::ClapTrap(ClapTrap const &cref)
{
    std::cout << "ct복사 생성자 호출" << std::endl;
    this->name = cref.name;
    this->hit_point = cref.get_hit_point();
    this->energy_point = cref.get_energy_point();
    this->attack_damage = cref.get_attack_damage();
}

ClapTrap::~ClapTrap()
{
    std::cout << "ct소멸자 호출" << std::endl;
}

ClapTrap&      ClapTrap::operator=(ClapTrap const &cref)
{
    std::cout << "ct복사대입 연산자 호출" << std::endl;
    this->name = cref.name;
    this->hit_point = cref.get_hit_point();
    this->energy_point = cref.get_energy_point();
    this->attack_damage = cref.get_attack_damage();
    return *this;
}

void ClapTrap::attack(const std::string& target)
{
    if (!this->hit_point)
    {
        std::cout << "ClapTrap " << this->name << " is dead" << std::endl;
        return;
    }
    if (!this->energy_point)
    {
        std::cout << "ClapTrap " << this->name << " has not enough energy" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << this->name \
    << " attacks target " << target \
    << " , causing " << this->attack_damage << " points of damage!" << std::endl;
    this->energy_point -= 1;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (!this->hit_point)
    {
        std::cout << this->name << " is dead" << std::endl;
        return;
    }
    this->hit_point = this->hit_point < amount ? 0 : this->hit_point -= amount;
    std::cout << this->name \
    << " taked " << amount << " of damage" << ", now HP : " << this->hit_point << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (!this->hit_point)
    {
        std::cout << this->name << " is dead" << std::endl;
        return;
    }
    if (!this->energy_point)
    {
        std::cout << this->name << " has not enough energy" << std::endl;
        return;
    }
    std::cout << this->name \
    << " is repaired " << amount << " of hp" << std::endl;
    this->hit_point += amount;
    this->energy_point -= 1;
}

unsigned int ClapTrap::get_hit_point(void) const
{
    return this->hit_point;
}

unsigned int ClapTrap::get_energy_point(void) const
{
    return this->energy_point;
}

unsigned int ClapTrap::get_attack_damage(void) const
{
    return this->attack_damage;
}
