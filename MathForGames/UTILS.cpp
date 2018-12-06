#include "UTILS.h"

int min(int a, int b)
{
	return a < b ? a : b;
}

int max(int a, int b)
{
	return a > b ? a : b;
}

int clamp(int value, int min, int max)
{
	if (value > min && value < max)
	{
		return value;
	}
	else
	{
		return 0;
	}
}

double DEG_TO_RAD(float deg)
{
	double rad = (deg *(PI / 180));

	return rad;
}

double RAD_TO_DEG(float rad)
{
	double deg = (rad /(PI / 180));

	return deg;
}

int abs(int val)
{
	return ((val) < 0 ? 0 - (val) : (val));
}

int pow(int base, int power)
{
	int number = base;

	for (int i = 0; i < power - 1; i++)
	{
		number = number * base;
	}

	return number;
}

bool isPowerOfTwo(int val)
{
	int lower_bound = 0;
	int upper_bound = val;
	int temp = 0;

	if (val <= 0)
	{
		return 0;       // if negative number throw an exception
	}
	
	while (temp != val)
	{
		temp = ((lower_bound + upper_bound) / 2);

			if (temp * temp == val)
			{
				return true;
			}
			else if (temp * temp > val)
			{
				upper_bound = temp;
			}
			else if (temp * temp < val)
			{
				lower_bound = temp;
			}
			else
			{
				return false;
			}
	}
}
