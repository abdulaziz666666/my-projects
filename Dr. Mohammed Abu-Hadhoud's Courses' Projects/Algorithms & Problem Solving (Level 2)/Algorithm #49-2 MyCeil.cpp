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

float GetFractionPart(float Num)
{
	return Num - int(Num);
}

int MyCeil(float Num)
{	
	int IntPart = int(Num);
	float FractionPart = GetFractionPart(Num);

	if (abs(FractionPart) > 0)
	{
		if (Num > 0)
			return ++IntPart;
		else
			return IntPart;
	}
	else
		return IntPart;
}

// the way dr. mohammed did.
int MyCeil2(float Num)
{
	if (GetFractionPart(Num) > 0)
	{
		if (Num > 0)
			return int(Num) + 1;
		else
			return int(Num);
	}
	else
		return int(Num);
}

int main()
{
	for (int i = 1; i <= 4; i++)
	{
		float Num = ReadNumber("Please enter a number: ");

		cout << "My ceil result:\t\t" << MyCeil(Num) << endl;
		cout << "C++ round result:\t" << ceil(Num) << endl;
		cout << endl;
	}

	return 0;
}