#include <Fixed.hpp>

Fixed::Fixed() : raw_value_(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int value) {
	std::cout << "Int constructor called" << std::endl;
	this->raw_value_ = value << fractional_bits_;
}

Fixed::Fixed(float value) {
	std::cout << "Float constructor called" << std::endl;
	this->raw_value_ = static_cast<int>(std::roundf(value * (1 << fractional_bits_)));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &rhs) {
	std::cout << "Assignation operator called" << std::endl;
	if (this != &rhs) {
		this->raw_value_ = rhs.getRawBits();
	}
	return (*this);
}

Fixed::Fixed(const Fixed &rhs) {
	std::cout << "Copy constructor called" << std::endl;
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
}

int Fixed::toInt(void) const {
	return (this->raw_value_ >> fractional_bits_);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return os;
}
