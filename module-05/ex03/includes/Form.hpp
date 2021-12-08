#ifndef FORM_HPP
#define FORM_HPP

#include <Bureaucrat.hpp>
#include <iostream>
#include <string>

class Bureaucrat;

class Form
{
	public:
		Form();
		Form(std::string name, std::string target, int grade_to_sign, int grade_to_execute);
		virtual ~Form();

		//Getter all atributes
		const std::string GetName() const;
		const std::string GetTarget() const;
		bool GetIsSigned() const;
		int GetGradeToSign() const;
		int GetGradeToExecute() const;

		void beSigned(const Bureaucrat &bureaucrat);
		void execute(const Bureaucrat &executor) const;

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

		class NotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private:
		Form(const Form &other);
		Form &operator=(const Form &other);

		static const int lowest_grade_ = 150;
		static const int highest_grade_ = 1;

		const std::string name_;
		const std::string target_;
		bool is_signed_;
		const int grade_to_sign_;
		const int grade_to_execute_;

		virtual void action() const = 0;
};

// << oeprator overload
std::ostream &operator<<(std::ostream &os, const Form &a);

#endif
