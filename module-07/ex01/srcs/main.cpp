#include <iter.hpp>
#include <string>
#include <iostream>

void printTestTitle(std::string title)
{
	std::cout << "\n" << title << std::endl;
}

int main(void)
{


	printTestTitle("string TEST");
	std::string s_array[3] = {"42Tokyo", "42Paris", "42Seoul"};
	iter(s_array, sizeof(s_array) / sizeof(s_array[0]), printSomething);

	printTestTitle("const string TEST");
	const std::string cs_array[3] = {"24Tokyo", "24Paris", "24Seoul"};
	iter(cs_array, sizeof(cs_array) / sizeof(cs_array[0]), printSomething);

	printTestTitle("int TEST");
	int int_array[3] = {-42, 0 , 42};
	iter(int_array, sizeof(int_array) / sizeof(int_array[0]), printSomething);

	printTestTitle("double TEST");
	double d_array[3] = {3.14, 42.4242, -4242424.42};
	iter(d_array, sizeof(d_array) / sizeof(d_array[0]), printSomething);
}
