#include <iostream>
using namespace std;

struct stFullName
{
	string FirstName;
	string LastName;
};

stFullName ReadFullName()
{
	stFullName FullName;

	cout << "Please enter your first name: ";
	cin >> FullName.FirstName;

	cout << "Please enter your last name: ";
	cin >> FullName.LastName;

	return FullName;
}

//void PrintFullName(stFullName FullName)
//{
//	cout << "Your Full Name: ";
//	cout << FullName.FirstName << " " << FullName.LastName << endl;
//}

string GetFullName(stFullName FullName, bool Reversed)
{
	// Dr. Mohammed made a string variable "FullName" and concatinate the first
	// and last name with a space in between.. which i tkink is meaningless
	// at least in that particular example.

	if (Reversed)
		return FullName.LastName + " " + FullName.FirstName;
	else
		return FullName.FirstName + " " + FullName.LastName;
}

void PrintFullName(string FullName)
{
	cout << "Your Full Name: " << FullName << endl;
}

int main()
{
	//PrintFullName(ReadFullName());
	PrintFullName(GetFullName(ReadFullName(), true));
	return 0;
} 