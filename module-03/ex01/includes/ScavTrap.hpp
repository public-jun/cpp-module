#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& other);
		ScavTrap &operator=(const ScavTrap &other);
		virtual ~ScavTrap();

		void attack(std::string const &target);
		void guardGate();
};

#endif
