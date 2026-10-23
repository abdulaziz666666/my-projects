#include <iostream>
using namespace std;

void ReadMarks(float Marks[3])
{
	cout << "Please enter the first mark: ";
	cin >> Marks[0];

	cout << "Please enter the second mark: ";
	cin >> Marks[1];

	cout << "Please enter the third mark: ";
	cin >> Marks[2];

	cout << endl;
}

float GetMarksAverage(float Marks[3])
{
	return (Marks[0] + Marks[1] + Marks[2]) / 3;
}

void PrintPassOrFail(float Marks[3])
{
	float Average = GetMarksAverage(Marks);

	cout << Average << endl;

	if (Average >= 50)
	{
		cout << "Pass" << endl;
	}
	else
	{
		cout << "Fail" << endl;
	}
}

int main()
{
	float Marks[3];

	ReadMarks(Marks);
	PrintPassOrFail(Marks);

	return 0;
}