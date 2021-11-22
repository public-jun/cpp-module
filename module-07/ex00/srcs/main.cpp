#include <whatever.hpp>
#include <test.hpp>
#include <color.hpp>
#include <iostream>
#include <string>

void printTestTitle(std::string title)
{
	std::cout << "\n"
			  << BACK_GRAY
			  << title
			  << " TEST"
			  << END << std::endl;
}

int main(void)
{
	{
		int a = 2;
		int b = 3;
		::swap(a, b);
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
		std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
		std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
	}

	printTestTitle("SWAP ");
	{
		int int_a = 10;
		int int_b = 20;
		swapTest(int_a, int_b);
		char char_a = 'a';
		char char_b = 'b';
		swapTest(char_a, char_b);
		std::string str_a = "hoge";
		std::string str_b = "val";
		swapTest(str_a, str_b);
		float float_a = 42.424242f;
		float float_b = 10.05f;
		swapTest(float_a, float_b);
		double double_a = 3.141592;
		double double_b = 1234.567;
		swapTest(double_a, double_b);
	}
	printTestTitle("MIN MAX ");
	{
		int int_a = 10;
		int int_b = 20;
		minMaxTest(int_a, int_b);
		int i_c = 42;
		int i_d = 42;
		minMaxTest(i_c, i_d);
		std::string str_a = "hoge42";
		std::string str_b = "hoge100";
		minMaxTest(str_a, str_b);
		float float_a = 42.424242f;
		float float_b = 10.05f;
		minMaxTest(float_a, float_b);
		double double_a = 3.141592;
		double double_b = 1234.567;
		minMaxTest(double_a, double_b);
	}
	return 0;
}
