#pragma once
#include <cfloat>

struct vec2
{
	float x, y;

	vec2();
	vec2(float x, float y);



	/*--- Operators ---*/
	vec2 operator+(const vec2 &rhs) const;
	vec2 operator-(const vec2 &rhs) const;

	vec2 &operator+=(const vec2 &rhs);
	vec2 &operator-=(const vec2 &rhs);

	bool operator==(const vec2 &rhs) const;
	bool operator!=(const vec2 &rhs) const;

	vec2 operator-() const;

	/*--- Type Conversions ---*/
	operator float *();
	operator const float *() const;

	/*------------------------*/
	float magnitude() const;

	vec2 &normalize();
	vec2 getNormalized() const;

	vec2 &scale(const vec2 &rhs);
	vec2 getScaled(const vec2 &rhs) const;

	vec2 operator*(const float rhs) const;
	friend vec2 operator*(const float lhs, const vec2 &rhs);

	vec2 &operator*=(const float rhs);
	vec2 &operator/=(const float rhs);

#ifdef RAYLIB_H
	vec2(Vector2 vec)
	{
		x = vec.x;
		y = vec.y;
	}

	vec2& operator=(const Vector2& a)
	{
		x = a.x;
		y = a.y;

		return *this;
	}

	operator Vector2()
	{
		return { x, y };
	}
#endif

	/*------------------------*/
	float dot(const vec2 &rhs) const;
};

/*******************************************/
/*******************************************/

/*template<unsigned D>
struct vec
{
	float data[D];
	vec();
	//vec(float x, float y);

	vec operator+(const vec &rhs) const;
	vec operator-(const vec &rhs) const;

	vec &operator+=(const vec &rhs);
	vec &operator-=(const vec &rhs);

	bool operator==(const vec &rhs) const;
	bool operator!=(const vec &rhs) const;

	vec operator-() const;

	operator float *();
	operator const float *() const;
};*/

/*******************************************/
/*******************************************/

/*template<unsigned D>
inline vec<D>::vec()
{
}

template<unsigned D>
inline vec<D>::vec(float x, float y)
{
	
}

template<unsigned D>
inline vec vec<D>::operator+(const vec & rhs) const
{
	vec<D> temp;

	for (size_t i = 0; i < D; ++i)
	{
		temp.data[i] = data[i] + rhs.data[i];
	}

	return temp;
}

template<unsigned D>
inline vec vec<D>::operator-(const vec & rhs) const
{
	vec<D> temp;

	for (size_t i = 0; i < D; ++i)
	{
		temp.data[i] = data[i] - rhs.data[i];
	}

	return temp;
}

template<unsigned D>
inline vec & vec<D>::operator+=(const vec & rhs)
{
	// TODO: insert return statement here
	for (size_t i = 0; i < D; ++i)
	{
		 data[i] += rhs.data[i];
	}
	return *this;
}

template<unsigned D>
inline vec & vec<D>::operator-=(const vec & rhs)
{
	// TODO: insert return statement here
	for (size_t i = 0; i < D; ++i)
	{
		data[i] -= rhs.data[i];
	}
	return *this;
}

template<unsigned D>
inline bool vec<D>::operator==(const vec & rhs) const
{
	vec<D> temp;
	bool eq[D];

	for (size_t i = 0; i < D; ++i)
	{
		temp.data[i] = data[i] - rhs.data[i];
		if(temp.data[i] < FLT_EPSILON)
		{
			eq[i] = true;
		}
		else
		{
			eq[i] = false;
		}
	}
	return;
}

template<unsigned D>
inline bool vec<D>::operator!=(const vec & rhs) const
{
	return false;
}

template<unsigned D>
inline vec vec<D>::operator-() const
{
	return vec();
}

template<unsigned D>
inline vec<D>::operator float*()
{
}

template<unsigned D>
inline vec<D>::operator const float*() const
{
}*/