#include <easyfind.hpp>
#include <iostream>
#include <iomanip>
#include <vector>

void testEasyFind(std::vector<int> &v, int val)
{
	std::cout << std::setw(5) << val << ": " <<std::flush;
	try
	{
		std::cout << *easyfind(v, val) << std::flush;
		std::cout << " find" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int main(void)
{
	const int a[] = {1, 22, 33, 44, 55};

	std::vector<int> v(a, a + 5);
	for (std::size_t i = 0; i < v.size(); ++i)
	{
		std::cout << std::setw(3) << "[" << i << "]: " << v.at(i) << std::endl;
	}


	testEasyFind(v, 66);
	testEasyFind(v, 1);

	return 0;
}
