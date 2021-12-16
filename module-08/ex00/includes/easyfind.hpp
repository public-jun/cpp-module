#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <color.hpp>
#include <exception>
#include <iostream>
#include <iomanip>

class NotExistException : public std::exception
{
	public:
		const char *what() const throw()
		{
			return ("Cannot found!");
		}
};

template <class T>
typename T::const_iterator easyfind(const T &container, int val)
{
	typename T::const_iterator res = std::find(container.begin(), container.end(), val);
	if (res == container.end())
	{
		throw NotExistException();
	}
	return (res);
}

template <class T>
void testEasyFind(const T &v, int val)
{
	std::cout << std::setw(5) << val << ": " <<std::flush;
	try
	{
		std::cout << GREEN << *easyfind(v, val);
		std::cout <<  " find" << END << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << END << '\n';
	}
}

#endif
