#include <WrongCat.hpp>
#include <color.hpp>
#include <iostream>

WrongCat::WrongCat()
{
	type_ = "WrongCat";
	std::cout << BLUE
			  << "WrongCat default constructor called"
			  << END
			  << std::endl;
}

WrongCat::WrongCat(const WrongCat &other)
{
	*this = other;
	std::cout << BLUE
			  << "WrongCat copy constructor called"
			  << END
			  << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	this->type_ = other.getType();
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << BLUE
			  << "WrongCat copy constructor called"
			  << END
			  << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << BLUE
			  << "WrongCat make sound: meow"
			  << END
			  << std::endl;
}
