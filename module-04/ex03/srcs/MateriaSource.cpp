#include <MateriaSource.hpp>
#include <iostream>

bool MateriaSource::is_valid_index(int idx) const
{
	if (idx >= 0 && idx < NUM_MATERIA_SOURCE)
	{
		return (true);
	}
	return (false);
}

MateriaSource::MateriaSource()
{
	for (size_t i = 0; i < NUM_MATERIA_SOURCE; ++i)
	{
		materias_[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	*this = other;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		for (size_t i = 0; i < NUM_MATERIA_SOURCE; ++i)
		{
			const AMateria *tmp = other.getMateria((static_cast<int>(i)));
			if (tmp)
			{
				materias_[i] = tmp->clone();
			}
			else
			{
				materias_[i] = NULL;
			}
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < NUM_MATERIA_SOURCE; ++i)
	{
		if (materias_[i])
		{
			delete materias_[i];
		}
	}
}

const AMateria *MateriaSource::getMateria(int idx) const
{
	if (is_valid_index(idx))
	{
		return (materias_[idx]);
	}
	return (NULL);
}

void MateriaSource::learnMateria(AMateria *m)
{
	for (size_t i = 0; i < NUM_MATERIA_SOURCE; ++i)
	{
		if (!materias_[i])
		{
			materias_[i] = m;
			break;
		}
	}
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (size_t i = 0; i < NUM_MATERIA_SOURCE; ++i)
	{
		if (!materias_[i])
		{
			break;
		}
		else if (materias_[i]->getType() == type)
		{
			return (materias_[i]->clone());
		}
	}
	return (0);
}
