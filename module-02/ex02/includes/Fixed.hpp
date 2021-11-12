#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(int value);
		Fixed(float value);
		Fixed& operator=(const Fixed& rhs);
		~Fixed();
		Fixed(const Fixed& rhs);

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;

	private:
		int raw_value_;
		const static int fractional_bits_ = 8;
};

std::ostream &operator<<(std::ostream& os, const Fixed& fixed);

#endif
