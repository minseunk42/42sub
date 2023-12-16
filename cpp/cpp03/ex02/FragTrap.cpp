#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "ft기본생성자 호출" << std::endl;
    this->hit_point = 100;
    this->energy_point = 100;
    this->attack_damage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << "ft생성자 호출" << std::endl;
    this->hit_point = 100;
    this->energy_point = 100;
    this->attack_damage = 30;
}

FragTrap::~FragTrap()
{
    std::cout << "ft소멸자 호출" << std::endl;
}

FragTrap&      FragTrap::operator=(FragTrap const &ref)
{
    std::cout << "ft복사대입 연산자 호출" << std::endl;
    ClapTrap:: operator=(ref);
    this->hit_point = ref.hit_point;
    this->energy_point = ref.get_energy_point();
    this->attack_damage = ref.get_attack_damage();
    return *this;
}

FragTrap::FragTrap(FragTrap const &ref) : ClapTrap(ref.name)
{
    std::cout << "ft복사 생성자 호출" << std::endl;
    this->hit_point = ref.get_hit_point();
    this->energy_point = ref.get_energy_point();
    this->attack_damage = ref.get_attack_damage();
}

void FragTrap::highFivesGuys()
{
    if (this->hit_point <= 0)
    {
        std::cout << this->name << " is dead" << std::endl;
        return;
    }
    std::cout << "FragTrap " << this->name \
    << " positive high fives!" << std::endl;
}
