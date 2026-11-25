#include <iostream>
using namespace std;

void PrintNumbersReversly(int From, int To)
{
	if (To >= From)
	{
		cout << To << endl;
		PrintNumbersReversly(From, To - 1);
	}
}

int main()
{
	
	PrintNumbersReversly(1, 10);

	return 0;
}