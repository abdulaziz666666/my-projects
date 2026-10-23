#include <iostream>
using namespace std;

float ReadDiameter()
{
	float Diameter;

	cout << "Please enter the diameter: ";
	cin >> Diameter;

	return Diameter;
}

float CircleAreaByDiameter(float Diameter)
{
	const float PI = 3.14;
	float Area = (PI * pow(Diameter, 2)) / 4;

	return Area;
}

void PrintArea(float Area)
{
	cout << "\nCircle Area = " << Area << endl;
}

int main()
{
	PrintArea(CircleAreaByDiameter(ReadDiameter()));

	return 0;
}