#pragma warning(disable : 4996)

#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	time_t CurrentTimeData = time(0); // as raw data lets say.
	char* FormatedCurrentTime = ctime(&CurrentTimeData); // as string
	cout << FormatedCurrentTime << endl;

	tm* gmtmData = gmtime(&CurrentTimeData); // converting the local time to GMT
	FormatedCurrentTime = asctime(gmtmData);
	cout << "UTC date and time: " << FormatedCurrentTime << endl;

	return 0;
}