#include <iostream>
using namespace std;

float ReadCircumference()
{
	float Circumference;

	cout << "Please enter the circumference: ";
	cin >> Circumference;

	return Circumference;
}

float CircleAreaByCircumference(float Circumference)
{
	const float PI = 3.14;

	float Area = pow(Circumference, 2) / (4 * PI);

	return Area;
}

void PrintArea(float Area)
{
	cout << "\nCircle Area = " << Area << endl;
}

int main()
{
	PrintArea(CircleAreaByCircumference(ReadCircumference()));
	return 0;
}