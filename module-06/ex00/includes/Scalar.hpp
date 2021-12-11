#ifndef SCALAR_HPP
#define SCALAR_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <limits>
#include <cmath>
// #include <exception>
#include <locale>

class Scalar
{
	public:
		explicit Scalar(std::string literal_value);
		Scalar(const Scalar &other);
		Scalar &operator=(const Scalar &);
		~Scalar();

		typedef enum {
			kNinf,
			kPinf,
			kNan,
			kChar,
			kInt,
			kFloat,
			KDouble,
			kDef
		} Types;

		void convert();
		const std::string getLiteralValue() const;

	private:
		Scalar();

		static const std::string kScienceValue[3];

		std::string literal_value_;
		Types type_;
		double store_value_;
		bool over_flow_c_;
		bool over_flow_i_;
		bool over_flow_f_;
		bool over_flow_d_;

		Types checkType();
		void storeValue();
		void checkOverFlow();
		void testCheckOverFlow();

		bool isScienceValue();
		void printScienceValue();
		void printAll();
		void printChar();
		void printInt();
		void printFloat();
		void printDouble();
};

#endif
