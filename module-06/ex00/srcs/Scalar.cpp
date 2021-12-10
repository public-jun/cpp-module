#include <Scalar.hpp>

Scalar::Scalar() {}

Scalar::Scalar(const std::string &literal_value) :
	literal_value_(literal_value), type_(kDef) {}

Scalar::Scalar(const Scalar &other)
{
	*this = other;
}

Scalar &Scalar::operator=(const Scalar &)
{
	return (*this);
}

Scalar::~Scalar() {}

const std::string Scalar::getLiteralValue() const
{
	return (literal_value_);
}

// 型判定
// char , int , float, double, invalid_type
// -inff +inff nanf , -inf +inf nan

static void testCheckType(Scalar::Types type)
{
	if (type == Scalar::kNinf)
		std::cout << "-inf" << std::endl;
	else if (type == Scalar::kPinf)
		std::cout << "+inf" << std::endl;
	else if (type == Scalar::kNan)
		std::cout << "nan" << std::endl;
	else if (type == Scalar::kChar)
		std::cout << "char" << std::endl;
	else
		std::cout << "default" << std::endl;
}

Scalar::Types Scalar::checkType()
{
	std::string literal_value = getLiteralValue();
	if (literal_value == "-inff" || literal_value == "-inf")
		return (kNinf);
	else if (literal_value == "+inff" || literal_value == "+inf")
		return (kPinf);
	else if (literal_value == "nanf" || literal_value == "nan")
		return (kNan);
	// char
	else if (literal_value.length() == 1 && std::isprint(literal_value[0]) && !std::isdigit(literal_value[0]))
		return (kChar);
	// int
	// float
	// double
	return (kDef);
}

void Scalar::convert()
{
	type_ = checkType();
	testCheckType(type_);
}
