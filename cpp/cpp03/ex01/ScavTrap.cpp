#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "st기본생성자 호출" << std::endl;
    this->hit_point = 100;
    this->energy_point = 50;
    this->attack_damage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "st생성자 호출" << std::endl;
    this->hit_point = 100;
    this->energy_point = 50;
    this->attack_damage = 20;
}

ScavTrap::~ScavTrap()
{
    std::cout << "st소멸자 호출" << std::endl;
}

ScavTrap&      ScavTrap::operator=(ScavTrap const &ref)
{
    std::cout << "st복사대입 연산자 호출" << std::endl;
    ClapTrap:: operator=(ref);
    this->hit_point = ref.hit_point;
    this->energy_point = ref.get_energy_point();
    this->attack_damage = ref.get_attack_damage();
    return *this;
}

ScavTrap::ScavTrap(ScavTrap const &ref) : ClapTrap(ref.name)
{
    std::cout << "st복사 생성자 호출" << std::endl;
    this->hit_point = ref.get_hit_point();
    this->energy_point = ref.get_energy_point();
    this->attack_damage = ref.get_attack_damage();
}

void ScavTrap::attack(const std::string& target)
{
    if (this->hit_point <= 0)
    {
        std::cout << this->name << " is dead" << std::endl;
        return;
    }
    if (this->energy_point <= 0)
    {
        std::cout << this->name << " has not enough energy" << std::endl;
        return;
    }
    std::cout << "st " << this->name \
    << " attacks target " << target \
    << " , causing " << this->attack_damage << " points of damage!" << std::endl;
    this->energy_point -= 1;
}