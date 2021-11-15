#include <Animal.hpp>
#include <string>
#include <iostream>

int main(void)
{
	Animal *animal1 = new Animal();

	std::cout << animal1->get_type() << std::endl;
	animal1->makeSound();
	
	delete animal1;
}
