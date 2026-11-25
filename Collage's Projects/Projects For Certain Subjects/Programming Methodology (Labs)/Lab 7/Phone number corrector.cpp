#include <iostream>
#include <string>
using namespace std;

short ReadNumberOfPhoneNumbers()
{
	short NumberOfPhoneNumbers;

	do
		cin >> NumberOfPhoneNumbers;
	while (NumberOfPhoneNumbers < 1);

	return NumberOfPhoneNumbers;
}

string ReadPhoneNumberAndCorrectIt()
{
	string PhoneNumber;
	cin >> PhoneNumber;

	if (PhoneNumber[0] != '4')
	{
		string BasePhoneNumber = PhoneNumber;
		PhoneNumber = "(407) " + BasePhoneNumber;
	}

	return PhoneNumber;
}

void PrintPhoneNumbersAfterCorrection(short NumberOfPhoneNumbers)
{
	for (short i = 0; i < NumberOfPhoneNumbers; i++)
	{
		string PhoneNumber = ReadPhoneNumberAndCorrectIt();
		cout << PhoneNumber << endl;
	}
}

int main() {

	short NumberOfPhoneNumbers = ReadNumberOfPhoneNumbers();
	PrintPhoneNumbersAfterCorrection(NumberOfPhoneNumbers);

	return 0;
}