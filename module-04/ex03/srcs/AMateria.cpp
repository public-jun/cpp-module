#include <AMateria.hpp>
#include <color.hpp>
#include <iostream>

AMateria::AMateria()
{
}

AMateria::AMateria(std::string const &type) :
	type_(type)
{
}

AMateria::AMateria(const AMateria &other)
{
	*this = other;
}

AMateria &AMateria::operator=(const AMateria &other)
{
	if (this != &other)
	{
		std::cout << BOLD
				  << "copying the type doesn’t make sense... "
				  << END << std::endl;
		type_ = "";
	}
	return (*this);
}

AMateria::~AMateria()
{
}

std::string const &AMateria::getType() const
{
	return (type_);
}

void AMateria::use(ICharacter &target)
{
	std::cout << BOLD
			  << "* AMateria use for "
			  << target.getName()
			  << " *"
			  << END << std::endl;
}
