#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <Bureaucrat.hpp>
#include <Form.hpp>
#include <iostream>
#include <fstream>
#include <string>

class ShrubberyCreationForm : public Form
{
	public:
		explicit ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
		virtual ~ShrubberyCreationForm();


	private:
		ShrubberyCreationForm();

		static const std::string shrubbery_name_;
		static const int require_sign_to_grade_ = 145;
		static const int require_exe_to_grade_ = 137;
		virtual void action() const;
};

#endif
