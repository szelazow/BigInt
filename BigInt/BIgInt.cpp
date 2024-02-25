#include <iostream>
#include "class.h"

int main()
{
	std::string firststring = "912551156124415999";
	std::string secondstring = "912551156124415999";
	Class_BigInt first = Class_BigInt(firststring);
	Class_BigInt second = Class_BigInt(secondstring);
	Class_BigInt third("0");
	third = first - second;
	std::cout << third;
	return 0;
}