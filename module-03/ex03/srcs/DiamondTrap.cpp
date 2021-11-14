#include <DiamondTrap.hpp>

DiamondTrap::DiamondTrap() : ClapTrap("no name_clap_name"), name_("no name")
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), name_(name)
{
	std::cout << "DiiamondTrap constructor " << name_ << " called" << std::endl;
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
