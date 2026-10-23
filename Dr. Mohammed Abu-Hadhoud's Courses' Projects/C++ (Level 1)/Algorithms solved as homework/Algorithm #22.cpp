#include <iostream>
#include <cmath>
using namespace std;

int GetCircleArea(float CongruentSide, float Base)
{
	const float PI = 3.14;
	const float L = CongruentSide;
	float Area = (PI * pow(L, 2) / 4) * ((2 * Base - L) / (2 * Base + L));
	Area = floor(Area);

	return Area;
}

int main()
{
	float CongruentSide, Base;

	cout << "Please enter the length of any congruent side: ";
	cin >> CongruentSide;

	cout << "Please enter the base: ";
	cin >> Base;

	//const float L = CongruentSide; // Just to make it easier to write.
	//float Area = (PI * L * L / 4) * ((2 * Base - L) / (2 * Base + L)); <- The past way
	//float Area = (PI * pow(L, 2) / 4) * ((2 * Base - L) / (2 * Base + L));
	//Area = floor(Area);

	cout << endl << GetCircleArea(CongruentSide, Base) << endl;

	return 0;
}