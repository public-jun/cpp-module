#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog &other);
		Dog &operator=(const Dog &other);
		virtual ~Dog();

		virtual void makeSound() const;

		const Brain *get_brain() const;
		const std::string &get_brain_idea(int index) const;
		void set_brain_idea(int index, std::string idea);

	private:
		Brain *brain_;
};

#endif
