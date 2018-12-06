#include <iostream>
#include "UTILS.h"

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

	std::cout << "Min: " << up << std::endl;
	std::cout << "Max: " << down << std::endl;
	std::cout << "Clamp: " << c << std::endl;
	std::cout << "DtoR: " << rad << std::endl;
	std::cout << "RtoD: " << deg << std::endl;
	std::cout << "Abs: " << absolute << std::endl;
	std::cout << "Pow: " << power << std::endl;
	std::cout << "SqrtOf2: " << sqrt << std::endl;

	return 0;
}