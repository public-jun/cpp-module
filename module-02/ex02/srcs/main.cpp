#include <Fixed.hpp>
#include <iomanip>

void	test(const std::string formula, Fixed calced)
{
	std::cout << std::setw(15) << formula << calced << std::endl;
}

void	tests(std::string l_string, std::string r_string, Fixed l_fixed, Fixed r_fixed)
{
	Fixed l = Fixed(l_fixed);
	Fixed r(r_fixed);
	std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
	std::cout << "(" << l_string << " and " << r_string << ")" << std::endl;
	test(l_string + " : ", l);
	test(r_string + " : ", r);
	test(l_string + " + " + r_string + ": ", l + r);
	test(r_string + " + " + l_string + ": ", r + l);
	test(l_string + " - " + r_string + ": ", l - r);
	test(r_string + " - " + l_string + ": ", r - l);
	test(l_string + " * " + r_string + ": ", l * r);
	test(r_string + " * " + l_string + ": ", r * l);
	test(l_string + " / " + r_string + ": ", l / r);
	test(r_string + " / " + l_string + ": ", r / l);
	test("+" + l_string + " : ", l);
	test("+" + r_string + " : ", r);
	test("-" + l_string + " : ", l);
	test("-" + r_string + " : ", r);
	test(l_string + " < " + r_string + ": ", l < r);
	test(r_string + " < " + l_string + ": ", r < l);
	test(l_string + " > " + r_string + ": ", l > r);
	test(r_string + " > " + l_string + ": ", r > l);
	test(l_string + " <= " + r_string + ": ", l <= r);
	test(r_string + " <= " + l_string + ": ", r <= l);
	test(l_string + " >= " + r_string + ": ", l >= r);
	test(r_string + " >= " + l_string + ": ", r >= l);
	test(l_string + " == " + r_string + ": ", l == r);
	test(r_string + " == " + l_string + ": ", r == l);
	test(l_string + " != " + r_string + ": ", l != r);
	test(r_string + " != " + l_string + ": ", r != l);
	test("min(" + l_string +", "+ r_string +") : ", Fixed::min(l, r));
	test("max(" + l_string +", "+ r_string +") : ", Fixed::max(l, r));
	std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << std::endl;
}

int main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;

	tests("0", "1.5", 0, 1.5f);
	tests("2", "3", 2, 3);
	tests("2", "0.5", 2, 0.5f);
	tests("3", "0.1", 3, 0.1f);
	tests("-1", "2", -1, 2);
	tests("1.1", "-0.3", 1.1f, -0.3f);
	tests("1.5", "2", 1.5f, 2);
	tests("-7", "13", -7, 13);
	tests("-3", "13", -3, 13);
	tests("1.1", "-0.3", 1.1f, -0.3f);
	tests("1.004", "1.004", 1.004f, 1.004f);
	tests("2.5", "1.25", 2.5f, 1.25f);
	tests("2.5", "0.125", 2.5f, 0.125f);
	tests("0", "0.4", 0, 0.4f);
	tests("10.004", "1", 10.004f, 1);
	tests("10.004", "-2", 10.004f, -2);
	tests("10.004", "0.8", 10.004f, 0.8f);
	tests("1.1", "-0.3", 1.1f, -0.3f);
	tests("1.1", "0.3", 1.1f, 0.3f);
	tests("0.1", "1.3", 0.1f, 1.3f);
	tests("10", "5.33", 10, 5.33f);
	return 0;
}
