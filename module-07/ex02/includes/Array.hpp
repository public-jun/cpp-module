#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <color.hpp>
#include <string>
#include <iostream>
#include <stdexcept>

template <class T>
class Array
{
	public:
		explicit Array();
		explicit Array(unsigned int n);
		Array(const Array &other);
		Array &operator=(const Array &other);
		~Array();

		T &operator[](unsigned int n);

		unsigned int size() const;
		const T *getArray() const;

	private:
		unsigned int n_;
		T *array_;
};

template <class T>
Array<T>::Array() : n_(0), array_(new T[0]())
{
	std::cout << BLUE << "defalt constructor called" << END << std::endl;
}

template <class T>
Array<T>::Array(unsigned int n) : n_(n), array_(new T[n]())
{
	std::cout << GREEN << "constructor called" << END << std::endl;
}

template <class T>
Array<T>::Array(const Array &other) : n_(other.size()), array_(new T[other.size()])
{
	std::cout << CYAN << "copy constructor called" << END << std::endl;
	const T *other_array = other.getArray();
	for (unsigned int i = 0; i < other.size(); ++i)
	{
		array_[i] = other_array[i];
	}
}

template <class T>
Array<T> &Array<T>::operator=(const Array &other)
{
	std::cout << YELLOW << "assignment operator called" << END << std::endl;
	if (this != &other)
	{
		unsigned int size = other.size();
		const T *array = other.getArray();

		n_ = size;
		T *tmp = new T[size];
		for (unsigned int i = 0; i < size; ++i)
		{
			tmp[i] = array[i];
		}
		delete [] array_;
		array_ = tmp;
	}
	return *this;
}

template <class T>
Array<T>::~Array()
{
	std::cout << RED << "destructor called" << END <<std::endl;
	delete [] array_;
}

template <class T>
T &Array<T>::operator[](unsigned int n)
{
	if (n_ <= n)
	{
		throw std::exception();
	}
	return array_[n];
}

template <class T>
unsigned int Array<T>::size() const
{
	return n_;
}

template <class T>
const T *Array<T>::getArray() const
{
	return array_;
}

#endif
