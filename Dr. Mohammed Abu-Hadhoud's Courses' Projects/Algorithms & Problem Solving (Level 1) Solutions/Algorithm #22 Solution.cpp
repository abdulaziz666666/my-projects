#include <iostream>
using namespace std;

struct stIsoscelesTriangle
{
	float EquivalentSide;
	float Base;
};

//stIsoscelesTriangle ReadInfo()
void ReadTriangleData(stIsoscelesTriangle& Triangle)
{

	cout << "Please enter one of the equivalent sides: ";
	cin >> Triangle.EquivalentSide;

	cout << "Please enter the base: ";
	cin >> Triangle.Base;
}

float CircleAreaByITriangle(stIsoscelesTriangle Triangle)
{
	const float PI = 3.14;
	float A = Triangle.EquivalentSide;
	float B = Triangle.Base;

	float Area = PI * (pow(B, 2) / 4) * ((2 * A - B) / (2 * A + B));

	return Area;
}

void PrintArea(float Area)
{
	cout << "\nCircle Area = " << Area << endl;
}

int main()
{
	stIsoscelesTriangle Triangle;

	ReadTriangleData(Triangle);
	PrintArea(CircleAreaByITriangle(Triangle));

	return 0;
}