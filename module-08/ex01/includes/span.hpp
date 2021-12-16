#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>
#include <stdexcept>
#include <string>
#include <algorithm>

class Span
{
	public:
		explicit Span(unsigned int n);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();

		unsigned int getSize() const;
		std::vector<int> getValues() const;

		void addNumber(int n);
		// long shortestSpan();
		long longestSpan();

		class FullException : public std::runtime_error
		{
			public:
				FullException(const std::string &s);
		};

		class NoNumberException : public std::runtime_error
		{
			public:
				NoNumberException(const std::string &s);
		};

		class OnlyOneException : public std::runtime_error
		{
			public:
				OnlyOneException(const std::string &s);
		};

	private :
		unsigned int size_;
		std::vector<int> values_;
		Span();
};

#endif
