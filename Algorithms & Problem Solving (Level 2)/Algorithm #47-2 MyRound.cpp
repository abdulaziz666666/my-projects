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

// Actually, i am using it as it gives me the fraction
// as it WILL be the last digit after multiplication.
int GetLastDigit(float Num)
{
	int LastDigit = int(Num * 10) % 10;
	return LastDigit;
}

float GetFractionPart(float Num)
{
	return Num - int(Num);
}

// it doesn't function properly
float MyRound1(float Num)
{
	if (Num > 0)
	{
		if (GetLastDigit(Num) >= 5)
			Num = int(Num) + 1;
		else
			Num = int(Num);
	}
	else
	{
		if (GetLastDigit(Num) >= 5)
			Num = int(Num);
		else
			Num = int(Num) - 1;
	}

	return Num;
}

int MyRound2(float Num)
{
	int IntPart = int(Num);
	float FractionPart = GetFractionPart(Num);

	if (abs(FractionPart) >= .5)
	{
		if (Num > 0)
			return ++IntPart;
		else
			return --IntPart;
	}
	else
		return IntPart;
}

int main()
{
	float Num = ReadNumber("Please enter a number: ");

	cout << "My round1 result:\t" << MyRound1(Num) << endl;
	cout << "My round2 result:\t" << MyRound2(Num) << endl;
	cout << "C++ round result:\t" << round(Num) << endl;

	return 0;
}