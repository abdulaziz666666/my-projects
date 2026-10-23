#include <iostream>
using namespace std;

//enum enGrade {A, B, C, D, E, F};
//
//int ReadGrade()
//{
//	int Grade;
//
//	cout << "Please enter the grade: ";
//	cin >> Grade;
//
//	return Grade;
//}
//
//enGrade CheckGradeDegree(int Grade)
//{
//	if (Grade >= 90)
//		return enGrade::A;
//
//	else if (Grade >= 80)
//		return enGrade::B;
//
//	else if (Grade >= 70)
//		return enGrade::C;
//
//	else if (Grade >= 60)
//		return enGrade::D;
//
//	else if (Grade >= 50)
//		return enGrade::E;
//
//	else
//		return enGrade::F;
//}
//
//void PrintResult(int Grade)
//{
//	switch (CheckGradeDegree(Grade))
//	{
//	case enGrade::A:
//		cout << "\nExcellent (A)\n";
//		break;
//	case enGrade::B:
//		cout << "\nVery Good (B)\n";
//		break;
//	case enGrade::C:
//		cout << "\nGood (C)\n";
//		break;
//	case enGrade::D:
//		cout << "\nVery Decent (D)\n";
//		break;
//	case enGrade::E:
//		cout << "\nDecent (E)\n";
//		break;
//	case enGrade::F:
//		cout << "\nFalied (F)\n";
//		break;
//	default:
//		break;
//	}
//}

int ReadNumberInRange(int From, int To)
{
	int Grade;

	do
	{
		cout << "Please enter the grade (" << From << " - " << To << "): ";
		cin >> Grade;

	} while (Grade < From || Grade > To);

	return Grade;
}

char GetGradeLetter(int Grade)
{
	if (Grade >= 90)
		return 'A';

	else if (Grade >= 80)
		return 'B';

	else if (Grade >= 70)
		return 'C';

	else if (Grade >= 60)
		return 'D';

	else if (Grade >= 50)
		return 'E';

	else
		return 'F';

}

int main()
{
	// this was my way.
	//PrintResult(ReadGrade());

	cout << GetGradeLetter(ReadNumberInRange(0, 100)) << endl;
	cout << GetGradeLetter(ReadNumberInRange(0, 100)) << endl;
	cout << GetGradeLetter(ReadNumberInRange(0, 100)) << endl;
	cout << GetGradeLetter(ReadNumberInRange(0, 100)) << endl;
	cout << GetGradeLetter(ReadNumberInRange(0, 100)) << endl;
	cout << GetGradeLetter(ReadNumberInRange(0, 100)) << endl;

	return 0;
}