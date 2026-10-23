#include <iostream>
using namespace std;

enum enMonthOfYear { Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec };

int ReadNumberInRange(int From, int To, string Target)
{
	int Num;

	do
	{
		cout << "Please enter (" << Target << ")\n";
		cout << "It should be between " << From << " and " << To << ": ";
		cin >> Num;

	} while (Num < From || Num > To);

	return Num;
}

enMonthOfYear ReadMonthOfYear()
{
	int MonthNumber = ReadNumberInRange(1, 12, "Month Number");
	return (enMonthOfYear)MonthNumber;
}

string GetMonthName(enMonthOfYear Month)
{
	switch (Month)
	{
	case enMonthOfYear::Jan:
		return "January";
		
	case enMonthOfYear::Feb:
		return "February";
		
	case enMonthOfYear::Mar:
		return "March";
		
	case enMonthOfYear::Apr:
		return "April";
		
	case enMonthOfYear::May:
		return "May";
		
	case enMonthOfYear::Jun:
		return "June";
		
	case enMonthOfYear::Jul:
		return "July";
		
	case enMonthOfYear::Aug:
		return "August";
		
	case enMonthOfYear::Sep:
		return "September";
		
	case enMonthOfYear::Oct:
		return "October";
		
	case enMonthOfYear::Nov:
		return "November";
		
	case enMonthOfYear::Dec:
		return "December";
	default:
		return "Invalid Month";
	}
}

int main()
{

	string MonthName = GetMonthName(ReadMonthOfYear());

	cout << endl; // Differentiating input from output.
	cout << "It is " << MonthName << endl;

	return 0;
}