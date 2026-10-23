#include <iostream>
using namespace std;

enum enWeekDay { Sun = 1, Mon, Tue, Wed, Thu, Fri, Sat };

void ShowWeekDaysMenu()
{
	cout << "*******************" << endl;
	cout << "     Week Days     " << endl;
	cout << "*******************" << endl;
	cout << "1: Sunday" << endl;
	cout << "2: Monday" << endl;
	cout << "3: Tuesday" << endl;
	cout << "4: Wednesday" << endl;
	cout << "5: Thurday" << endl;
	cout << "6: Friday" << endl;
	cout << "7: Saturday" << endl;
	cout << "*******************" << endl;

	cout << endl;
}

enWeekDay ReadWeekDay()
{
	int DayNumber;
	
	cout << "Please enter the current day number: ";
	cin >> DayNumber;

	return (enWeekDay)DayNumber;
}

string GetWeekDayName(enWeekDay WeekDay)
{
	switch (WeekDay)
	{
	case enWeekDay::Sun:
		return "Sunday";
		break;

	case enWeekDay::Mon:
		return "Monday";
		break;

	case enWeekDay::Tue:
		return "Tuesday";
		break;

	case enWeekDay::Wed:
		return "Wednesday";
		break;

	case enWeekDay::Thu:
		return "Thursday";
		break;

	case enWeekDay::Fri:
		return "Friday";
		break;

	case enWeekDay::Sat:
		return "Saturday";
		break;
	default:
		return "not a week day!";
	}
}

int main()
{
	ShowWeekDaysMenu();
	
	string Today = GetWeekDayName(ReadWeekDay());
	cout << "Today is " << Today << endl;

	return 0;
}