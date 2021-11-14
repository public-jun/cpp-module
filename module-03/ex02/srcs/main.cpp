#include <FragTrap.hpp>

void print_profile(const FragTrap &a)
{
	std::cout << "\n>>>>>>>>>>>>>>>>>>>" << std::endl;
	std::cout << "name :" << a.get_name() << std::endl;
	std::cout << "hitpoints :" << a.get_hitpoints() << std::endl;
	std::cout << "energy_points :" << a.get_energy_points() << std::endl;
	std::cout << "attack_damage :" << a.get_attack_damage() << std::endl;
	std::cout << "<<<<<<<<<<<<<<<<<<<\n"
			  << std::endl;
}

int main(void)
{
	FragTrap no_name;

	print_profile(no_name);
	no_name.takeDamage(3);

	FragTrap bob("bob");
	print_profile(bob);
	bob.takeDamage(3);

	FragTrap bob2(bob);
	print_profile(bob2);
	bob.takeDamage(10);

	FragTrap bob3;
	bob3 = bob;
	print_profile(bob3);

	bob.attack("tokyo");
	bob.beRepaired(30);
	bob.highFivesGuys();

	std::cout << std::endl;
}
