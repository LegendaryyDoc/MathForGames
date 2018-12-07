#include <iostream>
#include "UTILS.h"
#include "PointsVectors.h"
#include "vec3.h"

int main()
{
	int up = min(2, 3);
	int down = max(12, 2);
	int c = clamp(83, 12, 82);
	double rad = DEG_TO_RAD(30.0f);
	double deg = RAD_TO_DEG(0.5235f);
	int absolute = abs(-10);
	int power = pow(2, 4);
	bool sqrt = isPowerOfTwo(4);
	int next = nextPowerOfTwo(64);
	float move = moveTowards(5, 12, 1);

	std::cout << "Min: " << up << std::endl;
	std::cout << "Max: " << down << std::endl;
	std::cout << "Clamp: " << c << std::endl;
	std::cout << "DtoR: " << rad << std::endl;
	std::cout << "RtoD: " << deg << std::endl;
	std::cout << "Abs: " << absolute << std::endl;
	std::cout << "Pow: " << power << std::endl;
	std::cout << "SqrtOf2: " << sqrt << std::endl;
	std::cout << "Next Power of Two: " << next << std::endl;
	std::cout << "Move Towards: " << move << std::endl;

	std::cout << "\n\n";

	// addition
	vec2 v2a(13.5f, -48.23f), v2b(5, 3.99f), v2c;
	v2c = v2a + v2b;
	std::cout << "Vec2 addition: " << v2c.x << "," << v2c.y << std::endl;

	// subtraction
	v2a = vec2(13.5f, -48.23f);
	v2b = vec2(5, 3.99f);
	v2c = v2a - v2b;
	std::cout << "Vec2 subtraction: " << v2c.x << "," << v2c.y << std::endl;

	// +=
	v2a = vec2(13.5f, -48.23f);
	v2b = vec2(5, 3.99f);
	v2c = { 0,0 };
	v2c += {10,10};
	std::cout << "Vec2 +=: " << v2c.x << "," << v2c.y << std::endl;

	// -=
	v2a = vec2(13.5f, -48.23f);
	v2b = vec2(5, 3.99f);
	v2c = { 30,25 };
	v2c -= {10, 10};
	std::cout << "Vec2 -=: " << v2c.x << "," << v2c.y << std::endl;

	// == 
	v2a = { 0, 1 };
	v2b = { 0, 0 };
	if (v2a == v2b)
	{
		std::cout << "Vec2 ==: YEP " << std::endl;
	}

	// !=
	v2a = { 1, 0 };
	v2b = { 0, 0 };
	if (v2a != v2b)
	{
		std::cout << "Vec2 !=: YEP " << std::endl;
	}

	// negative
	v2a.x = 22;
	v2c.x = -v2a.x;
	std::cout << "Vec2 -: " << v2c.x << std::endl;

	// float *
	v2a = { 22, 89 };
	float* val = v2a;
	std::cout << "Vec2 float* 0: " << val[0] << std::endl;
	std::cout << "Vec2 float* 1: " << val[1] << std::endl;

	/*    Vector3    */
	vec3 v3a, v3b, v3c;

	v3a = { 10, 20, 16 };
	v3b = { 30, 15, 12 };
	v3c = v3a + v3b;
	std::cout << "Vec3 addition: " << v3c.x << "," << v3c.y << "," << v3c.z << std::endl;

	return 0;
}