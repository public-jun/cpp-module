#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{
	public:
		Animal();
		Animal(const Animal &other);
		Animal &operator=(const Animal &other);
		virtual ~Animal();

		const std::string &getType() const;

		virtual void makeSound() const;

	protected:
		std::string type_;
};

#endif
