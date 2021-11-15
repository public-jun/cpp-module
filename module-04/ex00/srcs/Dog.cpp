#include <Dog.hpp>
#include <color.hpp>
#include <iostream>

Dog::Dog()
{
	type_ = "Dog";
	std::cout << GREEN
			  << "Dog default constructor called"
			  << END
			  << std::endl;
}

Dog::Dog(const Dog &other)
{
	std::cout << GREEN
			  << "Dog copy constructor called"
			  << END
			  << std::endl;
	*this = other;
}

Dog &Dog::operator=(const Dog &other)
{
	this->type_ = other.getType();
	return (*this);
}

Dog::~Dog()
{
	std::cout << GREEN
			  << "Dog destructor called"
			  << END
			  << std::endl;
}

void Dog::makeSound() const
{
	std::cout << GREEN
			  << "Dog make sound: bow wow!!"
			  << END
			  << std::endl;
}
