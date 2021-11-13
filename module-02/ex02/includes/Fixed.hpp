#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <climits>

class Fixed
{
	public:
		Fixed();
		Fixed(int value);
		Fixed(float value);
		Fixed &operator=(const Fixed &rhs);
		~Fixed();
		Fixed(const Fixed &rhs);

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;

		// Six comparison operators over load
		bool operator>(const Fixed &rhs) const;
		bool operator<(const Fixed &rhs) const;
		bool operator>=(const Fixed &rhs) const;
		bool operator<=(const Fixed &rhs) const;
		bool operator==(const Fixed &rhs) const;
		bool operator!=(const Fixed &rhs) const;

		// Four arithmetic operators over load
		Fixed operator+(const Fixed &rhs) const;
		Fixed operator-(const Fixed &rhs) const;
		Fixed operator*(const Fixed &rhs) const;
		Fixed operator/(const Fixed &rhs) const;

		Fixed operator+(void) const;
		Fixed operator-(void) const;

		// increment, decrement operators
		Fixed &operator++(void);
		Fixed operator++(int);
		Fixed &operator--(void);
		Fixed operator--(int);

		// min, max function
		static Fixed &min(Fixed &lhs, Fixed &rhs);
		static const Fixed &min(const Fixed &lhs, const Fixed &rhs);
		static Fixed &max(Fixed &lhs, Fixed &rhs);
		static const Fixed &max(const Fixed &lhs, const Fixed &rhs);

	private:
		int raw_value_;
		const static int fractional_bits_ = 8;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif
