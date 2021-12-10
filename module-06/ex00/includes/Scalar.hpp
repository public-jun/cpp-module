#ifndef SCALAR_HPP
#define SCALAR_HPP

#include <string>
#include <iostream>
#include <exception>
#include <locale>

class Scalar
{
	public:
		explicit Scalar(const std::string &literal_value);
		Scalar(const Scalar &other);
		Scalar &operator=(const Scalar &);
		~Scalar();

		typedef enum {
			kDef,
			kNinf,
			kPinf,
			kNan,
			kChar,
			kInt,
			kFloat,
			KDouble
		} Types;

		void convert();
		const std::string getLiteralValue() const;

	private:
		Scalar();


		const std::string literal_value_;
		Types type_;

		Types checkType();
};

#endif
