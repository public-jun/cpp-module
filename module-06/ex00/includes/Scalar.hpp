#ifndef SCALAR_HPP
#define SCALAR_HPP

#include <string>
#include <exception>

class Scalar
{
	public:
		Scalar(std::string literal_value);
		Scalar(const Scalar &other);
		Scalar &operator=(const Scalar &other);
		~Scalar();

		const std::string GetLiteralValue() const;
		void LiteralToStore();

		bool IsNumeric() const;


		void ToChar() const;
		// StrToInt();
		// StrToFloat();
		// StrToDouble();

		class ImpossibleException : public std::exception
		{
			public:
				ImpossibleException(const char *msg);
				virtual const char *what() const throw();

			private:
				const char *msg_;
		};

		class NonDisplayableException: public std::exception
		{
			public:
				NonDisplayableException(const char *msg);
				virtual const char *what() const throw();

			private:
				const char *msg_;
		};

	private:
		const std::string literal_value_;
		// const double store_value_;
};

#endif
