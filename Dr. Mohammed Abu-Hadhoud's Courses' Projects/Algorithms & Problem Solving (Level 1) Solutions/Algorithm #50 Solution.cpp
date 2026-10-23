#include <iostream>
using namespace std;

string ReadPINCode()
{
	string PINCode;

	cout << "Please enter the PIN Code: " << endl;
	cin >> PINCode;

	return PINCode;
}

bool Login()
{
	string PINCode;
	int Tries = 3;
	
	do
	{
		PINCode = ReadPINCode();
		Tries--;

		if (PINCode == "1234")
			return true;
		else
		{
			cout << "\nWrong PIN Code\n";
			cout << Tries << " tries left\n";
			system("color 4F");
		}

	} while (Tries > 0);

	return false;
}

void ShowAccountBalance()
{
	if (Login())
	{
		cout << "\nYour Balance: " << 7500 << endl;
		system("color 2F");
	}
	else
	{ 
		cout << "\nYour Card is Locked. Call the bank for help.\n";
	}
}

int main()
{
	ShowAccountBalance();
	return 0;
}