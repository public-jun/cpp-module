#include <Scalar.hpp>

Scalar::Scalar() {}

Scalar::Scalar(std::string literal_value) :
	literal_value_(literal_value),
	type_(kDef),
	store_value_(0.0),
	over_flow_c_(false),
	over_flow_i_(false),
	over_flow_f_(false) {}

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
	std::cout << "TEST TYPE" << std::endl;
	if (type == Scalar::kNinf)
		std::cout << "-inf" << std::endl;
	else if (type == Scalar::kPinf)
		std::cout << "+inf" << std::endl;
	else if (type == Scalar::kNan)
		std::cout << "nan" << std::endl;
	else if (type == Scalar::kChar)
		std::cout << "char" << std::endl;
	else if (type == Scalar::kInt)
		std::cout << "int" << std::endl;
	else if (type == Scalar::KDouble)
		std::cout << "double" << std::endl;
	else if (type == Scalar::kFloat)
		std::cout << "float" << std::endl;
	else
		std::cout << "default" << std::endl;
	std::cout << std::endl;
}

static bool isChar(const std::string &value)
{
	if (value.length() == 1
		&& std::isprint(value[0])
		&& !std::isdigit(value[0]))
		return (true);
	return (false);

}

static bool isInt(const std::string &value)
{
	unsigned int i = 0;
	std::string::size_type len = value.length();

	if (value[i] == '0')
	{
		if (len == 1)
			return (true);
		else
			return (false);
	}
	if (value[i] == '+' || value[i] == '-')
		++i;
	while (value[i])
	{
		if (!std::isdigit(value[i]))
			break;
		++i;
	}
	if (len == static_cast<std::string::size_type>(i))
		return (true);
	return (false);
}

static bool isDouble(const std::string &value)
{
	std::string::size_type decimal_pos = value.find_first_of(".", 0);
	std::string::size_type len = value.length();
	std::string::size_type i = 0;

	if (decimal_pos == std::string::npos || decimal_pos == 0 || decimal_pos != value.find_last_of(".", len - 1) || decimal_pos == len - 1 )
		return (false);
	if (value[i] == '+' || value[i] == '-')
		++i;
	if (value[i] == '.')
		return (false);
	while (isdigit(value[i]))
		++i;
	if (i != decimal_pos)
		return (false);
	++i;
	while (isdigit(value[i]))
		++i;
	if (len == static_cast<std::string::size_type>(i))
		return (true);
	return (false);
}

static bool isFloat(const std::string &value)
{
	std::string::size_type decimal_pos = value.find_first_of(".", 0);
	std::string::size_type len = value.length();
	std::string::size_type i = 0;

	if (decimal_pos == std::string::npos || decimal_pos == 0 || decimal_pos != value.find_last_of(".", len - 1) || decimal_pos == len - 1 )
		return (false);
	if (value[i] == '+' || value[i] == '-')
		++i;
	if (value[i] == '.')
		return (false);
	while (isdigit(value[i]))
		++i;
	if (i != decimal_pos)
		return (false);
	++i;
	while (isdigit(value[i]))
		++i;
	if (value[i] == 'f' && len == static_cast<std::string::size_type>(i + 1))
		return (true);
	return (false);
}

Scalar::Types Scalar::checkType()
{
	const std::string literal_value = getLiteralValue();
	std::string::size_type len = literal_value.length();

	if (literal_value == "-inff" || literal_value == "-inf")
		return (kNinf);
	else if (literal_value == "+inff" || literal_value == "+inf")
		return (kPinf);
	else if (literal_value == "nanf" || literal_value == "nan")
		return (kNan);
	else if (isChar(literal_value))
		return (kChar);
	else if (isInt(literal_value))
		return (kInt);
	else if (isDouble(literal_value))
		return (KDouble);
	else if (isFloat(literal_value))
	{
		literal_value_ = literal_value.substr(0, len - 1);
		std::cout << literal_value_ << std::endl;
		return (kFloat);
	}
	return (kDef);
}

void Scalar::storeValue()
{
	std::istringstream iss(literal_value_);
	iss >> store_value_;
}

static void testCheckStoreValue(double value)
{
	std::cout << "TEST VALUE" << std::endl;
	std::cout << value << std::endl;
	std::cout << std::endl;
}

void Scalar::checkOverFlow()
{
	if (store_value_ < std::numeric_limits<char>::min()
		|| std::numeric_limits<char>::max() < store_value_)
		over_flow_c_ = true;
	if (store_value_ < std::numeric_limits<int>::min()
		|| std::numeric_limits<int>::max() < store_value_)
		over_flow_i_ = true;
	if (store_value_ < -std::numeric_limits<float>::max()
		|| std::numeric_limits<float>::max() < store_value_)
		over_flow_f_ = true;
}

void Scalar::testCheckOverFlow()
{
	std::cout << "TEST OVER FLOW" << std::endl;
	if (over_flow_c_)
		std::cout << "over flow char" << std::endl;
	if (over_flow_i_)
		std::cout << "over flow int" << std::endl;
	if (over_flow_f_)
		std::cout << "over flow float" << std::endl;
	std::cout << std::endl;
}

void Scalar::convert()
{
	type_ = checkType();
	testCheckType(type_);
	storeValue();
	testCheckStoreValue(store_value_);
	checkOverFlow();
	testCheckOverFlow();
}
