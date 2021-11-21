#include <Scalar.hpp>
#include <iostream>

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "One argment required" << std::endl;
		return (1);
	}

	Scalar scalar(av[1]);
	scalar.ToChar();
	//Convertする
	// scalar.;
	//statusをprintする
}
