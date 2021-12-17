#include <span.hpp>
#include <color.hpp>
#include <iostream>

void printTestTitle(std::string title)
{
	std::cout << "\n"
			  << CYAN
			  << title
			  << " TEST"
			  << END << std::endl;
}

void printValues(Span &sp)
{
	std::vector<int> values = sp.getValues();
	std::vector<int>::iterator it_end = values.end();
	for (std::vector<int>::iterator it = values.begin(); it != it_end; ++it)
	{
		std::cout << *it << std::endl;
	}
}

void testShortestSpan(Span &sp)
{
	try
	{
		sp.shortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << END << '\n';
	}
}

void testLongestSpan(Span &sp)
{
	try
	{
		sp.longestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << END << '\n';
	}
}

void testAddNumber(Span &sp, int value)
{
	try
	{
		sp.addNumber(value);
		std::cout << GREEN << value << " Added!" << END << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << END << '\n';
	}

}


int main(void)
{
	{
		printTestTitle("SUBJECT");
		Span sp = Span(5);

		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	{
		printTestTitle("Empty Exception");
		Span sp = Span(5);

		testShortestSpan(sp);
		testLongestSpan(sp);

		printTestTitle("Only one Exception");
		testAddNumber(sp, 1);
		testShortestSpan(sp);
		testLongestSpan(sp);
	}

	{
		printTestTitle("Normal add number");
		Span sp = Span(5);

		testAddNumber(sp, 5);
		testAddNumber(sp, 3);
		testAddNumber(sp, 17);
		testAddNumber(sp, 9);
		testAddNumber(sp, 11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

		testAddNumber(sp, 42);
		printValues(sp);
	}

	{
		printTestTitle("initialize range");
		try
		{
			Span sp = Span(10001);
			std::vector<int> vec;
			for (int i = 0; i < 10001; ++i)
			{
				vec.push_back(i);
			}
			sp.addNumber(vec.begin(), vec.end());

			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;

			sp.addNumber(10);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	return (0);
}
