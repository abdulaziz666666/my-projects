#include <iostream>
using namespace std;

enum enDayOfWeek { Sun = 1, Mon, Tue, Wed, Thu, Fri, Sat };

int ReadNumberInRange(int From, int To, string Target)
{
	int Num;

	do
	{
		cout << "You should enter (" << Target << ")\n";
		cout << "Please enter a number between " << From << " and " << To << ": ";
		cin >> Num;

	} while (Num < From || Num > To);

	return Num;
}

enDayOfWeek ReadDayOfWeek()
{
	int DayNumber = ReadNumberInRange(1, 7, "Day Number");

	return (enDayOfWeek)DayNumber;
}

string GetDayName(enDayOfWeek Day)
{
	switch (Day)
	{
	case enDayOfWeek::Sun:
		return "Sunday";

	case enDayOfWeek::Mon:
		return "Monday";

	case enDayOfWeek::Tue:
		return "Tuesday";

	case enDayOfWeek::Wed:
		return "Wednesday";

	case enDayOfWeek::Thu:
		return "Thuesday";

	case enDayOfWeek::Fri:
		return "Friday";

	case enDayOfWeek::Sat:
		return "Saturday";
	}
}

int main()
{
	string Day = GetDayName(ReadDayOfWeek());

	cout << endl; // differentiating the input and the output
	cout << "it is " << Day << endl;

	return 0;
}