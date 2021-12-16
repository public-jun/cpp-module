#include <easyfind.hpp>
#include <color.hpp>
#include <vector>
#include <list>
#include <deque>
#include <set>

void printTestTitle(std::string title)
{
	std::cout << "\n"
			  << CYAN
			  << title
			  << " TEST"
			  << END << std::endl;
}

int main(void)
{
	const int a[] = {1, 33, 22, 55, 44};
	for (std::size_t i = 0; i < 5; ++i)
	{
		std::cout << std::setw(3) << "[" << i << "]: " << a[i] << std::endl;
	}

	{
		printTestTitle("VECTOR");
		std::vector<int> v(a, a + 5);
		testEasyFind(v, 66);
		testEasyFind(v, 1);
	}

	{
		printTestTitle("LIST");
		std::list<int> l(a, a + 5);
		testEasyFind(l, 77);
		testEasyFind(l, 44);
	}

	{
		printTestTitle("DEQUE");
		std::deque<int> d(a, a + 5);
		testEasyFind(d, 100);
		testEasyFind(d, 22);
	}

	{
		printTestTitle("SET");
		std::set<int> s(a, a + 5);
		int i = 0;
		for (std::set<int>::iterator it = s.begin(); it != s.end(); ++it)
		{
			std::cout << std::setw(3) << "[" << i++ << "]: " << *it << std::endl;
		}
		testEasyFind(s, 42);
		testEasyFind(s, 33);
	}

	{
		printTestTitle("MULTI SET");
		std::multiset<int> ms(a, a + 5);
		int i = 0;
		for (std::set<int>::iterator it = ms.begin(); it != ms.end(); ++it)
		{
			std::cout << std::setw(3) << "[" << i++ << "]: " << *it << std::endl;
		}
		testEasyFind(ms, -1);
		testEasyFind(ms, 55);
	}

	return 0;
}
