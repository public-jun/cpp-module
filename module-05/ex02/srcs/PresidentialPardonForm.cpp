#include <PresidentialPardonForm.hpp>

const std::string PresidentialPardonForm::presidential_name_ = "PresidentialPardon";

PresidentialPardonForm::PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) :
	Form(presidential_name_, target, require_sign_to_grade_, require_exe_to_grade_)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
{
	*this = other;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	(void) other;
	return (*this);
}
PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::action() const
{
	std::cout << GetTarget() << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
