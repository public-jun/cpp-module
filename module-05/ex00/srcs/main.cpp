#include <Bureaucrat.hpp>
#include <color.hpp>
#include <iostream>

void PrintTestTitle(std::string title)
{
	std::cout << "\n" << BACK_GREEN << title << END << "\n" << std::endl;
}

void PrintTestInfo(std::string name, int grade, std::string append = "")
{
	std::cout << BLUE <<"[ Bureaucrat(name=" << name << ", grade=" << std::to_string(grade) << ")]" << append << END <<std::endl;
}

void TestConstructor(int grade)
{
	std::string name = "bob";

	PrintTestInfo(name, grade);
	try
	{
		Bureaucrat a(name, grade);
		std::cout << BOLD << a << END << "\n" << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << BACK_RED <<e.what() << END << '\n' << std::endl;
	}
}

void TestIncrement(int grade)
{
	std::string name = "Taro";

	PrintTestInfo(name, grade);
	try
	{
		Bureaucrat a(name, grade);
		//before grade
		std::cout << "before: " << std::to_string(a.GetGrade()) << std::endl;
		std::cout << BOLD << a << END << "\n" << std::endl;
		a.IncrementGrade();
		std::cout << "after: " << std::to_string(a.GetGrade()) << std::endl;
		std::cout << BOLD << a << END << "\n" << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << BACK_RED <<e.what() << END << '\n' << std::endl;
	}
}

void TestDecrement(int grade)
{
	std::string name = "Taro";

	PrintTestInfo(name, grade);
	try
	{
		Bureaucrat a(name, grade);
		std::cout << "before: " << std::to_string(a.GetGrade()) << std::endl;
		std::cout << BOLD << a << END << "\n" << std::endl;
		a.DecrementGrade();
		std::cout << "after: " << std::to_string(a.GetGrade()) << std::endl;
		std::cout << BOLD << a << END << "\n" << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << BACK_RED <<e.what() << END << '\n' << std::endl;
	}
}

int main(void)
{
	PrintTestTitle("----------CONSTRUCTOR TEST---------");
	TestConstructor(-42);
	TestConstructor(0);
	TestConstructor(1);
	TestConstructor(42);
	TestConstructor(150);
	TestConstructor(151);

	PrintTestTitle("----------INCREMENT TEST---------");
	TestIncrement(-42);
	TestIncrement(0);
	TestIncrement(1);
	TestIncrement(42);
	TestIncrement(150);
	TestIncrement(151);

	PrintTestTitle("----------DECREMENT TEST---------");
	TestDecrement(-42);
	TestDecrement(0);
	TestDecrement(1);
	TestDecrement(42);
	TestDecrement(150);
	TestDecrement(151);
	return (0);
}
