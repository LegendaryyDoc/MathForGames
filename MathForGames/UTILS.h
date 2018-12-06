#pragma once

// Returns the smaller of the two values
int min(int a, int b);

// Returns the larger of the two values
int max(int a, int b);

// Returns a value in the scope
int clamp(int value, int min, int max);

const double PI = 3.141592653589793238;

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
