#include <string>
#include <sstream>
#include "CppUnitTest.h"
#include "../BIgInt/class.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(Test_addition_override)
		{
			std::string firststring = "1253141";
			long long int firstint = -41251;
			Class_BigInt first = Class_BigInt(firststring);
			Class_BigInt second = Class_BigInt(firstint);
			first += second;
			std::string result ="1211890";
			std::string current_result = first.get_string();
			int current_sign = first.get_sign();
			Assert::AreEqual(current_result, result);
			Assert::AreEqual(current_sign, 1);
		}
		TEST_METHOD(Test_addition_override_int) 
		{
			std::string firststring = "1253141";
			int firstint = 121251;
			Class_BigInt first = Class_BigInt(firststring);
			first += firstint;
			std::string result = "1374392";
			std::string current_result = first.get_string();
			int current_sign = first.get_sign();
			Assert::AreEqual(result, current_result);
			Assert::AreEqual(current_sign, 1);
		}
		TEST_METHOD(Test_substraction_override)
		{
			std::string firststring = "1253141";
			long long int firstint = -41251;
			Class_BigInt first = Class_BigInt(firststring);
			Class_BigInt second = Class_BigInt(firstint);
			first -= second;
			std::string result = "1294392";
			std::string current_result = first.get_string();
			int current_sign = first.get_sign();
			Assert::AreEqual(current_result, result);
			Assert::AreEqual(current_sign, 1);
		}
		TEST_METHOD(Test_substraction_override_int)
		{
			std::string firststring = "11253141";
			int firstint = 121251;
			Class_BigInt first = Class_BigInt(firststring);
			first -= firstint;
			std::string result = "11131890";
			std::string current_result = first.get_string();
			int current_sign = first.get_sign();
			Assert::AreEqual(result, current_result);
			Assert::AreEqual(current_sign, 1);
		}
		TEST_METHOD(Test_addition)
		{
			std::string firststring = "1253141";
			long long int firstint = -41251;
			Class_BigInt first = Class_BigInt(firststring);
			Class_BigInt second = Class_BigInt(firstint);
			Class_BigInt third = first + second;
			std::string result = "1211890";
			std::string current_result = third.get_string();
			int current_sign = first.get_sign();
			Assert::AreEqual(current_result, result);
			Assert::AreEqual(current_sign, 1);
		}
		
		TEST_METHOD(Test_addition_int)
		{
			std::string firststring = "1253141";
			int firstint = 121251;
			Class_BigInt first = Class_BigInt(firststring);
			Class_BigInt third = first + firstint;
			std::string result = "1374392";
			std::string current_result = third.get_string();
			int current_sign = third.get_sign();
			Assert::AreEqual(result, current_result);
			Assert::AreEqual(current_sign, 1);
		}
		TEST_METHOD(Test_substraction)
		{
			std::string firststring = "1253141";
			long long int firstint = -41251;
			Class_BigInt first = Class_BigInt(firststring);
			Class_BigInt second = Class_BigInt(firstint);
			Class_BigInt third = first - second;
			std::string result = "1294392";
			std::string current_result = third.get_string();
			int current_sign = third.get_sign();
			Assert::AreEqual(current_result, result);
			Assert::AreEqual(current_sign, 1);
		}
		TEST_METHOD(Test_substraction_int)
		{
			std::string firststring = "11253141";
			int firstint = 121251;
			Class_BigInt first = Class_BigInt(firststring);
			Class_BigInt third = first - firstint;
			std::string result = "11131890";
			std::string current_result = third.get_string();
			int current_sign = first.get_sign();
			Assert::AreEqual(result, current_result);
			Assert::AreEqual(current_sign, 1);
		}
		TEST_METHOD(Test_zero_removal)
		{
			std::string firststring = "912551156124415999";
			std::string secondstring = "912551156124415870";
			Class_BigInt first = Class_BigInt(firststring);
			Class_BigInt second = Class_BigInt(secondstring);
			first -= second;
			std::string result = "129";
			std::string current_result = first.get_string();
			int current_sign = first.get_sign();
			Assert::AreEqual(current_result, result);
			Assert::AreEqual(current_sign, 1);
		}
		TEST_METHOD(Test_are_equal)
		{
			std::string firststring = "912551156124415999";
			std::string secondstring = "912551156124415999";
			Class_BigInt first = Class_BigInt(firststring);
			Class_BigInt second = Class_BigInt(secondstring);
			first -= second;
			std::string result = "0";
			std::string current_result = first.get_string();
			int current_sign = first.get_sign();
			Assert::AreEqual(current_result, result);
			Assert::AreEqual(current_sign, 1);
		}
		TEST_METHOD(Test_sign_change)
		{
			std::string firststring = "912551156124415999";
			std::string secondstring = "1912551156124415999";
			Class_BigInt first = Class_BigInt(firststring);
			Class_BigInt second = Class_BigInt(secondstring);
			first -= second;
			std::string result = "1000000000000000000";
			std::string current_result = first.get_string();
			int current_sign = first.get_sign();
			Assert::AreEqual(current_result, result);
			Assert::AreEqual(current_sign, -1);
		}
	};
	
}
