#include <iostream>
using namespace std;

float ReadRadius()
{
	float Radius;

	cout << "Please enter the radius: ";
	cin >> Radius;

	return Radius;
}

float CircleArea(float Radius)
{
	const float PI = 3.14;
	return PI * pow(Radius, 2);
}

void PrintArea(float Area)
{
	cout << "\nCircle Area = " << Area << endl;
}

int main()
{ 
	PrintArea(CircleArea(ReadRadius()));
	return 0;
}