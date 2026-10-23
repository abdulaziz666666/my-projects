#include <iostream>
using namespace std;

int ReadPositiveNumber(string Message)
{
	int Num;

	do
	{
		cout << Message + " (Should be positive): ";
		cin >> Num;
	} while (Num <= 0);

	return Num;
}
//
//float CalculateWeeksFromHours(int Hours)
//{ 
//	const short HOURS_IN_WEEK = 24 * 7;
//	return (float)Hours / HOURS_IN_WEEK;
//}
//
//float CalculateDaysFromHours(int Hours)
//{ 
//	const short HOURS_IN_DAY = 24;
//	return (float)Hours / HOURS_IN_DAY;
//}

float HoursToDays(int Hours)
{
	return (float)Hours / 24;
}

float DaysToWeeks(int Days)
{
	return (float)Days / 7;
}

float HoursToWeeks(int Hours)
{
	return (float)Hours / 24 / 7;
}

void PrintHoursInWeeksAndDays(int Hours, float Days, float Weeks)
{
	cout << endl;
	cout << "In Hours: " << Hours << endl;
	cout << "In Days: " << Days << endl;
	cout << "In Weeks: " << Weeks << endl;
	//cout << CalculateDaysFromHours(Hours) << " Days" << endl;
	//cout << CalculateWeeksFromHours(Hours) << " Weeks" << endl;
}

int main()
{
	int Hours = ReadPositiveNumber("Please enter the hours");
	float Days = HoursToDays(Hours);
	float Weeks = DaysToWeeks(Days);

	PrintHoursInWeeksAndDays(Hours, Days, Weeks);
	PrintHoursInWeeksAndDays(Hours, Days, HoursToWeeks(Hours));

	return 0;
}