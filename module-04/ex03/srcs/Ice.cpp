#include <Ice.hpp>
#include <color.hpp>
#include <iostream>

Ice::Ice() : type_("ice")
{
}

Ice::Ice(const Ice &other)
{
	*this = other;
}

Ice &Ice::operator=(const Ice &other)
{
	if (this != &other)
	{
		type_ = other.getType();
	}
	return (*this);
}

Ice::~Ice()
{
}

AMateria *Ice::clone()
{
	return (new Ice(*this));
}

void Ice::use(ICharacter &target)
{
	std::cout << BLUE
			  << "Ice: \"* shoots an ice bolt at "
			  << target.getName()
			  << " *\""
			  << END << std::endl;
}
