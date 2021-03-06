#ifndef ICE_HPP
#define ICE_HPP

#include <AMateria.hpp>
#include <ICharacter.hpp>
#include <string>

class Ice : public AMateria
{
	private:

	public:
		Ice();
		Ice(const Ice &other);
		Ice &operator=(const Ice &other);
		virtual ~Ice();

		virtual AMateria *clone() const;
		virtual void use(ICharacter &target);
};

#endif
