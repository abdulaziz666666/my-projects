#include <iostream>
using namespace std;

void ReadDayNumber(unsigned short &DayNumber)
{
	cout << "Please enter the number of the day: ";
	cin >> DayNumber;

	cout << endl;
}

void PrintDay(unsigned short DayNumber)
{
	switch (DayNumber)
	{
	case 1:
		cout << "Sunday" << endl;
		break;
		
	case 2:
		cout << "Monday" << endl;
		break;
		
	case 3:
		cout << "Tuesday" << endl;
		break;
		
	case 4:
		cout << "Wednesday" << endl;
		break;
		
	case 5:
		cout << "Thursday" << endl;
		break;
		
	case 6:
		cout << "Friday" << endl;
		break;
		
	case 7:
		cout << "Saturday" << endl;
		break;

	default:
		cout << "Not a week day!" << endl;
	}
	// The past way.
	//if (DayNumber >= 1 && DayNumber <= 7)
	//{
	//	if (DayNumber == 1)
	//	{
	//		cout << "Sunday" << endl;
	//	}
	//	else if (DayNumber == 2)
	//	{
	//		cout << "Monday" << endl;
	//	}
	//	else if (DayNumber == 3)
	//	{
	//		cout << "Tuesday" << endl;
	//	}
	//	else if (DayNumber == 4)
	//	{
	//		cout << "Wednesday" << endl;
	//	}
	//	else if (DayNumber == 5)
	//	{
	//		cout << "Thursday" << endl;
	//	}
	//	else if (DayNumber == 6)
	//	{
	//		cout << "Friday" << endl;
	//	}
	//	else
	//	{
	//		cout << "Saturday" << endl;
	//	}
	//}
	//else {
	//	cout << "Wrong day" << endl;
	//}
}

int main()
{
	unsigned short DayNumber;

	ReadDayNumber(DayNumber);
	PrintDay(DayNumber);

	return 0;
}