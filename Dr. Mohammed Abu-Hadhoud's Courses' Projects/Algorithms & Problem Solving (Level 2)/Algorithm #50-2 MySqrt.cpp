#include <iostream>
#include <cmath>
using namespace std;

float ReadNumber()
{
	float Num;

	cout << "Please enter a number: ";
	cin >> Num;

	return Num;
}

int MySqrt(int Num)
{
	// Negative numbers don't have square roots.
	if (Num < 0)
		return -1;

	for (int i = 0; i <= Num; i++) // Indeed, it will find it before reaching to Num;
	{
		if (i * i == Num)
			return i;
	}
}
// It was unexpected that Dr. Mohammed wrote it:
float MySqrt2(float Num)
{
	return pow(Num, 0.5); // Although it is a well-known fact, it wasn't expected.
}

int main()
{
	float Num = ReadNumber();

	cout << "My Sqrt result: " << MySqrt(Num) << endl;
	cout << "My Sqrt2 result: " << MySqrt2(Num) << endl;
	cout << "C++ Sqrt result: " << sqrt(Num) << endl;

	return 0;
}