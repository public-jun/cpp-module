#include <span.hpp>
#include <iostream>

int main(void)
{
	Span sp = Span(5);

	sp.addNumber(1);
	sp.addNumber(2);
	sp.addNumber(3);
	sp.addNumber(4);

	std::vector<int> values = sp.getValues();
	std::cout << values.at(0) << std::endl;

	std::cout << sp.longestSpan() << std::endl;
	return (0);
}
