#ifndef CURE_HPP
#define CURE_HPP

#include <AMateria.hpp>
#include <ICharacter.hpp>
#include <string>

class Cure: public AMateria
{
	private:

	public:
		Cure();
		Cure(const Cure &other);
		Cure &operator=(const Cure &other);
		virtual ~Cure();

		virtual AMateria *clone() const;
		virtual void use(ICharacter &target);
};

#endif
