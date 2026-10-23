#include <iostream>
#include <string>
using namespace std;

string ReadPassword()
{
	string Password;

	do
	{
		cout << "Please enter the password (Should be 3-letter long): ";
		cin >> Password;

	} while (Password.length() > 3);

	return Password;
}

string ConcatinateCharachtersInString(char chars[20], short length)
{
	string str;
	str = chars[0];

	for (int i = 1; i < length; i++)
		str += chars[i];

	return str;
}

bool FindPassword(string TargetPassword)
{

	int Tries = 0;
	string Password;

	cout << endl;
	for (int i = 65; i <= 90; i++)
	{
		for (int j = 65; j <= 90; j++)
		{
			for (int k = 65; k <= 90; k++)
			{
				Tries++;
				
				//Password = ConcatinateCharachtersInString() // would be great but not now.
				// i don't have to re-assign PASSWORD's value as it is re-assigned here.
				Password = char(i); 
				Password += char(j);
				Password += char(k);

				cout << "Trial [" << Tries << "]: " << Password << "\n";

				if (Password == TargetPassword)
				{
					cout << "\nPassword is " << Password << endl;
					cout << "Founded after " << Tries << " Trial(s)\n";
					return true;
				}
			}

		}
	}

	return false;
}

int main()
{
	string TargetPassword = ReadPassword();
	FindPassword(TargetPassword);
	return 0;
}