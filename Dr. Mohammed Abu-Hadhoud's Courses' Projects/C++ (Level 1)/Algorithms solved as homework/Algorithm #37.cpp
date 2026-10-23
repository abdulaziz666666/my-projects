#include <iostream>
using namespace std;

int ReadAndSumUntilMinus99()
{
	cout << "Enter numbers to sum them, enter -99 to stop.\n\n";

	unsigned i = 0;
	int Sum = 0;
	int Num = 0;

	while (Num != -99)
	{
		cout << "Enter a number (" << i + 1 << "): " << endl;
		cin >> Num;

		i++;

		if (Num != -99)
		{
			Sum += Num;
		}
	}

	return Sum;
}

int main()
{
	int Sum = ReadAndSumUntilMinus99();
	cout << "\nSum = " << Sum << endl;

	return 0;
}