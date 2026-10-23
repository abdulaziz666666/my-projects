#include <iostream>
using namespace std;

int GetDurationAsSeconds(int Days, int Hours, int Minutes, int Seconds)
{
	unsigned int SecondsPerDay = Days * 24 * 60 * 60;
	unsigned int SecondsPerHour = Hours * 60 * 60;
	unsigned short int SecondsPerMinute = Minutes * 60;

	int TotalDurationInSeconds = SecondsPerDay + SecondsPerHour + SecondsPerMinute + Seconds;

	return TotalDurationInSeconds;
}

void PrintDuration(int DurationInSeconds)
{
	cout << endl << "The total work on the project was: " << DurationInSeconds << " Seconds." << endl;
}

int main()
{
	unsigned short int Days, Hours, Minutes, Seconds;

	cout << "Please enter the following:" << endl;

	cout << "Days: ";
	cin >> Days;

	cout << "Hours: ";
	cin >> Hours;

	cout << "Minutes: ";
	cin >> Minutes;

	cout << "Seconds: ";
	cin >> Seconds;

	// The Old Way.
	//unsigned int SecondsPerDay = Days * 24 * 60 * 60;
	//unsigned int SecondsPerHour = Hours * 60 * 60;
	//unsigned short int SecondsPerMinute = Minutes * 60;

	//int TotalDurationInSeconds = SecondsPerDay + SecondsPerHour + SecondsPerMinute + Seconds;
	//cout << endl << "The total work on the project was: " << TotalDurationInSeconds << " Seconds." << endl;

	int Duration = GetDurationAsSeconds(Days, Hours, Minutes, Seconds);
	PrintDuration(Duration);

	return 0;
}