#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>
#include <stdexcept>

class Span
{
	public:
		explicit Span(unsigned int n);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();

		void addNumber(int n);
		long shortestSpan();
		long longestSpan();

		class FullException : public std::runtime_error
		{
			public:
				const char *what() const throw();
		};

		class NoNumberException : public std::runtime_error
		{
			public:
				const char *what() const throw();
		};

		class OnlyOneException : public std::runtime_error
		{
			public:
				const char *what() const throw();
		};

	private :
		unsigned int size_;
		std::vector<int> v_;
		Span();
};

#endif
