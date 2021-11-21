#include <Scalar.hpp>
#include <sstream>
#include <limits>
#include <iomanip>
#include <iostream>

Scalar::Scalar(std::string literal_value) :
	literal_value_(literal_value) {}

Scalar::Scalar(const Scalar &other) :
	literal_value_(other.GetLiteralValue()) {}

Scalar &Scalar::operator=(const Scalar &other)
{
	(void)other;
	return (*this);
}

Scalar::~Scalar() {}

const std::string Scalar::GetLiteralValue() const
{
	return (literal_value_);
}

// bool Scalar::IsNumeric() const
// {
// 	std::string literal_value = this->GetLiteralValue();
// 	if (literal_value)
// 	{
// 		throw (ImpossibleException("impossible"));
// 	}

// 	return (true);
// }

// void Scalar::LiteralToStore()
// {
// 	//空かどうか
// 	if (literal_value_.empty())
// 	{
// 		throw (ImpossibleException("impossible"));
// 	}
// 	//正しいformatかどうか
// }



void Scalar::ToChar() const
{
	double res;

	try
	{
		// valueが適切かどうか判定
		// if (!IsNumeric())
		// {
		// 	throw (ImpossibleException("impossible"));
		// }
		// res = std::numeric_limits<int>::max();
		std::string str = "42.0f";
		std::istringstream iss(str);
		iss >> res;
		// if ((res >= 0 && res < 32) || res == 127)
		// {
		// 	throw (NonDisplayableException("Non displayable"));
		// }
		// else if (res < 32 || res > 126)
		// {
		// 	throw (ImpossibleException("impossible"));
		// }
		// std::cout << "char: " << res << std::endl;
		std::cout << "int: " << static_cast<int>(res) << std::endl;
		std::cout << "float: " << static_cast<float>(res) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(res) << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << "char: " << e.what() << '\n';
	}

}

Scalar::ImpossibleException::ImpossibleException(const char *msg) :
	msg_(msg) {}

const char *Scalar::ImpossibleException::what() const throw()
{
	return (msg_);
}

Scalar::NonDisplayableException::NonDisplayableException(const char *msg) :
	msg_(msg) {}

const char *Scalar::NonDisplayableException::what() const throw()
{
	return (msg_);
}
