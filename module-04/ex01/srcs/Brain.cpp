#include <Brain.hpp>
#include <color.hpp>
#include <iostream>

Brain::Brain()
{
	std::cout << YELLOW
			  << "Brain default constructor called"
			  << END
			  << std::endl;
}

Brain::Brain(const Brain &other)
{
	*this = other;
	std::cout << YELLOW
			  << "Brain copy constructor called"
			  << END
			  << std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		for (size_t i = 0; i < NUM_IDEAS ; ++i)
		{
			this->set_idea(i, other.get_idea(i));
		}
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << YELLOW
			  << "Brain destructor called"
			  << END
			  << std::endl;
}


bool Brain::is_valid_index(int index) const
{
	if (index >= 0 && index < NUM_IDEAS )
	{
		return (true);
	}
	return (false);
}


const std::string &Brain::get_idea(int index) const
{
	if (is_valid_index(index))
	{
		return (this->ideas_[index]);
	}
	return (this->ideas_[0]);
}


void Brain::set_idea(int index, std::string idea)
{
	if (is_valid_index(index))
	{
		this->ideas_[index] = idea;
	}
	else
	{
		std::cout << "index[" << index << "]"
				  << " is out of range\n"
				  << "0 ~ 99 is required"
				  << std::endl;
	}
}
