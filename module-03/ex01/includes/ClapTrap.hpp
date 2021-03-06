#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
protected:
	std::string name_;
	unsigned int hitpoints_;
	unsigned int energy_points_;
	unsigned int attack_damage_;

public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &other);
	ClapTrap &operator=(const ClapTrap &other);
	virtual ~ClapTrap();

	const std::string &get_name(void) const;
	unsigned int get_hitpoints(void) const;
	unsigned int get_energy_points(void) const;
	unsigned int get_attack_damage(void) const;

	void attack(std::string const &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif
