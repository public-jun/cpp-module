#include <Animal.hpp>
#include <Dog.hpp>
#include <Cat.hpp>
#include <Brain.hpp>
#include <color.hpp>
#include <string>
#include <iostream>

void test_deep_copy(const std::string *lsh, const std::string *rsh)
{
	if (lsh != rsh)
	{
		std::cout << BOLD << "\nSUCCESS DEEP COPY\n" << END << std::endl;
	}
	else
	{
		std::cout << BOLD << "\nFAILUER DEEP COPY\n" << END << std::endl;
	}
}

int main(void)
{
	{
		const Animal *sample[4];

		std::cout << BOLD << "\nCREATE ARRAY PART\n" << END << std::endl;

		for (int i = 0; i < 2; ++i)
		{
			sample[i] = new Dog();
		}
		for (int i = 2; i < 4; ++i)
		{
			sample[i] = new Cat();
		}

		std::cout << BOLD << "\nDELETE ARRAY PART\n" << END << std::endl;
		for (int i = 0; i < 4; ++i)
		{
			delete sample[i];
		}

		std::cout << BOLD << "\nDEEP COPY TEST DOG PART\n" << END << std::endl;

		Dog dog;
		Dog dog2;

		dog.set_brain_idea(0, "pochi");
		dog2 = dog;

		std::cout << "dog brain ideas [0]: " << dog.get_brain_idea(0) << std::endl;
		std::cout << "dog2 brain ideas [0]: " << dog2.get_brain_idea(0) << std::endl;
		test_deep_copy(&(dog.get_brain_idea(0)), &(dog2.get_brain_idea(0)));
		std::cout << "dog brain ideas 0 addres: " << &(dog.get_brain_idea(0)) << std::endl;
		std::cout << "dog2 brain ideas 0 addres: " << &(dog2.get_brain_idea(0)) << std::endl;

		std::cout << BOLD << "\nDEEP COPY TEST CAT PART\n" << END << std::endl;
		Cat cat;
		cat.set_brain_idea(0, "kuro");
		Cat cat2(cat);
		std::cout << "cat brain ideas 0: " << cat.get_brain_idea(0) << std::endl;
		std::cout << "cat2 brain ideas 0: " << cat2.get_brain_idea(0) << std::endl;
		test_deep_copy(&(cat.get_brain_idea(0)), &(cat2.get_brain_idea(0)));
		std::cout << "cat brain ideas 0 addres: " << &(cat.get_brain_idea(0)) << std::endl;
		std::cout << "cat2 brain ideas 0 addres: " << &(cat2.get_brain_idea(0)) << std::endl;

		std::cout << BOLD << "\nDESTRUCTOR PART\n" << END << std::endl;
	}
}
