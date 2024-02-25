#pragma once
#include <iostream>
#include <vector>
#include <string>

class Class_BigInt
{
	std::string BigInt;
	int sign = 1;
public:
	std::string get_string() const;
	int get_sign() const;
	Class_BigInt& operator += (Class_BigInt& another_big);
	Class_BigInt& operator -= (Class_BigInt& another_big);
	Class_BigInt& operator += (int integer);
	Class_BigInt& operator -= (int integer);
	Class_BigInt(std::string numbers);
	Class_BigInt(signed long long int integer);
};
std::ostream& operator << (std::ostream& os, Class_BigInt& BigInt);
Class_BigInt operator + (Class_BigInt& some_big, Class_BigInt& another_big);
Class_BigInt operator - (Class_BigInt& some_big, Class_BigInt& another_big);
Class_BigInt operator + (Class_BigInt& BigInt, int& integer);
Class_BigInt operator - (Class_BigInt& BigInt, int& integer);