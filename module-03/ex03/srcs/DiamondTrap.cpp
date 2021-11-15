#include <DiamondTrap.hpp>
#include <color.hpp>
#include <iostream>

DiamondTrap::DiamondTrap() : ClapTrap("no name_clap_name"), name_("no name")
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
	this->FragTrap::hitpoints_ = 100;
	this->ScavTrap::energy_points_ = 50;
	this->FragTrap::attack_damage_ = 30;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), name_(name)
{
	std::cout << "DiiamondTrap constructor " << name_ << " called" << std::endl;
	this->FragTrap::hitpoints_ = 100;
	this->ScavTrap::energy_points_ = 50;
	this->FragTrap::attack_damage_ = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	*this = other;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this != &other)
	{
		name_ = other.get_name();
		this->ClapTrap::name_ = other.get_clap_name();
		hitpoints_ = other.get_hitpoints();
		energy_points_ = other.get_energy_points();
		attack_damage_ = other.get_attack_damage();
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor " << name_ << " called" << std::endl;
}

const std::string &DiamondTrap::get_name() const
{
	return (name_);
}

const std::string &DiamondTrap::get_clap_name() const
{
	return (this->ClapTrap::get_name());
}

void DiamondTrap::attack(std::string const &target)
{
	this->ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name is " << get_name() << "." << std::endl;
	std::cout << "ClapTrap name is " << get_clap_name() << "." << std::endl;
}

void DiamondTrap::print_status() const
{
	std::cout << "\n" << ">>>>>>>>>>>>>>>>>>>" << std::endl;
	std::cout << WHITE << "name " << END << ":" << this->get_name() << std::endl;
	std::cout << RED << "clap_name " << END << ":" << this->ClapTrap::get_name() << std::endl;
	std::cout << YELLOW << "hitpoints " << END << ":"<< this->get_hitpoints() << std::endl;
	std::cout << GREEN << "energy_points " << END << ":" << this->get_energy_points() << std::endl;
	std::cout << YELLOW << "attack_damage " << END << ":" << this->get_attack_damage() << std::endl;
	std::cout << "<<<<<<<<<<<<<<<<<<<\n"
			  << std::endl;
}
