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
	if (this != &other)
	{
		type_ = other.getType();

		Brain *new_brain = new Brain();
		*new_brain = *(other.brain_);
		delete brain_;
		brain_ = new_brain;
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

const Brain *Dog::get_brain() const
{
	return (this->brain_);
}

const std::string &Dog::get_brain_idea(int index) const
{
	return (brain_->get_idea(index));
}

void Dog::set_brain_idea(int index, std::string idea)
{
	brain_->set_idea(index, idea);
}
