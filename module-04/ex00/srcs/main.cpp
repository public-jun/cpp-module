#include <Animal.hpp>
#include <Dog.hpp>
#include <Cat.hpp>
#include <WrongCat.hpp>
#include <color.hpp>
#include <string>
#include <iostream>

int main(void)
{
	{
		std::cout << BOLD << "NORMALTEST" << END << std::endl;
		const Animal *meta = new Animal();
		const Animal *j = new Dog();
		const Animal *i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();

		delete meta;
		delete j;
		delete i;
	}

	{
		std::cout << BOLD << "\n\nWRONGTEST" << END << std::endl;
		const WrongAnimal *meta = new WrongAnimal();
		const WrongAnimal *i = new WrongCat();
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the Animal sound!
		meta->makeSound();

		delete meta;
		delete i;
	}
}
