#include <RobotomyRequestForm.hpp>
#include <color.hpp>

const std::string RobotomyRequestForm::robotomy_name_ = "robotomyRequest";

RobotomyRequestForm::RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) :
	Form(robotomy_name_, target, require_sign_to_grade_, require_exe_to_grade_)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
{
	*this = other;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	(void) other;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::action() const
{
	srand(time(NULL));

	if (rand() % 2)
	{
		std::cout << GREEN
				  << "Bzzzzzz!!, "
				  << GetTarget()
				  << " has been robotomized success"
				  << END << std::endl;
	}
	else
	{
		std::cout << RED
				  << GetTarget() << " has been robotomized fail"
				  << END << std::endl;
	}

}
