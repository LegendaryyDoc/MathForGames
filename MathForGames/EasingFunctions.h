#pragma once
#include "UTILS.h"
#include <cmath>

const float HALF_PI = PI / 2;

template <typename T>
T linearEase(float t, const T& b, const T& c, float d)
{
	return b + c * (t / d);
}

template <typename T>
T easeInSine(float t, const T& b, const T& c, float d)
{
	return b + c - c * cosf(t / d * HALF_PI);
}