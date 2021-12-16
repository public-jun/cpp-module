#include <span.hpp>

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
