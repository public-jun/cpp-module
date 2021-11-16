#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat &other);
		Cat &operator=(const Cat &other);
		virtual ~Cat();

		virtual void makeSound() const;

		const Brain *get_brain() const;
		const std::string &get_brain_idea(int index) const;
		void set_brain_idea(int index, std::string idea);

	private:
		Brain *brain_;
};

#endif
