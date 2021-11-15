#include <iostream>
#include <FragTrap.hpp>
#include <color.hpp>

FragTrap::FragTrap()
{
	std::cout << YELLOW;
	std::cout << "FragTrap default constructor called" << std::endl;
	std::cout << END << std::flush;
	hitpoints_ = 100;
	energy_points_ = 100;
	attack_damage_ = 30;
}

FragTrap::FragTrap(std::string name)
{
	std::cout << YELLOW;
	std::cout << "FragTrap constructor called" << std::endl;
	std::cout << END << std::flush;
	name_ = name;
	hitpoints_ = 100;
	energy_points_ = 100;
	attack_damage_ = 30;
}

FragTrap::FragTrap(const FragTrap &other)
{
	std::cout << YELLOW;
	std::cout << "FragTrap copy constructor called" << std::endl;
	std::cout << END << std::flush;
	*this = other;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
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

FragTrap::~FragTrap()
{
	std::cout << YELLOW;
	std::cout << "FragTrap destructor " << name_ << " called" << std::endl;
	std::cout << END << std::flush;
}

void FragTrap::highFivesGuys()
{
	std::cout << YELLOW;
	std::cout << "FragTrap" << name_ << "said, High five, everyone!." << std::endl;
	std::cout << END << std::flush;
}

void FragTrap::print_status() const
{
	std::cout << "\n" << ">>>>>>>>>>>>>>>>>>>" << std::endl;
	std::cout << YELLOW;
	std::cout << "name :" << this->get_name() << std::endl;
	std::cout << "hitpoints :"<< this->get_hitpoints() << std::endl;
	std::cout << "energy_points :" << this->get_energy_points() << std::endl;
	std::cout << "attack_damage :" << this->get_attack_damage() << std::endl;
	std::cout << END << std::flush;
	std::cout << "<<<<<<<<<<<<<<<<<<<\n"
			  << std::endl;
}
