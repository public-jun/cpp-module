#include <span.hpp>

Span::Span(unsigned int n)
{
	size_ = n;
	v_.reserve(size_);
}
