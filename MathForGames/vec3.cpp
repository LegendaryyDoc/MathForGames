#include "vec3.h"
#include <cfloat>

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

vec3::operator float*()
{
	return &x;
}

vec3::operator const float*() const
{
	return &x;
}


