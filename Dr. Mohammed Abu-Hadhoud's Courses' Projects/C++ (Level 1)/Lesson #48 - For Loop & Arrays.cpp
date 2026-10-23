#include <iostream>
using namespace std;

struct stArray
{
	int Values[100];
	int RealLength;
};

void ReadArrayData(stArray &Arr)
{
	cout << "How many numbers you want to enter (Max: 100): ";
	cin >> Arr.RealLength;

	for (int i = 0; i < Arr.RealLength; i++)
	{
		cout << "Please enter a number [" << i + 1 << "]: ";
		cin >> Arr.Values[i];
	}
}

int CalculateArraySum(stArray Arr)
{
	int Sum = 0;

	for (int i = 0; i < Arr.RealLength; i++)
	{
		Sum += Arr.Values[i];
	}

	return Sum;
}

float CalculateArrayAverage(stArray Arr)
{
	return (float)CalculateArraySum(Arr) / Arr.RealLength;
}

void PrintArrayData(stArray Arr)
{
	cout << endl; // To make some space between ReadArrayData() and the next output message.
	cout << "You entered these values:" << endl;

	for (int i = 0; i < Arr.RealLength; i++)
	{
		cout << "Number [" << i + 1 << "]: " << Arr.Values[i] << endl;
	}

	cout << endl;

	float Sum = (float)CalculateArraySum(Arr);

	cout << "Sum = " << Sum << endl;
	cout << "Average = " << Sum / Arr.RealLength << endl;
	//cout << "The Average of that array is " << CalculateArrayAverage(Arr) << endl;
}

int main()
{
	stArray Arr;
	
	ReadArrayData(Arr);
	PrintArrayData(Arr);

	return 0;
}