#include "class.h"
#include "class.h"
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <limits>
#include <utility>
#include "class.h"

int comparison(std::string natural, std::string negative) //determines the sign during operations if lengths are equal
{
	if (natural.size() < negative.size())
		return -1;
	if (natural.size() > negative.size())
		return 1;
	long int i = natural.size() - 1;
	for (i; i >= 0; i--)
	{
		if (natural[i] > negative[i])
			return 1;
		if (negative[i] < natural[i])
			return -1;
	}
	return 0; // special condition, if true a + b = 0 / a - b = 0, so further calculations are not necessary
}


std::pair<std::string, int> basic_operations(Class_BigInt first_number, Class_BigInt second_number, int sign) //addition and substraction, as in all 8 cases of those operations the process is quite similar.
{
	int new_sign;
	std::string split;
	int sign_first = first_number.get_sign();
	int sign_second = second_number.get_sign();
	std::string first_value = first_number.get_string();
	std::string second_value = second_number.get_string();
	std::string new_value;
	if (sign == -1)
	{
		sign_second = -sign_second;
	}
	if (sign_first == -1 && sign_second == -1)
	{
		new_sign = -1;
		sign_first = 1;
		sign_second = 1;
	}
	else if (sign_first == 1 && sign_second == -1)
	{
		new_sign = comparison(first_value, second_value);
	}
	else if (sign_first == -1 && sign_second == 1)
	{
		new_sign = comparison(second_value, first_value);
	}
	else
	{
		new_sign = 1;
	}
	if (new_sign == 0)
	{
		new_value = "0";
		new_sign = 1;
	}
	else
	{
		while (first_value.size() > second_value.size())
		{
			split.append(first_value, 0, 1);
			first_value.erase(first_value.begin());
		}
		while (second_value.size() > first_value.size())
		{
			split.append(second_value, 0, 1);
			second_value.erase(second_value.begin());
		}
		int carry_over = 0;
		while (!first_value.empty())
		{
			int tempint = (int(first_value.back()) - 48) * sign_first + sign_second * (int(second_value.back()) - 48) + carry_over;
			carry_over = 0;
			if (tempint < 0)
			{
				tempint = 10 + tempint;
				carry_over = -1;
			}
			if (tempint > 10)
			{
				tempint -= 10;
				carry_over = 1;
			}
			
			new_value.insert(0,std::to_string(tempint));
			first_value.pop_back();
			second_value.pop_back();
		}
		while (split.empty() == false)
		{
			int tempint = carry_over + int(split.back()) - 48;
			split.pop_back();
			carry_over = 0;
			if (tempint < 0)
			{
				tempint = 10 + tempint;
				carry_over = -1;
			}
			if (tempint > 10)
			{
				tempint -= 10;
				carry_over = 1;
			}
			new_value.insert(0,std::to_string(tempint));
		}
		if (carry_over != 0)
		{
			new_value.insert(0, 1, '1');
		}
		while (new_value[0] == '0')
		{
			new_value.erase(new_value.begin());
		}
	}
	std::pair <std::string, int> result(new_value, new_sign);
	return result;
}


std::string Class_BigInt::get_string() const
{
	return BigInt;
};
int Class_BigInt::get_sign() const
{
	return sign;
};
Class_BigInt& Class_BigInt::operator+=(Class_BigInt& another_big)
{
	std::pair <std::string, int> values = basic_operations(*this, another_big, 1);
	BigInt = values.first;
	sign = values.second;
	return *this;
}
Class_BigInt& Class_BigInt::operator -= (Class_BigInt& another_big)
{
	std::pair <std::string, int> values = basic_operations(*this, another_big, -1);
	BigInt = values.first;
	sign = values.second;
	return *this;
}
Class_BigInt& Class_BigInt::operator += (int integer)
{
	Class_BigInt second_value = Class_BigInt(signed long long int(integer));
	std::pair <std::string, int> values = basic_operations(*this, second_value, 1);
	BigInt = values.first;
	sign = values.second;
	return *this;
}
Class_BigInt& Class_BigInt::operator -= (int integer)
{
	Class_BigInt second_value = Class_BigInt(signed long long int(integer));
	std::pair <std::string, int> values = basic_operations(*this, second_value, -1);
	BigInt = values.first;
	sign = values.second;
	return *this;
}
Class_BigInt::Class_BigInt(std::string numbers)
{
	if(numbers[0] == '-')
	{
		sign = -1;
		numbers.erase(numbers.begin());
	}
	BigInt = numbers;
}
Class_BigInt::Class_BigInt(signed long long int integer)
{
	if (integer < 0)
	{
		sign = -1;
		integer = abs(integer);
	};
	BigInt = std::to_string(integer);
}
std::ostream& operator << (std::ostream& os, Class_BigInt& BigInt)
{
std::string output = BigInt.get_string();
if (BigInt.get_sign() == -1)
{
	output.insert(0, 1, '-');
}
os << output;
return os;
}
Class_BigInt operator + (Class_BigInt& some_big, Class_BigInt& another_big)
{
	std::pair <std::string, int> values = basic_operations(some_big, another_big, 1);
	Class_BigInt result = Class_BigInt(values.first);
	return result;
}
Class_BigInt operator - (Class_BigInt& some_big, Class_BigInt& another_big)
{
	std::pair <std::string, int> values = basic_operations(some_big, another_big, -1);
	Class_BigInt result = Class_BigInt(values.first);
	return result;
}
Class_BigInt operator + ( Class_BigInt& BigInt, int& integer)
{
	Class_BigInt converted = Class_BigInt(signed long long int(integer));
	std::pair <std::string, int> values = basic_operations(BigInt, converted, 1);
	Class_BigInt result = Class_BigInt(values.first);
	return result;
}
Class_BigInt operator - (Class_BigInt& BigInt, int& integer)
{
	Class_BigInt converted = Class_BigInt(signed long long int(integer));
	std::pair <std::string, int> values = basic_operations(BigInt, converted, -1);
	Class_BigInt result = Class_BigInt(values.first);
	return result;
}
