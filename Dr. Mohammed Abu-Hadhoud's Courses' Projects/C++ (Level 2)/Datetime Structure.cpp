#pragma warning (disable : 4996)

#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	time_t CurrentTimeData = time(0);
	tm* stLocalTime = localtime(&CurrentTimeData);

	cout << stLocalTime->tm_hour << " : " << stLocalTime->tm_min;

	return 0;
}