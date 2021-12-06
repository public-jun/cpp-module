#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{
	public:
		Animal();
		virtual ~Animal();

		const std::string &getType() const;

		virtual void makeSound() const = 0;

	protected:
		std::string type_;

	private:
		Animal(const Animal &other);
		Animal &operator=(const Animal &other);
};

#endif
