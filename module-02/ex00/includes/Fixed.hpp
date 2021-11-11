#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
	public:
		Fixed();
		Fixed &operator=(const Fixed &rhs);
		~Fixed();
		Fixed(const Fixed &rhs);
	private:
		int	int_fixed_value_;
		const static int fractional_bits_ = 8;
};

#endif
