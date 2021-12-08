#ifndef INTERN_HPP
#define INTERN_HPP

#include <Form.hpp>
#include <string>
#include <exception>

class Intern
{
	public:
		Intern();
		Intern(const Intern &);
		Intern &operator=(const Intern &);
		~Intern();

		Form *makeForm(const std::string &form_name, const std::string &target);

		class NotKnownForm : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private:
		static const int total_forms = 3;
		static const std::string form_names_[3];
};

#endif
