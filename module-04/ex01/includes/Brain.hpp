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

		bool is_valid_index(int index) const;
		const std::string &get_idea(int index) const;
		void set_idea(int index, std::string idea);

	private:
		std::string ideas_[NUM_IDEAS];
};

#endif
