#include <iostream>
using namespace std;

void ReadGrade(float &Grade)
{
	cout << "Please enter your grade: ";
	cin >> Grade;

	cout << endl;
}

void PrintGradeSymbol(float Grade)
{
	if (Grade >= 90)
	{
		cout << 'A' << endl;
	}
	else if (Grade >= 80)
	{
		cout << 'B' << endl;
	}
	else if (Grade >= 70)
	{
		cout << 'C' << endl;
	}
	else if (Grade >= 60)
	{
		cout << 'D' << endl;
	}
	else if (Grade >= 50)
	{
		cout << 'E' << endl;
	}
	else
	{
		cout << 'F' << endl;
	}
}

int main()
{
	float Grade;
	
	ReadGrade(Grade);
	PrintGradeSymbol(Grade);

	return 0;
}