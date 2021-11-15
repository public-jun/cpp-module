#include <Animal.hpp>
#include <color.hpp>
#include <iostream>

Animal::Animal() : type_("Animal")
{
	std::cout << RED
			  << "Animal default constructor called"
			  << END
			  << std::endl;
}

Animal::Animal(const Animal &other)
{
	std::cout << RED
			  << "Animal copy constructor called"
			  << END
			  << std::endl;
	*this = other;
}

Animal &Animal::operator=(const Animal &other)
{
	if (this != &other)
	{
		this->type_ = other.get_type();
	}
	return (*this);
}

Animal::~Animal()
{
	std::cout << RED
			  << "Animal destructor called"
			  << END
			  << std::endl;
}


const std::string &Animal::get_type() const
{
	return (this->type_);
}
