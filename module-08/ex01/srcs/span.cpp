#include <span.hpp>
#include <iostream>

Span::Span(unsigned int n)
{
	size_ = n;
	values_.reserve(size_);
}

Span::Span(const Span &other)
{
	*this = other;
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		size_ = other.getSize();
		values_ = other.getValues();
	}
	return *this;
}

Span::~Span() {}


unsigned int Span::getSize() const
{
	return size_;
}

std::vector<int> Span::getValues() const
{
	return values_;
}

void Span::addNumber(int n)
{
	if (values_.size() >= size_)
	{
		throw FullException("Stored number is FULL");
	}
	values_.push_back(n);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	for (std::vector<int>::iterator it = begin; it != end; ++it)
	{
		if (values_.size() >= size_)
		{
			throw FullException("Stored number is FULL");
		}
		values_.push_back(*it);
	}
}

void Span::addNumber(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end)
{
	for (std::vector<int>::const_iterator it = begin; it != end; ++it)
	{
		if (values_.size() >= size_)
		{
			throw FullException("Stored number is FULL");
		}
		values_.push_back(*it);
	}
}

long Span::shortestSpan()
{
	if (values_.size() == 0)
	{
		throw NoNumberException("No number is store");
	}
	else if (values_.size() == 1)
	{
		throw OnlyOneException("Ther is only one number stored");
	}
	long span;
	std::multiset<int> sort_values(values_.begin(), values_.end());
	const std::multiset<int>::const_iterator it_end = sort_values.end();
	std::multiset<int>::iterator first = sort_values.begin();
	std::multiset<int>::iterator second = sort_values.begin();
	for (std::advance(second, 1); second != it_end; ++second)
	{
		if (*second - *first < span)
			span = *second - *first;
		++first;
	}
	return (span);
}

long Span::longestSpan()
{
	if (values_.size() == 0)
	{
		throw NoNumberException("No number is store");
	}
	else if (values_.size() == 1)
	{
		throw OnlyOneException("Ther is only one number stored");
	}
	std::vector<int>::iterator it_min = std::min_element(values_.begin(), values_.end());
	std::vector<int>::iterator it_max = std::max_element(values_.begin(), values_.end());

	return (long)(*it_max) - (*it_min);
}

Span::FullException::FullException(const std::string &s) :
	runtime_error(s) {}

Span::NoNumberException::NoNumberException(const std::string &s) :
	runtime_error(s) {}

Span::OnlyOneException::OnlyOneException(const std::string &s) :
	runtime_error(s) {}
