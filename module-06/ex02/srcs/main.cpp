#include <Base.hpp>
#include <A.hpp>
#include <B.hpp>
#include <C.hpp>
#include <iostream>
#include <ctime>
#include <cstdlib>

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

Base *generate(void)
{
	std::srand(std::time(NULL));
	int i = std::rand() % 3;

	if (i == 0)
	{
		std::cout << "generate A" << std::endl;
		return (new A);
	}
	else if (i == 1)
	{
		std::cout << "generate B" << std::endl;
		return (new B);
	}
	else if (i == 2)
	{
		std::cout << "generate C" << std::endl;
		return (new C);
	}
	return (NULL);
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
	{
		std::cout << "A" << std::endl;
	}
	else if (dynamic_cast<B*>(p))
	{
		std::cout << "B" << std::endl;
	}
	else if (dynamic_cast<C*>(p))
	{
		std::cout << "C" << std::endl;
	}
	else
	{
		std::cout << "Wrong class" << std::endl;
	}
}

void identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch(const std::exception&)
	{
	}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch(const std::exception&)
	{
	}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch(const std::exception&)
	{
	}
	std::cout << "Wrong class" << std::endl;
}

int main(void)
{
	Base *pb;

	pb = generate();
	identify(pb);
	identify(*pb);
	delete pb;

	return (0);
}
