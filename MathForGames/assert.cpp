#include "assert.h"
#include <Windows.h>

bool nassert(const char * testName, bool expression)
{
	if (expression == true)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), { 0x02 });

		std::cout << "[PASS] " << testName << std::endl;

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), { 0x07 });

		return true;
	}
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), { 0x04 });

		std::cout << "[FAIL] " << testName << std::endl;

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), { 0x07 });

		return false;
	}
}

/*
bool nassert(const char * testName, int expected, int actual)
{
	if (expected == actual)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), { 0x02 });

		std::cout << "[PASS] " << testName << std::endl;

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), { 0x07 });

		return true;
	}
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), { 0x04 });

		std::cout << "[FAIL] " << testName << std::endl;

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), { 0x07 });

		return false;
	}
}

bool nassert(const char * testName, float expected, float actual, float tolerance)
{
	if (expected <= actual + tolerance && expected >= actual - tolerance)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), { 0x02 });

		std::cout << "[PASS] " << testName << std::endl;

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), { 0x07 });

		return true;
	}
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), { 0x04 });

		std::cout << "[FAIL] " << testName << std::endl;

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), { 0x07 });

		return false;
	}
}*/
