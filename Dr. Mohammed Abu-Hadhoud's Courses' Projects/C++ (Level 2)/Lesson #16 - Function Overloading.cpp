#include <iostream>
using namespace std;

double MySum(double a, double b)
{
	return a + b;
}

int MySum(int a, int b)
{
	return a + b;
}

int MySum(int a, int b, int c)
{
	return a + b + c;
}

int MySum(int a, int b, int c, int d)
{
	return a + b + c + d;
}

int main()
{

	cout << MySum(1, 2) << endl;
	cout << MySum(1, 2, 3) << endl;
	cout << MySum(1, 2, 3, 4) << endl;
	cout << MySum(1.2, 2.6) << endl;

	// 1 in 4

	return 0;
}