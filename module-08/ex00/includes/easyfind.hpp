#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <vector>
#include <exception>

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

#endif
