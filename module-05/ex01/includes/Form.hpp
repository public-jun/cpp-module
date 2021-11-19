#ifndef FORM_HPP
#define FORM_HPP

#include <Bureaucrat.hpp>
#include <iostream>
#include <string>

#define LOWEST_GRADE 150
#define HIGHEST_GRADE 1

class Bureaucrat;

class Form
{
	public:
		Form();
		Form(std::string name, int grade_to_sign, int grade_to_execute);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form();

		//Getter all atributes
		const std::string GetName() const;
		bool GetIsSigned() const;
		const int GetGradeToSign() const;
		const int GetGradeToExecute() const;

		void beSigned(const Bureaucrat &bureaucrat);

		class GradeTooHighException : public std::exception
		{
			public:
				GradeTooHighException(const char *msg);
				virtual const char *what() const throw();

			private:
				const char *msg_;
		};

		class GradeTooLowException : public std::exception
		{
			public:
				GradeTooLowException(const char *msg);
				virtual const char *what() const throw();

			private:
				const char *msg_;
		};

	private:
		const std::string name_;
		bool is_signed_;
		//grades has constrains and throw exception
		const int grade_to_sign_;
		const int grade_to_execute_;
};

// << oeprator overload
std::ostream &operator<<(std::ostream &os, const Form &a);

#endif
