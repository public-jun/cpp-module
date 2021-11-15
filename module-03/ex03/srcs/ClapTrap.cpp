#include <iostream>
#include <ClapTrap.hpp>
#include <color.hpp>

ClapTrap::ClapTrap() : name_("no name"), hitpoints_(10), energy_points_(10), attack_damage_(0)
{
	std::cout << RED;
	std::cout << "ClapTrap default constructor called" << std::endl;
	std::cout << END <<std::flush;
}

ClapTrap::ClapTrap(std::string name) : name_(name), hitpoints_(10), energy_points_(10), attack_damage_(0)
{
	std::cout << RED;
	std::cout << "ClapTrap constructor " << name_ << " called" << std::endl;
	std::cout << END <<std::flush;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << RED;
	std::cout << "ClapTrap copy constructor called" << std::endl;
	std::cout << END <<std::flush;
	*this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
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

ClapTrap::~ClapTrap()
{
	std::cout << RED;
	std::cout << "ClapTrap destructor " << name_ << " called" << std::endl;
	std::cout << END << std::flush;
}

const std::string &ClapTrap::get_name(void) const
{
	return (name_);
}

unsigned int ClapTrap::get_hitpoints(void) const
{
	return (hitpoints_);
}

unsigned int ClapTrap::get_energy_points(void) const
{
	return (energy_points_);
}

unsigned int ClapTrap::get_attack_damage(void) const
{
	return (attack_damage_);
}

void ClapTrap::attack(std::string const &target)
{
	std::cout << RED;
	std::cout << "ClapTrap " << name_
			  << " attacks " << target
			  << ", causing " << attack_damage_
			  << " points of damage !" << std::endl;
	std::cout << END <<std::flush;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	hitpoints_ = (hitpoints_ < amount ? 0 : hitpoints_ - amount);
	std::cout << RED;
	std::cout << "ClapTrap " << name_ << " took " << amount << " points of damage. "
			  << hitpoints_ << " HP is left !" << std::endl;
	std::cout << END <<std::flush;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	hitpoints_ += amount;
	std::cout << RED;
	std::cout << "ClapTrap " << name_ << " is repaired " << amount << " points. "
			  << hitpoints_ << " HP is left !" << std::endl;
	std::cout << END <<std::flush;
}

void ClapTrap::print_status() const
{
	std::cout << "\n" << ">>>>>>>>>>>>>>>>>>>" << std::endl;
	std::cout << RED;
	std::cout << "name :" << this->get_name() << std::endl;
	std::cout << "hitpoints :"<< this->get_hitpoints() << std::endl;
	std::cout << "energy_points :" << this->get_energy_points() << std::endl;
	std::cout << "attack_damage :" << this->get_attack_damage() << std::endl;
	std::cout << END << std::flush;
	std::cout << "<<<<<<<<<<<<<<<<<<<\n"
			  << std::endl;
}
