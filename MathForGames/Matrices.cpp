#include "Matrices.h"
#include "vec2.h"
#include <cmath>

mat3::mat3()
{
}

mat3::mat3(float * ptr)
{
	for (int i = 0; i < 9; i++) // cords
	{
		m[i] = ptr[i];
	}
}

mat3::mat3(float _m1, float _m2, float _m3, float _m4, float _m5, float _m6, float _m7, float _m8, float _m9)
{
	m1 = _m1;
	m2 = _m2;
	m3 = _m3;
	m4 = _m4;
	m5 = _m5;
	m6 = _m6;
	m7 = _m7;
	m8 = _m8;
	m9 = _m9;
}

void mat3::transpose()
{
	/*for (int i = 0; i < 2; i++)
	{
		float temp;
		temp = m[i + 1];
		m[i + 1] = m[i * 3];
		m[i * 3] = temp;
	}
	float temp;
	temp = m[5];
	m[5] = m[7];
	m[7] = temp;*/

	float temp;

	temp = m[3];
	m[3] = m[1];
	m[1] = temp;

	temp = m[2];
	m[2] = m[6];
	m[6] = temp;

	temp = m[5];
	m[5] = m[7];
	m[7] = temp;
}

mat3 mat3::getTranspose() const
{
	mat3 alpha;

	for (int i = 0; i < 9; i++)
	{
		alpha.m[i] = m[i];
	}

	float temp;

	temp = alpha.m[3];
	alpha.m[3] = alpha.m[1];
	alpha.m[1] = temp;

	temp = alpha.m[2];
	alpha.m[2] = alpha.m[6];
	alpha.m[6] = temp;

	temp = alpha.m[5];
	alpha.m[5] = alpha.m[7];
	alpha.m[7] = temp;

	return alpha;
}

mat3::operator float*()
{
	return m;
}

vec3 & mat3::operator[](const int index)
{
	// TODO: insert return statement here
	return axis[index];
}

mat3 mat3::operator*(const mat3 & rhs) const
{
	mat3 alpha = getTranspose();
	mat3 bravo;

	bravo.m[0] = alpha.xAxis.dot(rhs.xAxis);
	bravo.m[1] = alpha.yAxis.dot(rhs.xAxis);
	bravo.m[2] = alpha.zAxis.dot(rhs.xAxis);
	bravo.m[3] = alpha.xAxis.dot(rhs.yAxis);
	bravo.m[4] = alpha.yAxis.dot(rhs.yAxis);
	bravo.m[5] = alpha.zAxis.dot(rhs.yAxis);
	bravo.m[6] = alpha.xAxis.dot(rhs.zAxis);
	bravo.m[7] = alpha.yAxis.dot(rhs.zAxis);
	bravo.m[8] = alpha.zAxis.dot(rhs.zAxis);

	return bravo;
}

mat3 & mat3::operator*=(const mat3 & rhs)
{
	// TODO: insert return statement here
	(*this) = (*this) * rhs;

	return *this;
}

bool mat3::operator==(const mat3 & rhs) const
{
	for (int i = 0; i < 9; i++)
	{
		m[i] == rhs.m[i];
		if (m[i] != rhs.m[i])
		{
			return false;
		}
	}
	return true;
}

bool mat3::operator!=(const mat3 & rhs) const
{
	for (int i = 0; i < 9; i++)
	{
		m[i] == rhs.m[i];
		if (m[i] == rhs.m[i])
		{
			return false;
		}
	}
	return true;
}

mat3 mat3::identity() // ! need to fix
{
	mat3 alpha;

	for (int i = 0; i < 9; i++)
	{
		if (i == 0 || i == 4 || i == 8)
		{
			alpha.m[i] = 1;
		}
		else
		{
			alpha.m[i] = 0;
		}
	}
	
	return alpha;
}

void mat3::set(float _m1, float _m2, float _m3, float _m4, float _m5, float _m6, float _m7, float _m8, float _m9)
{
	m1 = _m1;
	m2 = _m2;
	m3 = _m3;
	m4 = _m4;
	m5 = _m5;
	m6 = _m6;
	m7 = _m7;
	m8 = _m8;
	m9 = _m9;
}

void mat3::set(float * ptr)
{
	for (int i = 0; i < 9; i++)
	{
		m[i] = ptr[i];
	}
}

mat3 mat3::translation(float x, float y)
{
	mat3 alpha;
	alpha = alpha.identity();
	alpha.zAxis.x = x;
	alpha.zAxis.y = y;
	return alpha;
}

mat3 mat3::translation(const vec2 & vec)
{
	mat3 alpha;
	alpha = alpha.translation(vec.x, vec.y);
	return alpha;
}

mat3 mat3::rotation(float rot)
{
	mat3 alpha;

	for (int i = 0; i < 9; i++)
	{
		alpha.m[i] = 0;
	}

	alpha.m[0] = cos(rot);
	alpha.m[3] = sin(rot);
	alpha.m[1] = -sin(rot);
	alpha.m[4] = cos(rot);
	alpha.m[8] = 1;

	return alpha;
}

mat3 mat3::scale(float xScale, float yScale)
{
	mat3 alpha;
	for (int i = 0; i < 3; i++)
	{
		alpha.axis[i].x = xScale;
		alpha.axis[i].y = yScale;
		alpha.axis[i].z = 0;
	}

	return alpha;
}

vec3 mat3::operator*(const vec3 & rhs) const // 3x3 x 3x1
{
	mat3 alpha;
	vec3 bravo;

	alpha = getTranspose();

	bravo.x = alpha.xAxis.dot(rhs);
	bravo.y = alpha.yAxis.dot(rhs);
	bravo.z = alpha.zAxis.dot(rhs);

	return bravo;
}

vec2 mat3::operator*(const vec2 & rhs) const // 3x3 x 2x1
{
	mat3 alpha;
	vec2 bravo;
	vec3 charlie;

	charlie.x = rhs.x;
	charlie.y = rhs.y;
	charlie.z = 0;

	alpha = getTranspose();

	bravo.x = alpha.xAxis.dot(charlie);
	bravo.y = alpha.yAxis.dot(charlie);

	return bravo;
}
