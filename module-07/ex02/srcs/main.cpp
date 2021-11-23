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

void errorTEST(int index, unsigned int size, Array<int> &my_array)
{
	try
	{
		// int index = 42;
		std::cout << "range: "
				  << "0~" << size - 1 << std::endl;
		std::cout << "index: " << index << std::endl;
		my_array[index] = 0;
		std::cout << GREEN << "OK!" << END << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << "ERROR ACCESS!!" << END << '\n';
	}
}

int main(void)
{
	{
		printTitle("----CONSTRUCTOR TEST----");
		Array<int> array_empty;
		Array<int> array_42(42);

		Array<int> assign_array_a(10);
		Array<int> assign_array_b(20);

		assign_array_a = assign_array_b;

		Array<int> array_copy_empty = array_empty;
		printTitle("----DESTRUCTOR----");
	}

	{
		printTitle("----CONST CONSTRUCTOR TEST----");
		const Array<int> array_empty;
		const Array<int> array_42(42);

		const Array<int> assign_array_a(10);
		const Array<int> assign_array_b(20);

		const Array<int> array_copy_empty = array_empty;
		printTitle("----DESTRUCTOR----");
	}

	{
		printTitle("----INT ARRAY TEST----");
		const unsigned int size = 5;
		Array<int> my_array(size);
		int *num_array = new int[size];

		srand(time(NULL));
		for (unsigned int i = 0; i < size; ++i)
		{
			const int value = rand();
			my_array[i] = value;
			num_array[i] = value;
		}
		for (unsigned int i = 0; i < size; ++i)
		{
			std::cout << "my_array : " << my_array[i] << std::endl;
			std::cout << "num_array: " << num_array[i] << std::endl;
			if (my_array[i] != num_array[i])
			{
				std::cout << RED << "Not same value!!" << END << std::endl;
				break;
			}
			else
			{
				std::cout << GREEN << "OK!" << END << std::endl;
			}
		}
		delete[] num_array;
	}

	printTitle("----STRING ARRAY TEST----");
	{
		const unsigned int size = 10;
		Array<std::string> my_array(size);
		std::string *string_array = new std::string[size];

		srand(time(NULL));
		const std::string array[5] = {"42Tokyo", "42Paris", "42Seoul", "Ecole42", "42SV"};
		for (unsigned int i = 0; i < size; ++i)
		{
			const std::string value = array[rand() % 5];
			my_array[i] = value;
			string_array[i] = value;
		}
		for (unsigned int i = 0; i < size; ++i)
		{
			std::cout << "my_array    : " << my_array[i] << std::endl;
			std::cout << "string_array: " << string_array[i] << std::endl;
			if (my_array[i] != string_array[i])
			{
				std::cout << RED << "Not same value!!" << END << std::endl;
				break;
			}
			else
			{
				std::cout << GREEN << "OK!" << END << std::endl;
			}
		}
		delete[] string_array;
	}

	{
		printTitle("----ERROR TEST----");
		const unsigned int size = 42;
		Array<int> my_array(size);

		errorTEST(0, size, my_array);
		errorTEST(41, size, my_array);
		errorTEST(42, size, my_array);

		printTitle("----DESTRUCTOR----");
	}
	return 0;
}
