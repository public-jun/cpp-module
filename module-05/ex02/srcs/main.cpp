#include <Bureaucrat.hpp>
#include <ShrubberyCreationForm.hpp>
#include <PresidentialPardonForm.hpp>
#include <Form.hpp>
#include <color.hpp>
#include <iostream>

void printTestTitle(std::string title)
{
	std::cout << "\n" << BACK_GREEN << title << END << "\n" << std::endl;
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
	std::cout << GREEN
			  << (f.GetIsSigned() ? "is signed" : "is not signed ")
			  << END << std::endl;
	b.executeForm(f);
	std::cout << std::endl;
}


int main(void)
{
	{
		printTestTitle("----------SHRUBBERY TEST---------");
		Bureaucrat b_top("top", 1);
		ShrubberyCreationForm s_form("hoge");
		testForm(b_top, s_form);

		Bureaucrat b_middle("mid", 140);
		ShrubberyCreationForm var_form("var");
		testForm(b_middle, var_form);

		Bureaucrat b_last("last", 150);
		ShrubberyCreationForm tokyo_form("tokyo");
		testForm(b_last, tokyo_form);
	}

	{
		printTestTitle("----------PRESIDENTIAL TEST---------");
		Bureaucrat b_top("top", 1);
		PresidentialPardonForm hoge_form("hoge");
		testForm(b_top, hoge_form);

		Bureaucrat b_middle("mid", 140);
		PresidentialPardonForm var_form("var");
		testForm(b_middle, var_form);

		Bureaucrat b_last("last", 150);
		PresidentialPardonForm tokyo_form("tokyo");
		testForm(b_last, tokyo_form);
	}

	{
		printTestTitle("----------SIGNFORM TEST---------");

		// testSignForm("entry", 1, 42);
		// testSignForm("entry", 150, 42);
	}

	return (0);
}
