#include <Bureaucrat.hpp>
#include <Form.hpp>
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

void	printFormInfo(const std::string &name, int grade_to_sign)
{
	std::cout << "[ Form(name, grade_to_sign) = " << std::flush;
	std::cout << CYAN
			  << "(" << name << ", " << grade_to_sign << ") ]" << END << std::endl;
}

void testConstructor(const std::string &name, int grade_to_sign, int grade_to_exe)
{
	printFormInfo(name, grade_to_sign);
	try
	{
		Form a(name, grade_to_sign, grade_to_exe);
		std::cout << BOLD << a << END << "\n" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << END << '\n' << std::endl;
	}
}

void	testSignForm(std::string f_name, int grade_to_sign, int grade_to_exe)
{
	Bureaucrat bob("bob", 10);
	printBureaucratInfo(bob);

	printFormInfo(f_name, grade_to_sign);
	Form form(f_name, grade_to_sign, grade_to_exe);
	bob.signForm(form);
	std::cout << std::endl;
}

int main(void)
{
	{
		printTestTitle("----------CONSTRUCTOR TEST---------");

		printTestTitle("< Grade to sign PART >");
		testConstructor("entry", -42, 42);
		testConstructor("entry", 0, 42);
		testConstructor("entry", 1, 42);
		testConstructor("entry", 42, 42);
		testConstructor("entry", 150, 42);
		testConstructor("entry", 151, 42);

		printTestTitle("< Grade to exe PART >");
		testConstructor("booking", 42, -42);
		testConstructor("booking", 42, 0);
		testConstructor("booking", 42, 1);
		testConstructor("booking", 42, 42);
		testConstructor("booking", 42, 150);
		testConstructor("booking", 42, 151);
	}

	{
		printTestTitle("----------SIGNFORM TEST---------");

		testSignForm("entry", 1, 42);
		testSignForm("entry", 150, 42);
	}

	return (0);
}
