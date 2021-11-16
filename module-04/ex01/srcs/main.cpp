#include <Animal.hpp>
#include <Dog.hpp>
#include <Cat.hpp>
#include <Brain.hpp>
#include <color.hpp>
#include <string>
#include <iostream>

int main(void)
{
	{
		// std::cout << BOLD << "NORMALTEST" << END << std::endl;
		// const Animal *meta = new Animal();
		// const Animal *j = new Dog();
		// const Animal *i = new Cat();
		// std::cout << j->getType() << " " << std::endl;
		// std::cout << i->getType() << " " << std::endl;
		// i->makeSound(); //will output the cat sound!
		// j->makeSound();
		// meta->makeSound();

		// delete meta;
		// delete j;
		// delete i;
	}
	{
		std::cout << BOLD << "BRAINTEST" << END << std::endl;
		Brain *brain = new Brain();
		for(size_t i = 0; i < 100; ++i)
		{
			brain->set_idea(i, "BRAIN" + std::to_string(i));
		}
		Brain brain_a = *brain;
		// for(size_t i = 0; i < 100; ++i)
		// {
		// 	std::cout << brain->get_idea(i) << std::endl;
		// }
		for(size_t i = 0; i < 100; ++i)
		{
			std::cout << brain_a.get_idea(i) << std::endl;
		}
		delete brain;
	}
}
