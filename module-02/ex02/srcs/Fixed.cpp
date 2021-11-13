#include <Fixed.hpp>

Fixed::Fixed() : raw_value_(0) {
}

Fixed::Fixed(int value) {
	this->raw_value_ = value << fractional_bits_;
}

Fixed::Fixed(float value) {
	this->raw_value_ = static_cast<int>(std::roundf(value * (1 << fractional_bits_)));
}

Fixed::~Fixed() {
}

Fixed &Fixed::operator=(const Fixed &rhs) {
	if (this != &rhs) {
		this->raw_value_ = rhs.getRawBits();
	}
	return (*this);
}

Fixed::Fixed(const Fixed &rhs) {
	*this = rhs;
}

int Fixed::getRawBits(void) const {
	return (this->raw_value_);
}

void Fixed::setRawBits(int const raw) {
	this->raw_value_ = raw;
}

float Fixed::toFloat(void) const {
	return (static_cast<float>(this->raw_value_) / (1 << fractional_bits_));
	// int value_int = raw_value_;
	// value_int >>= fractional_bits_;
	// float value = value_int;
	// float value_to_add = 1;
	// for (int i = 0; i < fractional_bits_; ++i)
	// {
	// 	value_to_add /= 2;
	// 	int mask = 1;
	// 	mask <<= fractional_bits_ - i - 1;
	// 	if (mask & raw_value_)
	// 	{
	// 		value += value_to_add;
	// 	}
	// }
	// return value;
}

int Fixed::toInt(void) const {
	return (this->raw_value_ >> fractional_bits_);
	// int value = raw_value_;
	// value >>= fractional_bits_;
	// if (value < 0)
	// {
	// 	int value_compair = value;
	// 	value_compair <<= fractional_bits_;
	// 	if (raw_value_ != value_compair)
	// 	{
	// 		value += 1;
	// 	}
	// }
	// return value;
}


// Six comparison operators over load
bool Fixed::operator>(const Fixed &rhs) const {
	return (raw_value_ > rhs.getRawBits());
}

bool Fixed::operator<(const Fixed &rhs) const {
	return (raw_value_ < rhs.getRawBits());
}

bool Fixed::operator>=(const Fixed &rhs) const {
	return (raw_value_ >= rhs.getRawBits());
}

bool Fixed::operator<=(const Fixed &rhs) const {
	return (raw_value_ <= rhs.getRawBits());
}

bool Fixed::operator==(const Fixed &rhs) const {
	return (raw_value_ == rhs.getRawBits());
}

bool Fixed::operator!=(const Fixed &rhs) const {
	return (raw_value_ != rhs.getRawBits());
}


// Four arithmetic operators over load
Fixed Fixed::operator+(const Fixed &rhs) const {
	Fixed tmp;

	tmp.setRawBits(raw_value_ + rhs.getRawBits());
	return (tmp);
}

Fixed Fixed::operator-(const Fixed &rhs) const {
	Fixed tmp;

	tmp.setRawBits(raw_value_ - rhs.getRawBits());
	return (tmp);
}

Fixed Fixed::operator*(const Fixed &rhs) const {
	Fixed ret;
	long new_raw_value = raw_value_;

	new_raw_value *= rhs.getRawBits();
	new_raw_value /= (1 << fractional_bits_);
	ret.setRawBits(static_cast<int>(new_raw_value));
	return (ret);
}

Fixed Fixed::operator/(const Fixed &rhs) const {
	Fixed ret;
	long new_raw_value = raw_value_;

	if (rhs.getRawBits() == 0)
	{
		std::cout << "Division by zero is undifined" << std::endl;
		ret.setRawBits(0);
		return (0);
	}
	new_raw_value <<= fractional_bits_;
	new_raw_value /= rhs.getRawBits();
	ret.setRawBits(new_raw_value);
	return (ret);
}

Fixed Fixed::operator+() const {
	return (*this);
}

Fixed Fixed::operator-() const {
	Fixed ret;
	ret.setRawBits(-(this->raw_value_));
	return (ret);
}

//increment, decrement operators
Fixed &Fixed::operator++(void) {
	this->setRawBits(++(this->raw_value_));
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed ret = *this;
	++(*this);
	return (ret);
}

Fixed &Fixed::operator--(void) {
	this->setRawBits(--(this->raw_value_));
	return (*this);
}

Fixed Fixed::operator--(int) {
	Fixed ret = *this;
	--(*this);
	return (ret);
}

Fixed &Fixed::min(Fixed &lhs, Fixed &rhs) {
	return (lhs <= rhs ? lhs : rhs);
}

const Fixed &Fixed::min(const Fixed &lhs, const Fixed &rhs) {
	return (lhs <= rhs ? lhs : rhs);
}

Fixed &Fixed::max(Fixed &lhs, Fixed &rhs) {
	return (lhs >= rhs ? lhs : rhs);
}

const Fixed &Fixed::max(const Fixed &lhs, const Fixed &rhs) {
	return (lhs >= rhs ? lhs : rhs);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return os;
}
