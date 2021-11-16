#include <Animal.hpp>
#include <Dog.hpp>
#include <Cat.hpp>
#include <Brain.hpp>
#include <color.hpp>
#include <string>
#include <iostream>

int main(void)
{
	std::cout << BOLD << "\nINSTANCE PART\n" << END << std::endl;

	// Animal animal;
	// animal.makeSound();
	Cat cat;
	cat.makeSound();
	Dog dog;
	dog.makeSound();
}
