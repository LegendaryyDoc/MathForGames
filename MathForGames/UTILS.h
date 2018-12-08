#pragma once

// Returns the smaller of the two values
int min(int a, int b);

// Returns the larger of the two values
int max(int a, int b);

// Returns a value in the scope
int clamp(int value, int min, int max);

//const double PI = 3.141592653589793238;

#ifndef PI
	#define PI 3.14159265358979323846f
#endif

// Returns a conversion from a degree to a radian
double DEG_TO_RAD(float deg);

// Returns a conversion from a radian to a degree
double RAD_TO_DEG(float rad);

// Returns the absolute value
int abs(int val);

// Returns the base to the power
int pow(int base, int power);

// Returns true if is a power of 2
bool isPowerOfTwo(int val);

// Returns the next power of two after the given value
int nextPowerOfTwo(int val);

// Moves current to target but cannot be greater than max
float moveTowards(float current, float target, float maxDelta);
