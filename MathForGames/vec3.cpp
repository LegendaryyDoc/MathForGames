#include "vec3.h"
#include <cfloat>
#include <cmath>

vec3::vec3()
{
}

vec3::vec3(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
}

vec3 vec3::operator+(const vec3 & rhs) const
{
	vec3 v3;

	v3.y = y + rhs.y;
	v3.x = x + rhs.x;
	v3.z = z + rhs.z;

	return v3;
}

vec3 vec3::operator-(const vec3 & rhs) const
{
	vec3 v3;

	v3.y = y - rhs.y;
	v3.x = x - rhs.x;
	v3.z = z - rhs.z;

	return v3;
}

vec3 & vec3::operator+=(const vec3 & rhs)
{
	// TODO: insert return statement here
	y += rhs.y;
	x += rhs.x;
	z += rhs.z;

	return *this;
}

vec3 & vec3::operator-=(const vec3 & rhs)
{
	// TODO: insert return statement here
	y -= rhs.y;
	x -= rhs.x;
	z -= rhs.z;

	return *this;
}

vec3 & vec3::operator*=(const float rhs)
{
	// TODO: insert return statement here
	x *= rhs;
	y *= rhs;
	z *= rhs;

	return *this;
}

vec3 & vec3::operator/=(const float rhs)
{
	// TODO: insert return statement here
	x /= rhs;
	y /= rhs;
	z /= rhs;

	return *this;
}

bool vec3::operator==(const vec3 & rhs) const
{
	vec3 v3;
	v3.y = y - rhs.y;
	v3.x = x - rhs.x;
	v3.z = z - rhs.z;

	if (v3.y < FLT_EPSILON && v3.x < FLT_EPSILON && v3.z < FLT_EPSILON)
	{
		return true;
	}
	return false;
}

bool vec3::operator!=(const vec3 & rhs) const
{
	vec3 v3;
	v3.y = y - rhs.y;
	v3.x = x - rhs.x;
	v3.z = z - rhs.z;

	if (v3.y > FLT_EPSILON || v3.x > FLT_EPSILON || v3.z > FLT_EPSILON)
	{
		return true;
	}
	return false;
}

vec3 vec3::operator-() const
{
	vec3 v3;
	v3.x = -x;
	v3.y = -y;

	return v3;
}

vec3 vec3::operator*(const float rhs) const
{
	vec3 v3;

	v3.x = x * rhs;
	v3.y = y * rhs;
	v3.z = z * rhs;

	return v3;
}

vec3 vec3::operator/(const float rhs) const
{
	vec3 v3;
	
	v3.x = x / rhs;
	v3.y = y / rhs;
	v3.z = z / rhs;

	return v3;
}

vec3::operator float*()
{
	return &x;
}

vec3::operator const float*() const
{
	return &x;
}

float vec3::magnitude() const
{
	int mag;

	mag = ((x * x) + (y * y) + (z * z));
	mag = sqrtf(mag);

	return mag;
}

float vec3::dot(const vec3 & rhs) const
{
	float dotp;

	dotp = ((x * rhs.x) + (y * rhs.y) + (z * rhs.z));

	return dotp;
}

vec3 vec3::cross(const vec3 & rhs) const
{
	return {y * rhs.z - z * rhs.y, z * rhs.x - x * rhs.z, x * rhs.y - y * rhs.x,};
}

vec3 & vec3::normalize()
{
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

vec3 vec3::getNormalised() const
{
	vec3 n;
	n.x = x;
	n.y = y;
	n.z = z;

	if (magnitude() == 0)
	{
		return n;
	}
	n.x /= magnitude();
	n.y /= magnitude();
	n.z /= magnitude();
}

vec3 & vec3::scale(const vec3 & rhs)
{
	// TODO: insert return statement here
	x *= rhs.x;
	y *= rhs.y;
	z *= rhs.z;

	return *this;
}

vec3 vec3::getScaled(const vec3 & rhs) const
{
	return rhs;
}

vec3 operator*(const float lhs, const vec3 & rhs)
{
	vec3 v3;

	v3.x = rhs.x * lhs;
	v3.y = rhs.y * lhs;
	v3.z = rhs.z * lhs;

	float scalar = 3.5f;
	vec3 dir = { 0, 1, 1 };

	vec3 newVelocity = scalar * dir;

	return v3;
}
