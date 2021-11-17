#include <Cure.hpp>
#include <color.hpp>
#include <iostream>

Cure::Cure() : type_("cure")
{
}

Cure::Cure(const Cure &other)
{
	*this = other;
}

Cure &Cure::operator=(const Cure &other)
{
	if (this != &other)
	{
		type_ = other.getType();
	}
	return (*this);
}

Cure::~Cure()
{
}

AMateria *Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter &target)
{
	std::cout << GREEN
			  << "Cure:  \"* heals "
			  << target.getName()
			  << "'s wounds *\""
			  << END << std::endl;
}
