#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <Form.hpp>
#include <string>
#include <iostream>
#include <exception>

class Form;

class Bureaucrat
{
	public:
		Bureaucrat();
		explicit Bureaucrat(std::string name);
		explicit Bureaucrat(int grade);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();

		const std::string GetName() const;
		int GetGrade() const;

		static bool IsGradeToohigh(int grade);
		static bool IsGradeTooLow(int grade);

		void IncrementGrade(); // 3->2
		void DecrementGrade(); // 140-> 141

		void signForm(const Form &form) const;

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

		private :
			// 1(high) <= range <= 150(low)
			static const int lowest_grade_ = 150;
			static const int highest_grade_ = 1;
			const std::string name_;
			int grade_;
};

std::ostream &operator<<(std::ostream &os , const Bureaucrat &a);

#endif
