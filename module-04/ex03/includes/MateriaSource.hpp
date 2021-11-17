
#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <IMateriaSource.hpp>
#include <string>

#define NUM_MATERIA_SOURCE 4

class MateriaSource : public IMateriaSource
{
	private:
		AMateria *materias_[NUM_MATERIA_SOURCE];
		bool is_valid_index(int idx) const;

	public:
		MateriaSource();
		MateriaSource(const MateriaSource &other);
		MateriaSource &operator=(const MateriaSource &other);
		virtual ~MateriaSource();

		const AMateria *getMateria(int idx) const;

		void learnMateria(AMateria *m);
		AMateria *createMateria(std::string const &type);
};
#endif
