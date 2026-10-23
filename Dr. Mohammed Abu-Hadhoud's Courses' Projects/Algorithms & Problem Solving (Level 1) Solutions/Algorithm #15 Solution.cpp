#include <iostream>
using namespace std;

struct stRectangle
{
	float Width;
	float Height;
};

void ReadInfo(stRectangle &Rectangle)
{
	cout << "Please enter the width: ";
	cin >> Rectangle.Width;

	cout << "Please enter the Height: ";
	cin >> Rectangle.Height;
}

//float CalculateArea(stRectangle Rectangle)
float CalculateRectangelArea(stRectangle Rectangle)
{
	return Rectangle.Width * Rectangle.Height;
}

void PrintArea(float Area)
{
	cout << "\nRectangle Area = " << Area << endl;
}

int main()
{
	stRectangle Rectangle;

	ReadInfo(Rectangle);
	PrintArea(CalculateRectangelArea(Rectangle));

	return 0;
}