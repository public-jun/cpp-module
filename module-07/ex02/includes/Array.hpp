#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <string>
#include <iostream>

template <class T>
class Array
{
	public:
		explicit Array();
		explicit Array(unsigned int n);


	private:
		T *array_;
		unsigned int n_;
};

template <class T>
Array<T>::Array()
{
	std::cout << "defalt constructor called" << std::endl;
	n_ = 0;
	array_ = new T[0]();
}

template <class T>
Array<T>::Array(unsigned int n)
{
	std::cout << "constructor called" << std::endl;
	n_ = n;
	array_ = new T[n]();
}

#endif
