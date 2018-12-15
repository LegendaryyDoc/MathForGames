#pragma once
#include<iostream>

#include "winterm.h"

bool nassert(const char * testName, bool expression);

template<typename T>
bool nassert(const char * testName, T expected, T actual);

template<typename T>
bool nassert(const char * testName, T expected, T actual, T tolerance);

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
