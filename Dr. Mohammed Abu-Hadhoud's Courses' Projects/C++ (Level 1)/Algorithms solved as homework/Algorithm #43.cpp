#include <iostream>
using namespace std;

void PrintDurationFromSeconds(int TotalSeconds)
{
	const unsigned int SecondsPerDay = 24 * 60 * 60;
	const unsigned short int SecondsPerHour = 60 * 60;
	const unsigned short int SecondsPerMinute = 60;

	// Although they are all shorts, Remainder can't be short; as it might hold less than a days as seconds, which are about 80K.	// Although they are all shorts, Remainder can't be short; as it might hold less than a days as seconds, which are about 80K.
	unsigned short int Days = floor(TotalSeconds / SecondsPerDay);
	unsigned int Remainder = TotalSeconds % SecondsPerDay;

	unsigned short int Hours = floor(Remainder / SecondsPerHour);
	Remainder = Remainder % SecondsPerHour;

	unsigned short int Minutes = floor(Remainder / SecondsPerMinute);
	Remainder = Remainder % SecondsPerMinute; // Now it holds the remaining seconds less than a minute.

	cout << Days << " : " << Hours << " : " << Minutes << " : " << Remainder << endl;
}

int main()
{
	unsigned int TotalSeconds;

	cout << "Please enter the total seconds: ";
	cin >> TotalSeconds;

	cout << endl;

	PrintDurationFromSeconds(TotalSeconds);

	return 0;

	// The Old Way.
	//// Although they are all shorts, Remainder can't be short; as it might hold less than a days as seconds, which are about 80K.	// Although they are all shorts, Remainder can't be short; as it might hold less than a days as seconds, which are about 80K.
	//unsigned short int Days = floor(TotalSeconds / SecondsPerDay);
	//unsigned int Remainder = TotalSeconds % SecondsPerDay; 
	//
	//unsigned short int Hours = floor(Remainder / SecondsPerHour);
	//Remainder = Remainder % SecondsPerHour;

	//unsigned short int Minutes = floor(Remainder / SecondsPerMinute);
	//Remainder = Remainder % SecondsPerMinute; // Now it holds the remaining seconds less than a minute.

	//cout << Days << " : " << Hours << " : " << Minutes << " : " << Remainder << endl;
		 
}