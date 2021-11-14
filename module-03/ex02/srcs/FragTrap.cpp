#include <FragTrap.hpp>

FragTrap::FragTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
	name_ = "no name";
	hitpoints_ = 100;
	energy_points_ = 100;
	attack_damage_ = 30;
}

FragTrap::FragTrap(std::string name)
{
	std::cout << "FragTrap constructor called" << std::endl;
	name_ = name;
	hitpoints_ = 100;
	energy_points_ = 100;
	attack_damage_ = 30;
}

FragTrap::FragTrap(const FragTrap &other)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = other;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
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

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor " << name_ << " called" << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap" << name_ << "said, High five, everyone!." << std::endl;
}
