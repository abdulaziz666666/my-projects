#include <iostream>
#include <cmath>
using namespace std;

float ReadNumber(string Message)
{
	float Num;

	cout << Message << endl;
	cin >> Num;

	return Num;
}

int MyFloor(float Num)
{
	if (Num > 0)
		return int(Num);
	else
		return int(Num) - 1;
}

int main()
{

	float Num;

	for (int i = 1; i <= 4; i++) // for all cases: -\+ with >= .5 and < .5
	{
		Num = ReadNumber("Please enter a number: ");

		cout << "My Floor1 result:\t" << MyFloor(Num) << endl;
		cout << "C++ Floor result:\t" << floor(Num) << endl;
	}

	return 0;
}