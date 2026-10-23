#include <iostream>
using namespace std;

struct stTriangle
{
	float Base;
	float Height;
};

void ReadInfo(stTriangle& Triangle)
{
	cout << "Please enter the base: ";
	cin >> Triangle.Base;
	
	cout << "Please enter the height: ";
	cin >> Triangle.Height;
}

float TriangleArea(stTriangle Triangle)
{
	return (Triangle.Base / 2) * Triangle.Height;
}

// I really prefer to only take the triangle as a parameter
// and calculating the area inside the procedure; which i think
// is much cleaner.
//void PrintArea(stTriangle Triangle) 
//{
//	 cout << "\nTriangle Area = " << TriangleArea(Triangle) << endl;=;
//}
void PrintArea(float Area)
{
	cout << "\nTriangle Area = " << Area << endl;
}

int main()
{
	stTriangle Triangle;

	ReadInfo(Triangle);
	PrintArea(TriangleArea(Triangle));

	return 0;
}