#include <Scalar.hpp>
#include <iostream>

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Enter numeric value" << std::endl;
		return (1);
	}

	Scalar value(static_cast<std::string>(av[1]));
	value.convert();
	return (0);
}
