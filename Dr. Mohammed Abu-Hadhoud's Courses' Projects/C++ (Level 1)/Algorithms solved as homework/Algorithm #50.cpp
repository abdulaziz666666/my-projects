#include <iostream>
using namespace std;

struct stAccount
{
	const unsigned short PIN = 1234;
	bool isLoggedSuccessfully;
	float Balance = 7500;
};

void ReadPIN(stAccount &Account)
{
	unsigned short PIN;

	cout << "Please enter the PIN to see your balance:" << endl;
	cin >> PIN;

	unsigned short Tries = 2;

	while (PIN != Account.PIN && Tries > 0)
	{
		cout << "Wrong PIN, you have " << Tries << " tries left" << endl;
		cout << "Please enter the PIN to see your balance:" << endl;
		cin >> PIN;

		Tries--;
	}

	if (PIN != Account.PIN)
	{
		cout << "\nYour Card is locked!\n";
		Account.isLoggedSuccessfully = false;
	}
	else
	{
		Account.isLoggedSuccessfully = true;
	}
}

void ShowBalance(stAccount Account)
{
	if (Account.isLoggedSuccessfully)
	{
		cout << "\nYour Balance: " << Account.Balance << endl;
	}
}

int main()
{
	stAccount MyAccount;

	ReadPIN(MyAccount);
	ShowBalance(MyAccount);

	return 0;
}