#include "UTILS.h"

int seed = 782469;
namespace nmath
{
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
		else if (value < min)
		{
			return min;
		}
		else if (value > max)
		{
			return max;
		}
		return value;
	}

	float DEG_TO_RAD(float deg)
	{
		float rad = (deg *(PI / 180));

		return rad;
	}

	float RAD_TO_DEG(float rad)
	{
		float deg = (rad / (PI / 180));

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
		if (val <= 0)
		{
			return 0;       // if negative number throw an exception
		}

		for (int i = 2; i < val; i++)
		{
			if (i * i == val)
			{
				return true;
			}
			else if (i * i > val)
			{
				return false;
			}
		}
		return false;
	}

	int nextPowerOfTwo(int val)
	{
		if (val <= 0)
		{
			return 0;       // if negative number throw an exception
		}

		for (int i = 2; i < val; i++)
		{
			if (i * i == val)
			{
				return val;
			}
			else if (i * i > val)
			{
				return i * i;
			}
		}
		return val;
	}

	float moveTowards(float current, float target, float maxDelta)
	{
		if (current < target && target > maxDelta)
		{
			current += maxDelta;
			return current;
		}
		else if (current < target && target < maxDelta)
		{
			current += target - current;
			return current;
		}
		else if (current == target)
		{
			return current;
		}
		return current;
	}
	int rand(int min, int max)
	{
		int rSeed = seed * seed;
		std::string sSeed = std::to_string(rSeed);
		std::string nrSeed = "111111";

		for (int i = 1; i < 7; ++i)
		{
			nrSeed[i] = sSeed[i];
		}
		seed = std::stoi(nrSeed);
		int n = max - min + 1;
		return seed % n;
	}

	float randDecimal(float min, float max)
	{
		int rSeed = seed * seed;
		std::string sSeed = std::to_string(rSeed);
		std::string nrSeed = "000000";

		for (int i = 1; i < 7; i++) {
			nrSeed[i] = sSeed[i];
		}
		float r = max - min + 1;
		float m = fmod(seed, r);
		if (m > max) {
			return max;
		}
		if (m < min) {
			return min;
		}
		return m;
	}

	void seedRand(int seedValue)
	{
		seed = seedValue;
	}
	int getRandSeed()
	{
		return seed;
	}
}