#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap()
{
    std::cout << "dt기본생성자 호출" << std::endl;
    this->name = ClapTrap::name + "_clap_name";
    this->hit_point = FragTrap::hit_point;
    this->attack_damage = FragTrap::attack_damage;
    this->energy_point = ScavTrap::get_energy_point();
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name)
{
    std::cout << "dt생성자 호출" << std::endl;
    this->name = ClapTrap::name + "_clap_name";
    this->hit_point = FragTrap::hit_point;
    this->attack_damage = FragTrap::attack_damage;
    this->energy_point = ScavTrap::energy_point;
    std::cout << "??? : " << ScavTrap::get_energy_point() << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "dt소멸자 호출" << std::endl;
}

DiamondTrap&      DiamondTrap::operator=(DiamondTrap const &ref)
{
    std::cout << "dt복사대입 연산자 호출" << std::endl;
    ScavTrap:: operator=(ref);
    FragTrap:: operator=(ref);
    this->name = ref.name;
    this->hit_point = ref.hit_point;
    this->energy_point = ref.get_energy_point();
    this->attack_damage = ref.get_attack_damage();
    return *this;
}

DiamondTrap::DiamondTrap(DiamondTrap const &ref)
{
    std::cout << "dt복사 생성자 호출" << std::endl;
    this->name = ref.name;
    this->hit_point = ref.get_hit_point();
    this->energy_point = ref.get_energy_point();
    this->attack_damage = ref.get_attack_damage();
}

void DiamondTrap::whoAmI()
{
    if (this->hit_point <= 0)
    {
        std::cout << ClapTrap::name << " is dead" << std::endl;
        return;
    }
    std::cout << "dt name : " << ClapTrap::name \
    << ", ct name : " << name << std::endl;
}
