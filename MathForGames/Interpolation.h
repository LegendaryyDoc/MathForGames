#pragma once
template <typename T>
T lerp(const T& a, const T& b, float t);

/*
template <typename T>
T lerp(const T& a, const T& b, float t);*/

/*--------------------------------------*/
/*--------------------------------------*/

template <typename T>
T lerp(const T& a, const T& b, float t)
{
	return a * (1 - t) + b * t;
}

/*
template <typename T>
T lerp(const T& a, const T& b, float t)
{
	return a + (b - a) * t;
}*/