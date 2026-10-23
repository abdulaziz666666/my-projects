#include <iostream>
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
		cout << Message << " (It should be positive): " << endl;
		cin >> Num;
	} while (Num < 0);

	return Num;
}

stTaskDuration ReadTaskDuration()
{
	stTaskDuration TaskDuration;

	TaskDuration.Days = ReadPositiveNumber("Please enter the days");
	TaskDuration.Hours = ReadPositiveNumber("Please enter the Hours");
	TaskDuration.Minutes = ReadPositiveNumber("Please enter the Minutes");
	TaskDuration.Seconds = ReadPositiveNumber("Please enter the Seconds");

	return TaskDuration;
}

//int CalculateTaskDuration(stTaskDuration TaskDuration)
int TaskDurationInSeconds(stTaskDuration TaskDuration)
{
	unsigned int TotalSeconds;

	TotalSeconds = TaskDuration.Seconds;
	TotalSeconds += TaskDuration.Minutes * 60;
	TotalSeconds += TaskDuration.Hours * 60 * 60;
	TotalSeconds += TaskDuration.Days * 24 * 60 * 60;

	return TotalSeconds;
}

int main()
{
	stTaskDuration TaskDuration = ReadTaskDuration();
	
	cout << endl;
	cout << "Total Seconds of that Task: " << TaskDurationInSeconds(TaskDuration) << " Seconds" << endl;

	return 0;
}