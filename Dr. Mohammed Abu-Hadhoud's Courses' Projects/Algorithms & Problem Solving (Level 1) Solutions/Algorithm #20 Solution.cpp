#include <iostream>
using namespace std;

float ReadSquareSide()
{
	float SquareSide;

	cout << "Please enter the square side: ";
	cin >> SquareSide;

	return SquareSide;
}

float CircleAreaInscribedInSquare(float SquareSide)
{
	const float PI = 3.14;
	float Area = (PI * pow(SquareSide, 2)) / 4;

	return Area;
}

void PrintArea(float Area)
{
	cout << "\nCircle Area = " << Area << endl;
}

int main()
{
	PrintArea(CircleAreaInscribedInSquare(ReadSquareSide()));

	return 0;
}