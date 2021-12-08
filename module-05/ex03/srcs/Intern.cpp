#include <Intern.hpp>
#include <PresidentialPardonForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <ShrubberyCreationForm.hpp>
#include <iostream>
#include <string>

const std::string Intern::form_names_[3] =
{
	"shrubbery creation",
	"robotomy request",
	"PresidentialPardonForm"
};

Intern::Intern()
{
}

Intern::Intern(const Intern &)
{
}

Intern &Intern::operator=(const Intern &)
{
	return (*this);
}

Intern::~Intern()
{
}

Form *Intern::makeForm(const std::string &form_name, const std::string &target)
{
	Form *(*make_form[3])(const std::string &target) =
	{
		&PresidentialPardonForm::create,
		&RobotomyRequestForm::create,
		&ShrubberyCreationForm::create
	};

	for(unsigned int i = 0; i < total_forms; ++i)
	{
		if (form_name == form_names_[i])
		{
			std::cout << "Intern creates " << form_name << std::endl;
			return (make_form[i](target));
		}
	}
	throw (NotKnownForm());
}

const char *Intern::NotKnownForm::what() const throw()
{
	return ("Intern cannot create NotKnownForm");
}
