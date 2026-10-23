#include <iostream>
using namespace std;

enum enPassFail {Pass, Fail};

float ReadMark()
{
	float Mark;

	cout << "Please enter the mark: ";
	cin >> Mark;

	return Mark;
}

enPassFail CheckMark(float Mark)
{
	if (Mark >= 50)
		return enPassFail::Pass;
	else
		return enPassFail::Fail;
}

//bool HasPassed(float Mark)
//{
//	return (Mark >= 50);
//}

void PrintResult(float Mark)
{
	//if (HasPassed(Mark))
	if (CheckMark(Mark) == enPassFail::Pass)
		cout << "\nPass\n";
	else
		cout << "\nFail\n";
}

int main()
{
	PrintResult(ReadMark());
	return 0;
}