#include <iostream>
using namespace std;

struct stRectangle
{
	float Side;
	float Diagonal;
};

void ReadInfo(stRectangle& Rectangle)
{
	cout << "Please enter the Side: ";
	cin >> Rectangle.Side;

	cout << "Please enter the Diagonal: ";
	cin >> Rectangle.Diagonal;
}

//float CalculateArea(stRectangle Rectangle)
float RectangleAreaBySideAndDiagonal(stRectangle Rectangle)
{
	return Rectangle.Side * sqrt(pow(Rectangle.Diagonal, 2) - pow(Rectangle.Side, 2));
}

void PrintArea(float Area)
{
	cout << "\nRectangle Area = " << Area << endl;
}

int main()
{
	stRectangle Rectangle;

	ReadInfo(Rectangle);
	PrintArea(RectangleAreaBySideAndDiagonal(Rectangle));

	return 0;
}