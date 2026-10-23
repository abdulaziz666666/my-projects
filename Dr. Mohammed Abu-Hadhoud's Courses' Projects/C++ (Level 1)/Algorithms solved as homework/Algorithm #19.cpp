#include <iostream>
#include <cmath>
using namespace std;

int GetCircleAreaByDiameter(float Diameter)
{
	const float PI = 3.14;
	float Area = PI * pow(Diameter, 2) / 4;
	Area = ceil(Area);

	return Area;
}

int main()
{
	float Diameter;

	cout << "Please enter the diameter: ";
	cin >> Diameter;

	cout << endl;

	// The priority here is equal; no needed for brackets
	//float Area = PI * Diameter * Diameter / 4; <- The past way
	//float Area = PI * pow(Diameter, 2) / 4; // This Also Becomes An Old Way.
	//Area = ceil(Area);

	cout << GetCircleAreaByDiameter(Diameter) << endl;

	return 0;
}