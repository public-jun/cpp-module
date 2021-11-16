#include <Cat.hpp>
#include <color.hpp>
#include <iostream>

Cat::Cat()
{
	type_ = "Cat";
	std::cout << BLUE
			  << "Cat default constructor called"
			  << END
			  << std::endl;
}

Cat::Cat(const Cat &other)
{
	*this = other;
	std::cout << BLUE
			  << "Cat copy constructor called"
			  << END
			  << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	this->type_ = other.getType();
	return (*this);
}

Cat::~Cat()
{
	std::cout << BLUE
			  << "Cat destructor called"
			  << END
			  << std::endl;
}

void Cat::makeSound() const
{
	std::cout << BLUE
			  << "Cat make sound: meow"
			  << END
			  << std::endl;
}
