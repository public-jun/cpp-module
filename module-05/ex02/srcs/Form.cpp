#include <Form.hpp>
#include <color.hpp>

Form::Form() :
	name_("no_name"),
	target_("no_name"),
	is_signed_(false),
	grade_to_sign_(lowest_grade_),
	grade_to_execute_(lowest_grade_)
{
}


Form::Form(std::string name, std::string target, int grade_to_sign, int grade_to_execute) :
	name_(name),
	target_(target),
	is_signed_(false),
	grade_to_sign_(grade_to_sign),
	grade_to_execute_(grade_to_execute)
{
	if (Bureaucrat::IsGradeToohigh(grade_to_sign) || Bureaucrat::IsGradeToohigh(grade_to_execute))
	{
		throw (GradeTooHighException("Exception in constructor. Grade is too HIGH!!"));
	}
	else if (Bureaucrat::IsGradeTooLow(grade_to_sign) || Bureaucrat::IsGradeTooLow(grade_to_execute))
	{
		throw (GradeTooLowException("Exception in constructor. Grade is too LOW!!"));
	}
}

Form::Form(const Form &other) :
	name_(other.GetName()),
	target_(other.GetTarget()),
	is_signed_(false),
	grade_to_sign_(other.GetGradeToSign()),
	grade_to_execute_(other.GetGradeToExecute())
{
}


Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		is_signed_ = other.GetIsSigned();
	}
	return (*this);
}

Form::~Form()
{
}

const std::string Form::GetName() const
{
	return (name_);
}

const std::string Form::GetTarget() const
{
	return (target_);
}

bool Form::GetIsSigned() const
{
	return (is_signed_);
}

int Form::GetGradeToSign() const
{
	return (grade_to_sign_);
}

int Form::GetGradeToExecute() const
{
	return (grade_to_execute_);
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (is_signed_)
	{
		return ;
	}
	if (grade_to_sign_ < bureaucrat.GetGrade())
	{
		throw (GradeTooLowException("exception in beSigned. Grade is too LOW!!"));
	}
	is_signed_ = true;
}

void Form::execute(const Bureaucrat &executor) const
{
	if (!is_signed_)
	{
		throw (NotSignedException());
	}
	if (grade_to_execute_ < executor.GetGrade())
	{
		throw (GradeTooLowException("exception in execute. Grade is too LOW!!"));
	}
	action();
}


Form::GradeTooHighException::GradeTooHighException(const char *msg) :
	msg_(msg)
{
}

const char *Form::GradeTooHighException::what() const throw()
{
	return (msg_);
}

Form::GradeTooLowException::GradeTooLowException(const char *msg) :
	msg_(msg)
{
}

const char *Form::GradeTooLowException::what() const throw()
{
	return (msg_);
}

const char *Form::NotSignedException::what() const throw()
{
	return ("FORM is not signed");
}

std::ostream &operator<<(std::ostream &os, const Form &a)
{
	//Form info
	//name is
	//Form is signed:
	//Grade to sign:
	//Grade to execute:
	os << BOLD
	   << "------Form info------\n"
	   << "name is " << a.GetName() << "\n"
	   << "Form is " << (a.GetIsSigned() ? "signed" : "not signed") << "\n"
	   << "target is " << a.GetTarget() << "\n"
	   << "Grade to sign :" << std::to_string(a.GetGradeToSign()) << "\n"
	   << "Grade to execute :" << std::to_string(a.GetGradeToExecute()) << "\n"
	   << END;
	return (os);
}
