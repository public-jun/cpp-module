#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <string>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string name_;

	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &other);
		DiamondTrap &operator=(const DiamondTrap &other);
		virtual ~DiamondTrap();

		const std::string &get_name() const;
		const std::string &get_clap_name() const;

		void attack(std::string const &target);
		void whoAmI();

		void print_status() const;
};

#endif
