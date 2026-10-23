#include <iostream>
using namespace std;

string ReadPINCode()
{
	string PINCode;

	cout << "Please enter the PINCode: ";
	cin >> PINCode;

	return PINCode;
}
//
//bool CheckPINCode(string PINCode)
//{
//	return PINCode == "1234";
//}
//
//void PrintBalance(string PINCode)
//{
//	if (CheckPINCode(PINCode))
//		cout << "\nYours balance is 7500\n";
//	else
//		cout << "\nWrong PINCode\n";
//}

bool Login()
{
	string PINCode;
	
	do
	{
		PINCode = ReadPINCode();

		if (PINCode == "1234")
		{
			return true;
		}
		else
		{
			cout << "\nWrong PINCode\n";
			system("color 4F");
		}
	} while (PINCode != "1234"); 
	// i can also put while(true); and it will be fine.
	// although i wrote like what dr.Mohammed wrote, i see using true is clearer; it shows 
	// that the loop will be repeated forever until the user enter the correct PIN Code.
}

int main()
{
	//PrintBalance(ReadPINCode());
	if (Login())
	{
		system("color 2F");
		cout << "\nYour balance is " << 7500 << endl;
	}

	return 0;
}