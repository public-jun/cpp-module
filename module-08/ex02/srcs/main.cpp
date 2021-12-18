#include <mutantstack.hpp>
#include <color.hpp>
#include <iostream>
#include <list>

void printTestTitle(std::string title)
{
	std::cout << "\n"
			  << CYAN
			  << title
			  << " TEST"
			  << END << std::endl;
}

int main()
{
	{
		printTestTitle("SUBJECT");
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}

	{
		printTestTitle("Mutant Stack");
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.top() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		std::cout << mstack.size() << '\n' << std::endl;

		std::cout << "print element" << std::endl;
		const MutantStack<int>::iterator it_e = mstack.end();
		for (MutantStack<int>::iterator it = mstack.begin(); it != it_e; ++it)
		{
			std::cout << *it << std::endl;
		}
	}

	{
		printTestTitle("List");
		std::list<int> ls;
		ls.push_back(5);
		ls.push_back(17);
		std::cout << ls.back() << std::endl;
		ls.pop_back();
		std::cout << ls.back() << std::endl;
		ls.push_back(3);
		ls.push_back(5);
		ls.push_back(737);
		std::cout << ls.size() << '\n' << std::endl;

		std::cout << "print element" << std::endl;
		const std::list<int>::iterator it_e = ls.end();
		for (std::list<int>::iterator it = ls.begin(); it != it_e; ++it)
		{
			std::cout << *it << std::endl;
		}
	}
	return 0;
}
