#ifndef ROBOTOMYREQUESTFORM
#define ROBOTOMYREQUESTFORM

#include <Bureaucrat.hpp>
#include <Form.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public Form
{
	public:
		explicit RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &other);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
		virtual ~RobotomyRequestForm();

	private:
		RobotomyRequestForm();

		static const std::string robotomy_name_;
		static const int require_sign_to_grade_ = 72;
		static const int require_exe_to_grade_ = 45;
		virtual void action() const;
};

#endif
