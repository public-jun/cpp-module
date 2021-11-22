#ifndef ITER_HPP
#define ITER_HPP

#include <string>
#include <iostream>

template <class T>
void iter(T *array, std::size_t len, void (*f)(T&))
{
	for (std::size_t i = 0; i < len ; ++i)
	{
		f(array[i]);
	}
}

template <class T>
void iter(const T *array, std::size_t len, void (*f)(const T&))
{
	for (std::size_t i = 0; i < len ; ++i)
	{
		f(array[i]);
	}
}

template <class T>
void printSomething(T &a)
{
	std::cout << a << std::endl;
}

template <class T>
void printSomething(const T &a)
{
	std::cout << a << std::endl;
}

#endif
