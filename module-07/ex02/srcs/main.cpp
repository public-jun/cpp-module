#include <Array.hpp>
#include <color.hpp>
#include <string>
#include <iostream>

void printTitle(std::string title)
{
	std::cout << "\n"
			  << BACK_GRAY << title << END << "\n"
			  << std::endl;
}

int main(void)
{
	printTitle("----CONSTRUCTOR----");
	{
		Array<int> array_empty;
		Array<int> array_42(42);

		Array<int> assign_array_a(10);
		Array<int> assign_array_b(20);

		assign_array_a = assign_array_b;

		Array<int> array_copy_empty = array_empty;
	}

	{
		const Array<int> array_empty;
		const Array<int> array_42(42);

		const Array<int> assign_array_a(10);
		const Array<int> assign_array_b(20);

		// assign_array_a = assign_array_b;

		const Array<int> array_copy_empty = array_empty;
	}

	printTitle("----DESTRUCTOR----");
}
