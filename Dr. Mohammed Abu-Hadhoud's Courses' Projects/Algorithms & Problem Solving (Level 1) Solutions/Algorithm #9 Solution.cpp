#include <iostream>
#include <string>
using namespace std;

// my way
//void Read3Numbers(int Numbers[3])
//{
//	for (int i = 0; i < 3; i++)
//	{
//		cout << "Please enter a number (" << i + 1 << "): ";
//		cin >> Numbers[i];
//	}
//}
//
//int CalculateSum(int Numbers[3])
//{
//	int Sum = 0;
//
//	for (int i = 0; i < 3; i++)
//	{
//		Sum += Numbers[i];
//	}
//
//	return Sum;
//}
//
//string GetConcatinatedNumbers(int Numbers[3])
//{
//	string ConcatinatedNumbers = to_string(Numbers[0]);
//
//	for (int i = 1; i < 3; i++)
//	{
//		ConcatinatedNumbers += ", " + to_string(Numbers[i]);
//	}
//
//	return ConcatinatedNumbers;
//}
//
//void PrintSum(int Numbers[3])
//{
//	string Result = "The Sum of " + GetConcatinatedNumbers(Numbers) + " is " + to_string(CalculateSum(Numbers));
//	cout << endl << Result << endl;
//}

void Read3Numbers(int& Num1, int& Num2, int& Num3)
{
	cout << "Please enter a number (1): ";
	cin >> Num1;

	cout << "Please enter a number (2): ";
	cin >> Num2;

	cout << "Please enter a number (3): ";
	cin >> Num3;
}

int SumOf3Numbers(int Num1, int Num2, int Num3)
{
	return Num1 + Num2 + Num3;
}

void PrintResult(int Total)
{
	cout << "\nThe sum is " << Total << endl;
}

int main()
{
	//int Numbers[3];

	//Read3Numbers(Numbers);
	//PrintSum(Numbers);

	int Num1, Num2, Num3;

	Read3Numbers(Num1, Num2, Num3);
	PrintResult(SumOf3Numbers(Num1, Num2, Num3));

	return 0;
}