#include <iostream>
#include <string>
using namespace std;

enum enPassFail { Pass, Fail };

void Read3Marks(int& Mark1, int& Mark2, int& Mark3)
{
	cout << "Please enter a Mark (1): ";
	cin >> Mark1;

	cout << "Please enter a Mark (2): ";
	cin >> Mark2;

	cout << "Please enter a Mark (3): ";
	cin >> Mark3;
}

int SumOf3Marks(int Mark1, int Mark2, int Mark3)
{
	return Mark1 + Mark2 + Mark3;
}

float CalculateAverage(int Mark1, int Mark2, int Mark3)
{
	return (float)SumOf3Marks(Mark1, Mark2, Mark3) / 3;
}

enPassFail CheckAverageMark(float Average)
{
	if (Average >= 50)
		return enPassFail::Pass;
	else
		return enPassFail::Fail;
}

void PrintResults(float Average)
{
	cout << "\nYour Average: " << Average << endl;

	if (CheckAverageMark(Average) == enPassFail::Pass)
		cout << "You Passed" << endl;
	else
		cout << "You Failed" << endl;
}

int main()
{
	int Mark1, Mark2, Mark3;

	Read3Marks(Mark1, Mark2, Mark3);
	PrintResults(CalculateAverage(Mark1, Mark2, Mark3));

	return 0;
}