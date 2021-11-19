#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

#define LOWEST_GRADE 150
#define HIGHEST_GRADE 1

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

		bool IsGradeToohigh(int grade);
		bool IsGradeTooLow(int grade);

		void IncrementGrade(); // 3->2
		void DecrementGrade(); // 140-> 141

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
			const std::string name_;
			// 1(high) <= range <= 150(low)
			int grade_;
};

std::ostream &operator<<(std::ostream &os , const Bureaucrat &a);

#endif
