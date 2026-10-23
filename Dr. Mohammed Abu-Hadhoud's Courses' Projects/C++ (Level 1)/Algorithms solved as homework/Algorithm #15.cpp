#include <iostream>
using namespace std;

float GetRectangleArea(float Width, float Height)
{
	return Width * Height;
}

int main()
{
	float Width, Height;

	cout << "Please enter the width: ";
	cin >> Width;

	cout << "Please enter the height: ";
	cin >> Height;

	cout << endl;

	//float Area = Width * Height; // The Old Way.
	cout << GetRectangleArea(Width, Height) << endl;

	return 0;
}