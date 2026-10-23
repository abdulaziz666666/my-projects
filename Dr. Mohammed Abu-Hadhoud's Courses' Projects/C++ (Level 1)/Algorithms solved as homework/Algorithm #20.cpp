#include <iostream>
#include <cmath>
using namespace std;

int GetCircleAreaBySquareSide(float Side)
{
	const float PI = 3.14;
	float Area = PI * pow(Side, 2) / 4;
	Area = ceil(Area);

	return Area;
}

int main()
{
	float Side;

	cout << "In order to calculate the circle area inside a square, you need\nto enter the length of any side of the square: ";
	cin >> Side;

	//float Area = PI * Side * Side / 4; <- The past way
	//float Area = PI * pow(Side, 2) / 4;
	//Area = ceil(Area);

	cout << endl << GetCircleAreaBySquareSide(Side) << endl;

	return 0;
}