#include <WrongAnimal.hpp>
#include <color.hpp>
#include <iostream>

WrongAnimal::WrongAnimal() : type_("WrongAnimal")
{
	std::cout << RED
			  << "WrongAnimal default constructor called"
			  << END
			  << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	std::cout << RED
			  << "WrongAnimal copy constructor called"
			  << END
			  << std::endl;
	*this = other;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this != &other)
	{
		this->type_ = other.getType();
	}
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << RED
			  << "WrongAnimal destructor called"
			  << END
			  << std::endl;
}


const std::string &WrongAnimal::getType() const
{
	return (this->type_);
}

void WrongAnimal::makeSound() const
{
	std::cout << RED
			  << "WrongAnimal make sound: ..."
			  << END
			  << std::endl;
}
