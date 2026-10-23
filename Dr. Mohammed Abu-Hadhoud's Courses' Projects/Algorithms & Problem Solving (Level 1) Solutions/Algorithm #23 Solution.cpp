#include <iostream>
using namespace std;

struct stArbitraryTriangle
{
	float A, B, C;
};

//stIsoscelesTriangle ReadInfo()
void ReadTriangleData(stArbitraryTriangle& Triangle)
{
	cout << "Please enter A: ";
	cin >> Triangle.A;

	cout << "Please enter B: ";
	cin >> Triangle.B;

	cout << "Please enter C: ";
	cin >> Triangle.C;
}

float CircleAreaByArbTriangle(stArbitraryTriangle T)
{
	const float PI = 3.14;

	float P = (T.A + T.B + T.C) / 2;
	float X = (T.A * T.B * T.C) / (4 * sqrt(P * (P - T.A) * (P - T.B) * (P - T.C)));
	float Area = PI * pow(X, 2);
	//float Area = PI * pow((T.A * T.B * T.C) / (4 * sqrt(P * (P - T.A) * (P - T.B) * (P - T.C))), 2);

	return Area;
}

void PrintArea(float Area)
{
	cout << "\nCircle Area = " << Area << endl;
}

int main()
{
	stArbitraryTriangle Triangle;

	ReadTriangleData(Triangle);
	PrintArea(CircleAreaByArbTriangle(Triangle));

	return 0;
}