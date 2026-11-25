#pragma warning (disable : 4996)

#include <iostream>
#include <ctime>
using namespace std;

struct stTime
{
	time_t CurrentTimeRawData;
	tm* Details;
	char* TimeInfoAsString;
	string TimeSymbol;
};

string GetTimeSymbol(short CurrentHour)
{
	return (CurrentHour >= 12) ? "PM" : "AM";
}

void PrepareTimeData(stTime& Time)
{
	Time.CurrentTimeRawData = time(0);
	Time.TimeInfoAsString = ctime(&Time.CurrentTimeRawData);

	Time.Details = localtime(&Time.CurrentTimeRawData);
	Time.TimeSymbol = GetTimeSymbol(Time.Details->tm_hour);
}

void ShowCurrentTime(stTime &Time)
{
	printf("%0*d:%0*d\n",
		2, Time.Details->tm_hour % 12,
		2, Time.Details->tm_min);
}

int main()
{
	stTime Time;

	PrepareTimeData(Time);
	ShowCurrentTime(Time);

	return 0;
}