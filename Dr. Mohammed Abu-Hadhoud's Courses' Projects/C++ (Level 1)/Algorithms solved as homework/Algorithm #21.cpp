#include <iostream>
#include <cmath>
using namespace std;

int GetCircleAreaByCircumference(float Circumference)
{
	const float PI = 3.14;
	float Area = pow(Circumference, 2) / (4 * PI);
	Area = floor(Area);

	return Area;
}

int main()
{
	float Circumference;

	cout << "Please enter the circumference to calculate the area of the circle: ";
	cin >> Circumference;

	//float Area = Circumference * Circumference / (4 * PI); <- The past way
	//float Area = pow(Circumference, 2) / (4 * PI);
	//Area = floor(Area);

	cout << endl << GetCircleAreaByCircumference(Circumference) << endl;

	return 0;
}