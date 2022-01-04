#include <Scalar.hpp>

const std::string Scalar::kScienceValue[3] =
{
	"-inf",
	"+inf",
	"nan"
};

Scalar::Scalar() {}

Scalar::Scalar(std::string literal_value) :
	literal_value_(literal_value),
	type_(kDef),
	store_value_(0.0),
	over_flow_c_(false),
	over_flow_i_(false),
	over_flow_f_(false),
	over_flow_d_(false) {}

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

namespace
{
	bool isChar(const std::string &value)
	{
		if (value.length() == 1
			&& std::isprint(value[0])
			&& !std::isdigit(value[0]))
			return (true);
		return (false);

	}
}

namespace
{
	bool isInt(const std::string &value)
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
}

namespace
{
	bool isDouble(const std::string &value)
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
}

namespace
{
	bool isFloat(const std::string &value)
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
		return (kFloat);
	}
	return (kDef);
}

void Scalar::storeValue()
{
	std::istringstream iss(literal_value_);

	if (type_ == kChar)
	{
		store_value_ = static_cast<double>(literal_value_[0]);
	}
	else
	{
		iss >> store_value_;
	}
}

void Scalar::checkOverFlow()
{
	if (store_value_ < static_cast<double>(std::numeric_limits<char>::min())
		|| static_cast<double>(std::numeric_limits<char>::max()) < store_value_)
		over_flow_c_ = true;
	if (store_value_ < static_cast<double>(std::numeric_limits<int>::min())
		|| static_cast<double>(std::numeric_limits<int>::max()) < store_value_)
		over_flow_i_ = true;
	if (store_value_ < static_cast<double>(-std::numeric_limits<float>::max())
		|| static_cast<double>(std::numeric_limits<float>::max()) < store_value_)
		over_flow_f_ = true;
}

bool Scalar::isScienceValue()
{
	if (type_ == kNan || type_ == kNinf || type_ == kPinf)
	{
		return (true);
	}
	return (false);
}

void Scalar::printChar()
{
	std::cout << "char: " << std::flush;

	char c_value = static_cast<char>(store_value_);
	if (over_flow_c_ || type_ == kDef || isScienceValue())
		std::cout << "impossible" << std::endl;
	else if (std::isprint(c_value))
		std::cout << '\'' << c_value << '\'' << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
}

void Scalar::printInt()
{
	std::cout << "int: " << std::flush;

	if (over_flow_i_ || type_ == kDef || isScienceValue())
	{
		if (type_ == kInt)
		{
			over_flow_f_ = true;
			over_flow_d_ = true;
		}
		std::cout << "impossible" << std::endl;
	}
	else
	{
		int i_value = static_cast<int>(store_value_);
		std::cout << i_value << std::endl;
	}
}

void Scalar::printScienceValue()
{
	for(unsigned int i = 0; i <= kNan; ++i)
	{
		if (type_ == i)
			std::cout << kScienceValue[i] << std::flush;
	}
}

void Scalar::printFloat()
{
	std::cout << "float: " << std::flush;

	if (isScienceValue())
	{
		printScienceValue();
		std::cout << "f" << std::endl;
	}
	else if (type_ == kDef)
	{
		if (type_ == kFloat)
		{
			over_flow_d_ = true;
		}
		std::cout << "impossible" << std::endl;
	}
	else
	{
		float f_value = static_cast<float>(store_value_);
		unsigned int pos = 0;

		if (std::floor(f_value) == f_value)
			pos = 1;
		else
			pos = 5;
		std::cout << std::fixed << std::setprecision(pos) << f_value << "f" << std::endl;
	}
}

void Scalar::printDouble()
{
	std::cout << "double: " << std::flush;

	if (isScienceValue())
	{
		printScienceValue();
		std::cout << std::endl;
	}
	else if (over_flow_d_ || type_ == kDef)
	{
		std::cout << "impossible" << std::endl;
	}
	else
	{
		double d_value = store_value_;
		unsigned int pos = 0;

		if (std::floor(d_value) == d_value)
			pos = 1;
		else
			pos = 15;
		std::cout << std::fixed << std::setprecision(pos) << d_value << std::endl;
	}
}


void Scalar::printAll()
{
	printChar();
	printInt();
	printFloat();
	printDouble();
}

void Scalar::convert()
{
	type_ = checkType();
	storeValue();
	checkOverFlow();
	printAll();
}
