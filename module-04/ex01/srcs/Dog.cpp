#include <Dog.hpp>
#include <color.hpp>
#include <iostream>

Dog::Dog()
{
	std::cout << GREEN
			  << "Dog default constructor called"
			  << END
			  << std::endl;
	type_ = "Dog";
	try
	{
		brain_ = new Brain();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		throw;
	}
}

Dog::Dog(const Dog &other) : brain_(new Brain())
{
	std::cout << GREEN
			  << "Dog copy constructor called"
			  << END
			  << std::endl;
	*this = other;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << GREEN
			  << "Dog Assignnation operator called"
			  << END
			  << std::endl;
	if (this != &other)
	{
		type_ = other.getType();

		Brain *p = new Brain();
		*p = *(other.brain_);
		delete brain_;
		brain_ = p;
	}
	return (*this);
}

Dog::~Dog()
{
	delete brain_;
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
