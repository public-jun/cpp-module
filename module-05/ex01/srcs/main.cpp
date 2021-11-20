#include <Bureaucrat.hpp>
#include <color.hpp>
#include <iostream>

void PrintTestTitle(std::string title)
{
	std::cout << "\n" << BACK_GREEN << title << END << "\n" << std::endl;
}

int main(void)
{
	PrintTestTitle("----------CONSTRUCTOR TEST---------");
	
	return (0);
}
