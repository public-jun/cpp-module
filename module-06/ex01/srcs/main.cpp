#include <serialization.hpp>
#include <iostream>

int main(void)
{
	Data data;

	data.value = 42;

	std::cout << std::showbase;
	std::cout <<  "before ptr: " << &data << "\n";
	uintptr_t raw = serialize(&data);
	Data *p_data = deserialize(raw);
	std::cout <<  "after ptr : " << p_data;
	std::cout << std::noshowbase << "\n" << std::endl;

	std::cout << "compare value" << std::endl;
	std::cout << "before value: " << data.value << std::endl;
	std::cout << "after value : " << p_data->value << std::endl;

	return (0);
}
