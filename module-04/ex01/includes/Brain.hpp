#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

#define NUM_IDEAS 100

class Brain
{
	public:
		Brain();
		Brain(const Brain &other);
		Brain &operator=(const Brain &other);
		~Brain();

	private:
		std::string ideas[NUM_IDEAS];
};

#endif
