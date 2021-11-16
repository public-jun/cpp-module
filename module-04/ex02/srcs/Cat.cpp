#include <Cat.hpp>
#include <color.hpp>
#include <iostream>

Cat::Cat()
{
	std::cout << BLUE
			  << "Cat default constructor called"
			  << END
			  << std::endl;
	type_ = "Cat";
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

Cat::Cat(const Cat &other) : brain_(new Brain())
{
	std::cout << BLUE
			  << "Cat copy constructor called"
			  << END
			  << std::endl;
	*this = other;
}

Cat &Cat::operator=(const Cat &other)
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

Cat::~Cat()
{
	delete brain_;
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

const Brain *Cat::get_brain() const
{
	return (this->brain_);
}

const std::string &Cat::get_brain_idea(int index) const
{
	return (brain_->get_idea(index));
}

void Cat::set_brain_idea(int index, std::string idea)
{
	brain_->set_idea(index, idea);
}
