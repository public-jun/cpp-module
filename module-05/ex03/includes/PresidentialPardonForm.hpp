#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <Bureaucrat.hpp>
#include <Form.hpp>
#include <iostream>
#include <fstream>
#include <string>

class PresidentialPardonForm : public Form
{
	public:
		explicit PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm &other);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
		virtual ~PresidentialPardonForm();

		static Form *create(const std::string &target);

	private:
		PresidentialPardonForm();

		static const std::string presidential_name_;
		static const int require_sign_to_grade_ = 25;
		static const int require_exe_to_grade_ = 5;
		virtual void action() const;
};

#endif
