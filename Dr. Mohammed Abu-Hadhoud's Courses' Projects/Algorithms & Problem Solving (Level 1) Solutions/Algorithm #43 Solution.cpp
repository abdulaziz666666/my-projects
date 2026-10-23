#include <iostream>
#include <cmath>
using namespace std;

struct stTaskDuration
{
	unsigned short Days, Hours, Minutes, Seconds;
};

int ReadPositiveNumber(string Message)
{
	int Num;

	do
	{
		cout << Message << " (Should be positive): " << endl;
		cin >> Num;

	} while (Num <= 0);

	return Num;
}

int SecondsToDays(int Seconds)
{
	const int SECONDS_IN_DAY = 24 * 60 * 60;
	return Seconds % SECONDS_IN_DAY;
}

int SecondsToHours(int Seconds)
{
	const int SECONDS_IN_HOUR = 60 * 60;
	return Seconds % SECONDS_IN_HOUR;
}

int SecondsToMinutes(int Seconds)
{
	const int SECONDS_IN_MINUTE = 60;
	return Seconds % SECONDS_IN_MINUTE;
}

//stTaskDuration CalculateTaskDuration(int Seconds)
stTaskDuration SecondsToTaskDuration(int Seconds)
{
	unsigned short Days, Hours, Minutes;
	unsigned RemainingSeconds = Seconds;

	const int SECONDS_IN_DAY = 24 * 60 * 60;
	int SECONDS_IN_HOUR = 60 * 60;
	int SECONDS_IN_MINUTE = 60;

	stTaskDuration TaskDuration;

	TaskDuration.Days = floor(RemainingSeconds / SECONDS_IN_DAY);
	RemainingSeconds %= SECONDS_IN_DAY;

	TaskDuration.Hours = floor(RemainingSeconds / SECONDS_IN_HOUR);
	RemainingSeconds %= SECONDS_IN_HOUR;

	TaskDuration.Minutes = floor(RemainingSeconds / SECONDS_IN_MINUTE);
	RemainingSeconds %= SECONDS_IN_MINUTE;

	TaskDuration.Seconds = RemainingSeconds;

	return TaskDuration;

	//Days = floor(RemainingSeconds / SECONDS_IN_DAY);
	//RemainingSeconds %= SECONDS_IN_DAY;

	//Hours = floor(RemainingSeconds / SECONDS_IN_HOUR);
	//RemainingSeconds %= SECONDS_IN_HOUR;

	//Minutes = floor(RemainingSeconds / SECONDS_IN_MINUTE);
	//RemainingSeconds %= SECONDS_IN_MINUTE;

	//TaskDuration.Days = Days;
	//TaskDuration.Hours = Hours;
	//TaskDuration.Minutes = Minutes;
	//TaskDuration.Seconds = RemainingSeconds;
}

void PrintTaskDurationDetails(stTaskDuration TaskDuration)
{
	cout << endl;
	cout << TaskDuration.Days << " Days\n";
	cout << TaskDuration.Hours << " Hours\n";
	cout << TaskDuration.Minutes << " Minutes\n";
	cout << TaskDuration.Seconds << " Seconds\n";
}

int main()
{
	int TotalSeconds = ReadPositiveNumber("Please enter the TotalSeconds");
	stTaskDuration TaskDuration = SecondsToTaskDuration(TotalSeconds);

	PrintTaskDurationDetails(TaskDuration);

	return 0;
}