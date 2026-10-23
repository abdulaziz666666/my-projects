#include <iostream>
using namespace std;

void ReadMonthNumber(unsigned short& MonthNumber)
{
	cout << "Please enter the number of the month: ";
	cin >> MonthNumber;

	cout << endl;
}

void PrintMonth(unsigned short MonthNumber)
{
	switch (MonthNumber)
	{
	case 1:
		cout << "January" << endl;
		break;

	case 2:
		cout << "February" << endl;
		break;

	case 3:
		cout << "March" << endl;
		break;

	case 4:
		cout << "April" << endl;
		break;

	case 5:
		cout << "May" << endl;
		break;

	case 6:
		cout << "Jun" << endl;
		break;

	case 7:
		cout << "July" << endl;
		break;

	case 8:
		cout << "August" << endl;
		break;

	case 9:
		cout << "September" << endl;
		break;

	case 10:
		cout << "October" << endl;
		break;

	case 11:
		cout << "November" << endl;
		break;

	case 12:
		cout << "December" << endl;
		break;

	default:
		cout << "Wrong Month" << endl;
	}
	// The past way.
	//if (MonthNumber >= 1 && MonthNumber <= 12)
	//{
	//	if (MonthNumber == 1)
	//	{
	//		cout << "January" << endl;
	//	}
	//	else if (MonthNumber == 2)
	//	{
	//		cout << "February" << endl;
	//	}
	//	else if (MonthNumber == 3)
	//	{
	//		cout << "March" << endl;
	//	}
	//	else if (MonthNumber == 4)
	//	{
	//		cout << "April" << endl;
	//	}
	//	else if (MonthNumber == 5)
	//	{
	//		cout << "May" << endl;
	//	}
	//	else if (MonthNumber == 6)
	//	{
	//		cout << "Jun" << endl;
	//	}
	//	else if (MonthNumber == 7)
	//	{
	//		cout << "July" << endl;
	//	}
	//	else if (MonthNumber == 8)
	//	{
	//		cout << "August" << endl;
	//	}
	//	else if (MonthNumber == 9)
	//	{
	//		cout << "September" << endl;
	//	}
	//	else if (MonthNumber == 10)
	//	{
	//		cout << "October" << endl;
	//	}
	//	else if (MonthNumber == 11)
	//	{
	//		cout << "November" << endl;
	//	}
	//	else
	//	{
	//		cout << "December" << endl;
	//	}
	//}
	//else {
	//	cout << "Wrong Month" << endl;
	//}
}

int main()
{
	unsigned short MonthNumber;

	ReadMonthNumber(MonthNumber);
	PrintMonth(MonthNumber);

	return 0;
}