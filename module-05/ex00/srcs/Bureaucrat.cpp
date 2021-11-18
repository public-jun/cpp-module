#include <Bureaucrat.hpp>
#include <iostream>
#include <color.hpp>

Bureaucrat::Bureaucrat() :
	name_("no_name"), grade_(LOWEST_GRADE)
{
}

Bureaucrat::Bureaucrat(std::string name) :
	name_(name), grade_(LOWEST_GRADE)
{
}

Bureaucrat::Bureaucrat(int grade) : name_("no_name"), grade_(grade)
{
	if (IsGradeToohigh(grade))
	{
		throw (GradeTooHighException("Exception in constructor. Grade is too HIGH!!"));
	}
	else if (IsGradeTooLow(grade))
	{
		throw (GradeTooLowException("Exception in constructor. Grade is too LOW!!"));
	}
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name_(name), grade_(grade)
{
	//gradeのエラー処理
	if (IsGradeToohigh(grade))
	{
		throw (GradeTooHighException("Exception in constructor. Grade is too HIGH!!"));
	}
	else if (IsGradeTooLow(grade))
	{
		throw (GradeTooLowException("Exception in constructor. Grade is too LOW!!"));
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) :
	name_(other.GetName()), grade_(other.GetGrade())
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		grade_ = other.GetGrade();
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
}

// Getter

const std::string Bureaucrat::GetName() const
{
	return (name_);
}

int Bureaucrat::GetGrade() const
{
	return (grade_);
}

// Is_valid_grade

bool Bureaucrat::IsGradeToohigh(int grade)
{
	return (grade < HIGHEST_GRADE);
}

bool Bureaucrat::IsGradeTooLow(int grade)
{
	return (grade > LOWEST_GRADE);
}

// Increment Decrement
void Bureaucrat::IncrementGrade()
{
	if (grade_ == HIGHEST_GRADE)
	{
		throw (GradeTooHighException("Exception in increment. Grade is too HIGH!!"));
	}
	grade_ -= 1;
}

void Bureaucrat::DecrementGrade()
{
	if (grade_ == LOWEST_GRADE)
	{
		throw (GradeTooLowException("Exception in decrement. Grade is too LOW!!"));
	}
	grade_ += 1;
}

// class exceptions

Bureaucrat::GradeTooHighException::GradeTooHighException(const char *msg) :
	msg_(msg)
{
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return (msg_);
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const char *msg) :
	msg_(msg)
{
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return (msg_);
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &a)
{
	//<name>, bureaucrat grade <grade>.
	os << BOLD
	   << a.GetName() << ", bureaucrat grade " << a.GetGrade() << "."
	   << END;
	return (os);
}
