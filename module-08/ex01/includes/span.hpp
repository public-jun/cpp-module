#ifndef SPAN_HPP
#define SPAN_HPP

#include <iterator>
#include <vector>
#include <set>
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
		void setValues();

		void addNumber(int n);
		void addNumber(std::vector<int>::iterator begin,
						std::vector<int>::iterator end);
		void addNumber(std::vector<int>::const_iterator begin,
						std::vector<int>::const_iterator end);
		long shortestSpan();
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
