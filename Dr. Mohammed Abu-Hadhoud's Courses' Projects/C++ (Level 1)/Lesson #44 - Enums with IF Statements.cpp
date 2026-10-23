#include <iostream>
using namespace std;

enum enScreenColor { Red = 1, Green = 2, Blue = 3, Yellow = 4 };
enum enCountry {KSA=1, Egypt, Kuwait, Qatar, UAE, Syria, Other};

const string Countries[7] = { "Saudi Arabia", "Egypt", "Kuwait", "Qatar", "United Arabian Emirates", "Syria", "Other Country" };

void Example1()
{
	cout << "**********************************\n";
	cout << "Please enter the number of your favourite color:\n";
	cout << "(1) Red\n";
	cout << "(2) Green\n";
	cout << "(3) Blue\n";
	cout << "(4) Yellow\n";
	cout << "**********************************\n";
	cout << "Your Choice: ";

	int C;
	enScreenColor Color;

	cin >> C;
	Color = (enScreenColor)C;

	if (Color == enScreenColor::Red)
	{
		system("color 4F");
	}
	else if (Color == enScreenColor::Green)
	{
		system("color 2F");
	}
	else if (Color == enScreenColor::Blue)
	{
		system("color 1F");
	}
	else if (Color == enScreenColor::Yellow)
	{
		system("color 6F");
	}
	else
	{
		system("color 4F");
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

	// A great alternative
	//if (CountryNumber >= 1 && CountryNumber <= 7)
	//{
	//	cout << "You choose " << ::Countries[CountryNumber - 1] << endl;
	//}
	//else 
	//{
	//	cout << "You choose Another Country" << endl;
	//}

	if (ChosenCountry == enCountry::KSA)
	{
		cout << "You choose Saudi Arabia" << endl;
	}
	else if (ChosenCountry == enCountry::Egypt)
	{
		cout << "You choose Egypt" << endl;
	}
	else if (ChosenCountry == enCountry::Kuwait)
	{
		cout << "You choose Kuqait" << endl;
	}
	else if (ChosenCountry == enCountry::UAE)
	{
		cout << "You choose United Arabian Emirates" << endl;
	}
	else if (ChosenCountry == enCountry::Qatar)
	{
		cout << "You choose Qatar" << endl;
	}
	else if (ChosenCountry == enCountry::Syria)
	{
		cout << "You choose Syria" << endl;
	}
	else
	{
		cout << "You choose another country" << endl;
	}
}

int main()
{
	Example2();
	return 0;
}