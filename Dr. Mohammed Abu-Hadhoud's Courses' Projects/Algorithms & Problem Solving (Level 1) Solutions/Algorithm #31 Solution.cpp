#include <iostream>
#include <cmath>
using namespace std;

int ReadNumber(string Message)
{ 
	int Num;

	cout << Message << endl;
	cin >> Num;

	return Num;
}

// a good way to represent them.
void PrintNumPowerFromNtoN(int Num, int FromPower, int ToPower)
{
	int PoweredResult;

	// iterating through different powers.
	for (int Power = FromPower; Power <= ToPower; Power++)
	{
		PoweredResult = 1;

		// this loop multiply POWER times (power of 2: two times, etc)
		for (int Counter = 1; Counter <= Power; Counter++)
			PoweredResult *= Num;

		cout << Num << " ^ " << Power << " = " << PoweredResult << endl;
	}
}

/*
For some reason, Dr. Mohammed solves that algorithm manually:

void PrintPowerOf2_3_4(int Num)
{
	int a, b, c;

	a = Num * Num;
	b = Num * Num * Num;
	c = Num * Num * Num * Num;

	cout << a < " " << b << " " << c << endl;
}
*/

int main()
{
	int Num = ReadNumber("Please enter a number: ");
	PrintNumPowerFromNtoN(Num, 2, 4);
	
	return 0;
}