#include <Bureaucrat.hpp>
#include <ShrubberyCreationForm.hpp>
#include <PresidentialPardonForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <Form.hpp>
#include <Intern.hpp>
#include <color.hpp>
#include <iostream>

void printTestTitle(std::string title)
{
	std::cout << "\n" << BACK_GREEN << BLACK << title << END << "\n" << std::endl;
}

void	printBureaucratInfo(const Bureaucrat &b)
{
	std::cout << "[ Buruaucrat(name, grade) = " << std::flush;
	std::cout << BLUE
			  << "(" << b.GetName() << ", " << b.GetGrade() << ") ]"
			  << END << std::endl;
}

void testForm(Bureaucrat &b, Form &f)
{
	printBureaucratInfo(b);

	std::cout << BOLD << f << END << std::endl;
	b.signForm(f);
	b.executeForm(f);
	std::cout << std::endl;
}


int main(void)
{
	Bureaucrat b_top("top", 1);
	{
		printTestTitle("ROBOTMY TEST");
		Intern someRandomIntern;
		Form *rrf;
		try
		{
			rrf = someRandomIntern.makeForm("robotomy request", "Bender");
			testForm(b_top, *rrf);
			delete rrf;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		printTestTitle("SHRUBBERY TEST");
		Intern someRandomIntern;
		Form *rrf;
		try
		{
			rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
			testForm(b_top, *rrf);
			delete rrf;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		printTestTitle("PRESIDENTIAL TEST");
		Intern someRandomIntern;
		Form *rrf;
		try
		{
			rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
			testForm(b_top, *rrf);
			delete rrf;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		printTestTitle("WRONG FORM TEST");
		Intern someRandomIntern;
		Form *rrf;
		try
		{
			rrf = someRandomIntern.makeForm("wrong request", "Bender");
			testForm(b_top, *rrf);
			delete rrf;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	return (0);
}
