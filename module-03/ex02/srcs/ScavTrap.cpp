#include <ScavTrap.hpp>

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	name_ = "no name";
	hitpoints_ = 100;
	energy_points_ = 50;
	attack_damage_ = 20;
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "ScavTrap constructor called" << std::endl;
	name_ = name;
	hitpoints_ = 100;
	energy_points_ = 50;
	attack_damage_ = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		name_ = other.get_name();
		hitpoints_ = other.get_hitpoints();
		energy_points_ = other.get_energy_points();
		attack_damage_ = other.get_attack_damagee();
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor " << name_ << " called" << std::endl;
}

void ScavTrap::attack(std::string const &target)
{
	std::cout << "ScavTrap " << name_
			  << " attacks " << target
			  << ", causing " << attack_damage_
			  << " points of damage !" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap" << name_ << "have enterred in Gate keeper mode." << std::endl;
}
