#include <iostream>
using namespace std;

void ReadGrade(float& Grade)
{
	cout << "Please enter your grade: ";
	cin >> Grade;

	cout << endl;
}

void PrintPassOrFail(float Grade)
{
	if (Grade >= 50)
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
	float Grade;

	ReadGrade(Grade);
	PrintPassOrFail(Grade);

	return 0;
}