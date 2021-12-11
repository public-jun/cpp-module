#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <cstdint>
#include <bitset>

typedef struct s_Data
{
	int value;
} Data;

uintptr_t serialize(Data *ptr);

Data* deserialize(uintptr_t raw);

#endif
