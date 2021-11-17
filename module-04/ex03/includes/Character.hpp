#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <ICharacter.hpp>
#include <AMateria.hpp>
#include <string>

#define NUM_MATERIA 4

class Character : public ICharacter
{
	private:
		std::string name_;
		AMateria *inventory_[NUM_MATERIA];

		Character();

		bool is_valid_index(int idx) const;

	public:
		Character(std::string name);
		Character(const Character &other);
		Character &operator=(const Character &other);
		virtual ~Character();


		virtual std::string const &getName() const;
		const AMateria *getMateria(int idx) const;

		virtual void equip(AMateria *m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter &target);
};

#endif
