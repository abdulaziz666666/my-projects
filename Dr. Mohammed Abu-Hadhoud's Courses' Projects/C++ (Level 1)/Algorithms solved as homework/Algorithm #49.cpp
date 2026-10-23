#include <iostream>
using namespace std;

struct stAccount
{
	const string PIN = "1234";
	float Balance = 7500;
};

void ReadPIN(string &PIN)
{
	cout << "Please enter the PIN: ";
	cin >> PIN;

	cout << endl;
}

void PrintBalance(stAccount Account, string PIN)
{
	if (PIN == Account.PIN)
	{
		cout << "Your balance is " << Account.Balance << endl;
	}
	else
	{
		cout << "Wrong PIN" << endl;
	}
}

int main()
{
	stAccount MyAccount;
	string PIN;

	ReadPIN(PIN);
	PrintBalance(MyAccount, PIN);

	return 0;
}