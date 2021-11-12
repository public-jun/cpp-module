#include <Fixed.hpp>

Fixed::Fixed() : raw_value_(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
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
	std::cout << "getRawBits member function called" << std::endl;
	return (this->raw_value_);
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->raw_value_ = raw;
}
