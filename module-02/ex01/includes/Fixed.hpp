#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
	public:
		Fixed(const int );
		Fixed& operator=(const Fixed& rhs);
		~Fixed();
		Fixed(const Fixed& rhs);
		int getRawBits(void) const;
		void setRawBits(int const raw);

	private:
		int raw_value_;
		const static int fractional_bits_ = 8;
};

#endif
