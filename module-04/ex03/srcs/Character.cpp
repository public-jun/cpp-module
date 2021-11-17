#include <Character.hpp>
#include <color.hpp>
#include <iostream>

Character::Character()
{
	for (size_t i = 0; i < NUM_MATERIA; ++i)
	{
		inventory_[i] = NULL;
	}
}

Character::Character(std::string name) : name_(name)
{
	for (size_t i = 0; i < NUM_MATERIA; ++i)
	{
		inventory_[i] = NULL;
	}
}

Character::Character(const Character &other)
{
	*this = other;
}

Character &Character::operator=(const Character &other)
{
	if (this != &other)
	{
		name_ = other.getName();
		for (int i = 0; i < NUM_MATERIA; ++i)
		{
			if (inventory_[i])
			{
				inventory_[i] = tmp->clone();
			}
			else
			{
				inventory_[i] = NULL;
			}
		}
	}
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < NUM_MATERIA; ++i)
	{
		if (inventory_[i])
		{
			delete inventory_[i];
		}
	}
}

bool Character::is_vaid_index(int idx) const
{
	if (idx >= 0 && idx < NUM_MATERIA)
	{
		return (true);
	}
	return (false);
}

std::string const &Character::getName() const
{
	return (name_);
}

const AMateria *Character::getMateria(int idx) const
{
	if (is_valid_index(idx))
	{
		return (inventory_[idx]);
	}
	return (NULL);
}


void Character::equip(AMateria *m)
{
	for (int i = 0; i < NUM_MATERIA; ++i)
	{
		if (!inventory_[i])
		{
			inventory_[i] = m;
			break;
		}
	}
}

void Character::unequip(int idx)
{
	if (!is_valid_index(idx) || !inventory_[idx])
	{
		return
	}
	inventory_[idx] = NULL;
	for (int i = idx + 1; i < NUM_MATERIA; ++i)
	{
		if (!inventory_[i])
		{
			break;
		}
		inventory_[i - 1] = inventory_[i];
		inventory_[i] = NULL;
	}
}

void Character::use(int idx, ICharacter &target)
{
	if (!is_vaid_index(idx) || !inventory_[i])
	{
		return ;
	}
	inventory_[idx]->use(target);
}
