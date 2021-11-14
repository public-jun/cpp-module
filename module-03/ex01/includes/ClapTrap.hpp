#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	private:
		std::string name_;
		unsigned int hitpoints_;
		unsigned int energy_points_;
		unsigned int attack_damage_;

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &other);
		ClapTrap &operator=(const ClapTrap &other);
		~ClapTrap();

		const std::string &get_name(void) const;
		unsigned int get_hitpoints(void) const;
		unsigned int get_energy_points(void) const;
		unsigned int get_attak_damage(void) const;

		void attack(std::string const &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif
