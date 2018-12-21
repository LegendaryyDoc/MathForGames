#pragma once
#include<iostream>

#include "winterm.h"
#include "Matrices.h"

bool nassert(const char * testName, bool expression);


template<typename T>
inline bool nassert(const char * testName, T expected, T actual)
{
	if (expected == actual)
	{
		SetConsoleColor({ 0x02 });

		std::cout << "[PASS] " << testName << std::endl;

		SetConsoleColor({ 0x07 });

		return true;
	}
	else
	{
		SetConsoleColor({ 0x04 });

		std::cout << "[FAIL] " << testName << std::endl;

		SetConsoleColor({ 0x07 });

		return false;
	}
}

template<typename T>
inline bool nassert(const char * testName, T expected, T actual, T tolerance)
{
	if (expected <= actual + tolerance && expected >= actual - tolerance)
	{
		SetConsoleColor({ 0x02 });

		std::cout << "[PASS] " << testName << std::endl;

		SetConsoleColor({ 0x07 });

		return true;
	}
	else
	{
		SetConsoleColor({ 0x04 });

		std::cout << "[FAIL] " << testName << std::endl;

		SetConsoleColor({ 0x07 });

		return false;
	}
}


bool nassert(const char * testName, mat3 expected, mat3 actual)
{
	if (expected == actual)
	{
		SetConsoleColor({ 0x02 });

		std::cout << "[PASS] " << testName << std::endl;

		SetConsoleColor({ 0x07 });

		return true;
	}
	else
	{
		SetConsoleColor({ 0x04 });

		std::cout << "[FAIL] " << testName << std::endl;

		SetConsoleColor({ 0x07 });

		return false;
	}
}
