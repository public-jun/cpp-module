#include <Bureaucrat.hpp>
#include <ShrubberyCreationForm.hpp>
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

// void	printFormInfo(const std::string &name, int grade_to_sign)
// {
// 	std::cout << "[ Form(name, grade_to_sign) = " << std::flush;
// 	std::cout << CYAN
// 			  << "(" << name << ", " << grade_to_sign << ") ]" << END << std::endl;
// }

// void testConstructor(const std::string &name, int grade_to_sign, int grade_to_exe)
// {
// 	printFormInfo(name, grade_to_sign);
// 	try
// 	{
// 		Form a(name, grade_to_sign, grade_to_exe);
// 		std::cout << BOLD << a << END << "\n" << std::endl;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << RED << e.what() << END << '\n' << std::endl;
// 	}
// }

// void	testSignForm(std::string f_name, int grade_to_sign, int grade_to_exe)
// {
// 	Bureaucrat bob("bob", 10);
// 	printBureaucratInfo(bob);

// 	printFormInfo(f_name, grade_to_sign);
// 	Form form(f_name, grade_to_sign, grade_to_exe);
// 	bob.signForm(form);
// 	std::cout << std::endl;
// }

int main(void)
{
	{
		printTestTitle("----------SHRUBBERY TEST---------");
		ShrubberyCreationForm shrubbery("hoge");
		Bureaucrat b_top("one", 1);
		printBureaucratInfo(b_top);

		ShrubberyCreationForm s_form("hoge");
		b_top.signForm(s_form);
		b_top.executeForm(s_form);
		std::cout << std::endl;

		// Bureaucrat b_middle("mid", 140);
		// printBureaucratInfo(b_middle);
		// Bureaucrat b_last("last", 150);
		// printBureaucratInfo(b_last);
	}

	{
		printTestTitle("----------SIGNFORM TEST---------");

		// testSignForm("entry", 1, 42);
		// testSignForm("entry", 150, 42);
	}

	return (0);
}
