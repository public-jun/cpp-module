#include <iostream>
#include <ScavTrap.hpp>
#include <color.hpp>

ScavTrap::ScavTrap()
{
	std::cout << GREEN;
	std::cout << "ScavTrap default constructor called" << std::endl;
	std::cout << END << std::flush;
	hitpoints_ = 100;
	energy_points_ = 50;
	attack_damage_ = 20;
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << GREEN;
	std::cout << "ScavTrap constructor called" << std::endl;
	std::cout << END << std::flush;
	name_ = name;
	hitpoints_ = 100;
	energy_points_ = 50;
	attack_damage_ = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other)
{
	std::cout << GREEN;
	std::cout << "ScavTrap copy constructor called" << std::endl;
	std::cout << END << std::flush;
	*this = other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		name_ = other.get_name();
		hitpoints_ = other.get_hitpoints();
		energy_points_ = other.get_energy_points();
		attack_damage_ = other.get_attack_damage();
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << GREEN;
	std::cout << "ScavTrap destructor " << name_ << " called" << std::endl;
	std::cout << END << std::flush;
}

void ScavTrap::attack(std::string const &target)
{
	std::cout << GREEN;
	std::cout << "ScavTrap " << name_
			  << " attacks " << target
			  << ", causing " << attack_damage_
			  << " points of damage !" << std::endl;
	std::cout << END << std::flush;
}

void ScavTrap::guardGate()
{
	std::cout << GREEN;
	std::cout << "ScavTrap" << name_ << "have enterred in Gate keeper mode." << std::endl;
	std::cout << END << std::flush;
}

void ScavTrap::print_status() const
{
	std::cout << "\n" << ">>>>>>>>>>>>>>>>>>>" << std::endl;
	std::cout << GREEN;
	std::cout << "name :" << this->get_name() << std::endl;
	std::cout << "hitpoints :"<< this->get_hitpoints() << std::endl;
	std::cout << "energy_points :" << this->get_energy_points() << std::endl;
	std::cout << "attack_damage :" << this->get_attack_damage() << std::endl;
	std::cout << END << std::flush;
	std::cout << "<<<<<<<<<<<<<<<<<<<\n"
			  << std::endl;
}
