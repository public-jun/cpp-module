#include <DiamondTrap.hpp>
#include <iostream>
#include <color.hpp>

//Clap RED
//Frag YELLOW
//Scav GREEN

int main(void)
{
	{
		DiamondTrap dia("dia");
		dia.print_status();
		dia.attack("42tokyo");
		dia.print_status();
		dia.takeDamage(10);
		dia.print_status();
		dia.beRepaired(20);
		dia.print_status();
		dia.highFivesGuys();
		dia.guardGate();
		dia.whoAmI();
		std::cout << std::endl;
	}

	// {
	// 	ClapTrap clap("clap");
	// 	clap.print_status();
	// 	clap.attack("42tokyo");
	// 	clap.print_status();
	// 	clap.takeDamage(10);
	// 	clap.print_status();
	// 	std::cout << std::endl;
	// }

	// {
	// 	FragTrap frag("frag");
	// 	frag.print_status();
	// 	frag.attack("42tokyo");
	// 	frag.print_status();
	// 	frag.takeDamage(10);
	// 	frag.print_status();
	// 	frag.highFivesGuys();
	// 	std::cout << std::endl;
	// }

	// {
	// 	ScavTrap scav("scav");
	// 	scav.print_status();
	// 	scav.attack("42tokyo");
	// 	scav.print_status();
	// 	scav.takeDamage(10);
	// 	scav.print_status();
	// 	scav.guardGate();
	// 	std::cout << std::endl;
	// }


	std::cout << std::endl;
}
