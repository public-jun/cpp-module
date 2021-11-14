#include <ClapTrap.hpp>

ClapTrap::ClapTrap() : name_("no name"), hitpoints_(10), energy_points_(10), attack_damage_(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name_(name), hitpoints_(10), energy_points_(10), attack_damage_(0)
{
	std::cout << "ClapTrap constructor " << name_ << " called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
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
	std::cout << "ClapTrap destructor " << name_ << " called" << std::endl;
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
	std::cout << "ClapTrap " << name_
			  << " attacks " << target
			  << ", causing " << attack_damage_
			  << " points of damage !" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	hitpoints_ = (hitpoints_ < amount ? 0 : hitpoints_ - amount);
	std::cout << "ClapTrap " << name_ << " took " << amount << " points of damage. "
			  << hitpoints_ << " HP is left !" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	hitpoints_ += amount;
	std::cout << "ClapTrap " << name_ << " is repaired " << amount << " points. "
			  << hitpoints_ << " HP is left !" << std::endl;
}
