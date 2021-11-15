#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <string>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& other);
		ScavTrap &operator=(const ScavTrap &other);
		virtual ~ScavTrap();

		void attack(std::string const &target);
		void guardGate();

		void print_status() const;
};

#endif
