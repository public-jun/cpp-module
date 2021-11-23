#include <Array.hpp>
#include <string>
#include <iostream>

int main(void)
{
	Array<int> array(10);
	Array<int> array2 = Array<int>();
	Array<int> array3 = array;

	array2 = array;
	// array = array;
}
