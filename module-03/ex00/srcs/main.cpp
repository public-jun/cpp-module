#include <ClapTrap.hpp>
#include <string>
#include <iostream>

int main(void)
{
	ClapTrap bob("bob");

	std::cout << "name :" << bob.get_name() << std::endl;
	std::cout << "hitpoints :" << bob.get_hitpoints() << std::endl;
	std::cout << "energy_points :" << bob.get_energy_points() << std::endl;
	std::cout << "attack_damage :" << bob.get_attack_damage() << std::endl;

	bob.attack("something!");
	bob.takeDamage(10);
	bob.beRepaired(100);
	bob.takeDamage(50);
	bob.takeDamage(20);
	bob.beRepaired(12);
	bob.takeDamage(42);
}
