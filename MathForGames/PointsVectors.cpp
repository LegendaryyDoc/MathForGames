#include "PointsVectors.h"
#include <cfloat>
#include <cmath>

vec2::vec2()
{
}

vec2::vec2(float _x, float _y)
{
	x = _x;
	y = _y;
}


/*--------- Operators ---------*/
vec2 vec2::operator+(const vec2 & rhs) const
{
	vec2 v3;

	v3.y = y + rhs.y;
	v3.x = x + rhs.x;

	return v3;
}

vec2 vec2::operator-(const vec2 & rhs) const
{
	vec2 v3;

	v3.y = y - rhs.y;
	v3.x = x - rhs.x;

	return v3;
}

vec2 & vec2::operator+=(const vec2 & rhs)
{
	// TODO: insert return statement here
	y += rhs.y;
	x += rhs.x;

	return *this;
}

vec2 & vec2::operator-=(const vec2 & rhs)
{
	// TODO: insert return statement here
	y -= rhs.y;
	x -= rhs.x;

	return *this;
}

bool vec2::operator==(const vec2 &rhs) const
{
	vec2 v3;
	v3.y = y - rhs.y;
	v3.x = x - rhs.x;

	if (v3.y < FLT_EPSILON && v3.x < FLT_EPSILON)
	{
		return true;
	}
	return false;
}

bool vec2::operator!=(const vec2 &rhs) const
{
	vec2 v3;
	v3.y = y - rhs.y;
	v3.x = x - rhs.x;

	if (v3.y > FLT_EPSILON || v3.x > FLT_EPSILON)
	{
		return true;
	}
	return false;
}

vec2 vec2::operator-() const
{
	vec2 v3;
	v3.x = -x;
	v3.y = -y;

	return v3;
}

/*--------- Type Conversions ---------*/
vec2::operator float*()
{
	return &x;
}

vec2::operator const float*() const
{
	return &x;
}

/*------------------------------------*/
/*------------------------------------*/

float vec2::magnitude() const
{
	int mag;

	mag = ((x * x) + (y * y));
	mag = sqrtf(mag);

	return mag;
}

vec2 & vec2::normalize()
{
	// TODO: insert return statement here
	
	if (magnitude() == 0)
	{
		return *this;
	}
	else
	{
		*this *= (1.0f / magnitude());
		return *this;
	}
}

vec2 vec2::getNormalized() const
{
	return *this;
}

vec2 & vec2::scale(const vec2 & rhs)
{
	// TODO: insert return statement here
	x *= rhs.x;
	y *= rhs.y;

	return *this;
}

vec2 vec2::getScaled(const vec2 & rhs) const
{
	return rhs;
}

vec2 vec2::operator*(const float rhs) const
{
	vec2 v3;

	v3.x = x * rhs;
	v3.y = y * rhs;

	return v3;
}

vec2 & vec2::operator*=(const float rhs)
{
	// TODO: insert return statement here
	x *= rhs;
	y *= rhs;
	return *this;
}

vec2 & vec2::operator/=(const float rhs)
{
	// TODO: insert return statement here
	x /= rhs;
	y /= rhs;
	return *this;
}

vec2 operator*(const float lhs, const vec2 & rhs)
{
	vec2 v3;

	v3.x = rhs.x * lhs;
	v3.y = rhs.y * lhs;

	return v3;
}


