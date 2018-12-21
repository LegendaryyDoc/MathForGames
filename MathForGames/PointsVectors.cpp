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


vec2 vec2::getPerpCW() const
{
	vec2 n;
	n.x = y;
	n.y = -x;
	return n;

}

vec2 vec2::getPerpCCW() const
{
	vec2 n;
	n.x = -y;
	n.y = x;
	return n;
}

float vec2::angleBetween(const vec2 & rhs) const
{
	return std::acos(dot(rhs) / magnitude() * rhs.magnitude());
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
		*this *= magnitude();
		return *this;
	}
}

vec2 vec2::getNormalized() const
{
	vec2 n;
	n.x = x;
	n.y = y;

	if (magnitude() == 0)
	{
		return n;
	}
	n.x /= magnitude();
	n.y /= magnitude();

	return n;
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

float vec2::dot(const vec2 & rhs) const
{
	float dotp;

	dotp = ((x * rhs.x) + (y + rhs.y));

	return dotp;
}

vec2 operator*(const float lhs, const vec2 & rhs)
{
	vec2 v3;

	v3.x = rhs.x * lhs;
	v3.y = rhs.y * lhs;

	float scalar = 3.5f;
	vec2 dir = { 0, 1 };

	vec2 newVelocity = scalar * dir;

	return v3;
}


