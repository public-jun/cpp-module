#ifndef TEST_HPP
#define TEST_HPP

#include <whatever.hpp>
#include <color.hpp>
#include <iostream>
#include <string>

template <class T>
void swapTest(T &a, T &b)
{
	std::cout << "\nbefor :"
			  << "(a, b) = ("
			  << RED << a << END
			  << ", "
			  << BLUE << b << END
			  << ") " << std::endl;
	swap(a, b);
	std::cout << "after :"
			  << "(a, b) = ("
			  << BLUE << a << END
			  << ", "
			  << RED << b << END
			  << ") " << std::endl;
}

template <class T>
void minMaxTest(T &a, T &b)
{
	std::cout << BOLD
			  << "\n"
			  << "case: ["
			  << a
			  << "(" << &a <<")"
			  << ", "
			  << b
			  << "(" << &b <<")"
			  << "]"
			  << END << std::endl;

	std::cout << "min: "
			  << min(a, b)
			  << "("
			  << &min(a, b)
			  << ")" << std::endl;

	std::cout << "max: "
			  << max(a, b)
			  << "("
			  << &max(a, b)
			  << ")" << std::endl;
}

#endif
