#include <iostream>
using namespace std;

enum enCountry {KSA=1, Egypt, Kuwait, Qatar, UAE, Syria, Other};

void Example1()
{
	int Day = 4;

	switch (Day)
	{
	case 1:
		cout << "Sunday\n";
		break;
	case 2:
		cout << "Monday\n";
		break;
	case 3:
		cout << "Tuesday\n";
		break;
	case 4:
		cout << "Wednesday\n";
		break;
	case 5:
		cout << "Thursday\n";
		break;
	case 6:
		cout << "Friday\n";
		break;
	case 7:
		cout << "Saturday\n";
		break;
	default:
		cout << "Not a week day!\n";
	}

}

void Example2()
{
	cout << "**********************************\n";
	cout << "Please enter the number of your country:\n";
	cout << "(1) Saudi Arabia\n";
	cout << "(2) Egypt\n";
	cout << "(3) Kuwait\n";
	cout << "(4) Qatar\n";
	cout << "(5) UAE\n";
	cout << "(6) Syria\n";
	cout << "(7) Other\n";
	cout << "**********************************\n";
	cout << "Your Choice: ";

	int CountryNumber;
	enCountry ChosenCountry;

	cin >> CountryNumber;

	ChosenCountry = (enCountry)CountryNumber;

	switch (ChosenCountry)
	{
	case enCountry::KSA:
		cout << "You choose Saudi Arabia" << endl;
		break;

	case enCountry::Egypt:
		cout << "You choose Saudi Arabia" << endl;
		break;

	case enCountry::Kuwait:
		cout << "You choose Saudi Arabia" << endl;
		break;

	case enCountry::Qatar:
		cout << "You choose Saudi Arabia" << endl;
		break;

	case enCountry::UAE:
		cout << "You choose Saudi Arabia" << endl;
		break;

	case enCountry::Syria:
		cout << "You choose Saudi Arabia" << endl;
		break;

	default:
		cout << "You choose Another Country" << endl;
	}
}

int main()
{
	Example2();
	return 0;
}