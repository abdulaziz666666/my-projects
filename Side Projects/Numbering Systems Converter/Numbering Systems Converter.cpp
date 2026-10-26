#include <iostream>
#include <cmath>
#include <string>
using namespace std;

enum enNumberingSystem { Binary = 1, Octal, Decimal };

struct stNumber
{
	string TextualNumber = "";
	enNumberingSystem NumberingSystem;
};

bool CheckValidityForNumberingSystems(char Digit)
{
	Digit = int(Digit);

	bool DigitInNumbersRange = (Digit >= 48 && Digit <= 57);

	return DigitInNumbersRange;
}

bool UserEnteredInvalidNumber(string TextualNumber)
{
	for (int i = 0; i < TextualNumber.length(); i++)
		if (!CheckValidityForNumberingSystems(TextualNumber[i]))
			// for each digit, if it's NOT valid: return true (invalid digit found in user input).
			return true; 

	return false; // otherwise, the number is valid (no need to ask again).
}

string ReadTextualNumber()
{
	string TextualNumber;

	do
	{
		cout << "Please enter the original number: ";
		cin >> TextualNumber;

	} while (UserEnteredInvalidNumber(TextualNumber));

	return TextualNumber;
}

enNumberingSystem ReadNumberingSystem(string TargetNumber)
{
	short NumberOfNumberingSystem;

	cout << "1- Binary\n";
	cout << "2- Octal\n";
	cout << "3- Decimal\n";
	cout << endl;

	do
	{
		cout << "Please enter the " << TargetNumber << " number's system (1-3): ";
		cin >> NumberOfNumberingSystem;

	} while (NumberOfNumberingSystem < 1 || NumberOfNumberingSystem > 3);

	return (enNumberingSystem)NumberOfNumberingSystem;
}

void ReadOriginalNumberInfo(stNumber &OriginalNumber)
{
	OriginalNumber.TextualNumber = ReadTextualNumber();
	OriginalNumber.NumberingSystem = ReadNumberingSystem("original");
}

short GetNumberingSystemBase(enNumberingSystem NumberingSystem)
{
	switch (NumberingSystem)
	{
	case enNumberingSystem::Binary:
		return 2;
	case enNumberingSystem::Octal:
		return 8;
	case enNumberingSystem::Decimal:
		return 10;
	}
}


string ConvertToDecimal(stNumber OriginalNumber)
{
	if (OriginalNumber.NumberingSystem == enNumberingSystem::Decimal)
		return OriginalNumber.TextualNumber;

	int ConvertedNumber = 0;

	int Base = GetNumberingSystemBase(OriginalNumber.NumberingSystem);
	int Temp = stoi(OriginalNumber.TextualNumber);

	for (int i = 0; i < OriginalNumber.TextualNumber.length(); i++)
	{
		ConvertedNumber += pow(Base, i) * (Temp % Base);
		Temp /= Base;
	}

	return to_string(ConvertedNumber);
}

string GetReversedText(string Text)
{
	string ReveredText = "";

	for (int i = Text.length() - 1; i >= 0; i--)
		ReveredText += Text[i];

	return ReveredText;
}

string ConvertToBasesOtherThanDecimal(string TextualNumber, int Base)
{
	string ConvertedNumber = "";
	int Temp = stoi(TextualNumber);

	while (Temp > 0)
	{
		ConvertedNumber += to_string(Temp % Base);
		Temp /= Base;
	}

	return GetReversedText(ConvertedNumber);
}

string ConvertToBaseN(stNumber Number)
{
	short Base = GetNumberingSystemBase(Number.NumberingSystem);

	if (Base == 10)
		return ConvertToDecimal(Number);
	else
		return ConvertToBasesOtherThanDecimal(Number.TextualNumber, Base);
}

string GetConvertedTextualNumber(stNumber OriginalNumber, enNumberingSystem ConvertToWhichSystem)
{
	// This function converts numbers by converting to decimal firstly,
	// then, convert to whatever system was selected.
	
	if (OriginalNumber.NumberingSystem == ConvertToWhichSystem)
		return OriginalNumber.TextualNumber;
	
	stNumber ConvertedNumber;

	ConvertedNumber.NumberingSystem = ConvertToWhichSystem;
	ConvertedNumber.TextualNumber = ConvertToDecimal(OriginalNumber);

	return ConvertToBaseN(ConvertedNumber);
}

void FillConvertedNumberInfo(stNumber OriginalNumber, stNumber& ConvertedNumber)
{
	ConvertedNumber.NumberingSystem = ReadNumberingSystem("converted");
	ConvertedNumber.TextualNumber = GetConvertedTextualNumber(OriginalNumber, ConvertedNumber.NumberingSystem);
}

void ShowResult(stNumber OriginalNumber, stNumber ConvertedNumber)
{
	cout << "\nThe Original Number " << OriginalNumber.TextualNumber;
	cout << " with base " << GetNumberingSystemBase(OriginalNumber.NumberingSystem) << endl;

	cout << "\nThe Converted Number " << ConvertedNumber.TextualNumber;
	cout << " with base " << GetNumberingSystemBase(ConvertedNumber.NumberingSystem) << endl;
}

void StartProgram()
{
	stNumber OriginalNumber, ConvertedNumber;

	ReadOriginalNumberInfo(OriginalNumber);
	FillConvertedNumberInfo(OriginalNumber, ConvertedNumber);
	
	ShowResult(OriginalNumber, ConvertedNumber);
}

int main()
{

	StartProgram();

	return 0;
}