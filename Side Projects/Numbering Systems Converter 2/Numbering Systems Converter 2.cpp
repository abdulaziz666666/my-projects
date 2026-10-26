#include <iostream>
#include <cmath>
#include <string>
using namespace std;

enum enNumberingSystem { Binary = 1, Octal, Decimal, Hexadecimal};

struct stNumber
{
	string TextualNumber = "";
	enNumberingSystem NumberingSystem;
	short Base;
};

bool IsNumeralChar(int CharAsciiCode, int FromNumber, int ToNumber)
{
	return (CharAsciiCode >= int(FromNumber + '0') && CharAsciiCode <= int(ToNumber + '0'));
}

bool IsAlphabeticChar(int CharAsciiCode, char FromChar, char ToChar)
{
	return (CharAsciiCode >= int(FromChar) && CharAsciiCode <= int(ToChar));
}

bool IsHexChar(int CharAsciiCode)
{
	return IsNumeralChar(CharAsciiCode, 0, 9) || IsAlphabeticChar(CharAsciiCode, 'a', 'f') || IsAlphabeticChar(CharAsciiCode, 'A', 'F');
}

bool CheckValidityForNumberingSystems(char Digit, enNumberingSystem NumberingSystem)
{
	int CharAsciiCode = int(Digit);

	switch (NumberingSystem)
	{
	case enNumberingSystem::Binary:
		return IsNumeralChar(CharAsciiCode, 0, 1);
	case enNumberingSystem::Octal:
		return IsNumeralChar(CharAsciiCode, 0, 7);
	case enNumberingSystem::Decimal:
		return IsNumeralChar(CharAsciiCode, 0, 9);
	case enNumberingSystem::Hexadecimal:
		return IsHexChar(CharAsciiCode);
	}
}

bool UserEnteredInvalidNumber(string TextualNumber, enNumberingSystem NumberingSystem)
{
	for (int i = 0; i < TextualNumber.length(); i++)
		if (!CheckValidityForNumberingSystems(TextualNumber[i], NumberingSystem))
			// for each digit, if it's NOT valid: return true (invalid digit found in user input).
			return true;

	return false; // otherwise, the number is valid (no need to ask again).
}

string ReadTextualNumber(enNumberingSystem NumberingSystem)
{
	string TextualNumber;

	do
	{
		cout << "Please enter the original number: ";
		cin >> TextualNumber;

	} while (UserEnteredInvalidNumber(TextualNumber, NumberingSystem));

	return TextualNumber;
}

enNumberingSystem ReadNumberingSystem(string TargetNumber)
{
	short NumberOfNumberingSystem;

	cout << endl;
	cout << "1- Binary\n";
	cout << "2- Octal\n";
	cout << "3- Decimal\n";
	cout << "4- Hexadecimal\n";
	cout << endl;

	do
	{
		cout << "Please enter the " << TargetNumber << " number's system (1-4): ";
		cin >> NumberOfNumberingSystem;

	} while (NumberOfNumberingSystem < 1 || NumberOfNumberingSystem > 4);

	return (enNumberingSystem)NumberOfNumberingSystem;
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
	case enNumberingSystem::Hexadecimal:
		return 16;
	}
}

void ReadOriginalNumberInfo(stNumber& OriginalNumber)
{
	OriginalNumber.NumberingSystem = ReadNumberingSystem("original");
	OriginalNumber.Base = GetNumberingSystemBase(OriginalNumber.NumberingSystem);
	OriginalNumber.TextualNumber = ReadTextualNumber(OriginalNumber.NumberingSystem);
}

void FillNumber(stNumber& ConvertedNumber, string TextualNumber, enNumberingSystem NumberingSystem)
{
	ConvertedNumber.TextualNumber = TextualNumber;
	ConvertedNumber.NumberingSystem = NumberingSystem;
	ConvertedNumber.Base = GetNumberingSystemBase(ConvertedNumber.NumberingSystem);
}

char GetCapitalLetter(char Letter)
{
	if (int(Letter) >= 97) // indicates it is a small letter.
		return char(int(Letter) - 32); // shifting from small to capital.
	else
		return Letter; // if not >= 97 then it is capital already.
}

short HexToDecimal(char TextualDigit)
{
	int CharAsciiCode = int(GetCapitalLetter(TextualDigit));

	if (IsAlphabeticChar(CharAsciiCode, 'A', 'F'))
	{
		return CharAsciiCode - 65 + 10; // As 'A' starts from 65 -> 10. 'D' is 68 -> 13.
	}
	else // means it is a numeral
	{
		return CharAsciiCode - 48; // As '0' starts from 48 -> 0. 5 is 53 -> 5.
	}
}

short GetLastDigit(string TextualNumber, enNumberingSystem NumberingSystem)
{
	if (NumberingSystem == enNumberingSystem::Hexadecimal)
		return HexToDecimal(TextualNumber[TextualNumber.length() - 1]);

	else
	{
		long long Temp = stoll(TextualNumber);
		return Temp % 10;
	}
}

void RemoveLastDigit(string& TextualNumber)
{
	string Temp = "";

	for (int i = 0; i < TextualNumber.length() - 1; i++)
		Temp += TextualNumber[i];

	TextualNumber = Temp;
}

stNumber ConvertToDecimal(stNumber OriginalNumber)
{	
	if (OriginalNumber.NumberingSystem == enNumberingSystem::Decimal)
		return OriginalNumber;
	else 
	{ 
		long long Number = 0;
		short LastDigit;
		short Counter = 0;

		while (OriginalNumber.TextualNumber != "")
		{
			LastDigit = GetLastDigit(OriginalNumber.TextualNumber, OriginalNumber.NumberingSystem);
			Number += pow(OriginalNumber.Base, Counter) * LastDigit;

			RemoveLastDigit(OriginalNumber.TextualNumber);

			Counter++;
		}

		stNumber ConvertedNumber;
		FillNumber(ConvertedNumber, to_string(Number), enNumberingSystem::Decimal);
		
		return ConvertedNumber;
	}
}

string GetReversedText(string Text)
{
	string ReveredText = "";

	for (int i = Text.length() - 1; i >= 0; i--)
		ReveredText += Text[i];

	return ReveredText;
}

string ToHexDigit(short Number)
{
	string HexadecimalDigitsArray[16] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F"};
	return HexadecimalDigitsArray[Number];
}

stNumber ConvertDecimalToBaseN(stNumber DecimalNumber, enNumberingSystem ConvertToWhichSystem)
{
	string ConvertedTextualNumber = "";
	short Base = GetNumberingSystemBase(ConvertToWhichSystem);
	long long Temp = stoll(DecimalNumber.TextualNumber);

	while (Temp > 0) 
	{
		ConvertedTextualNumber += ToHexDigit(Temp % Base);
		Temp /= Base;

		// Yes, it might not be a hex number anyway, but it'll also work properly.
		// i'm just trying to make the code reusable.
	}

	ConvertedTextualNumber = GetReversedText(ConvertedTextualNumber);

	stNumber ConvertedNumber;
	FillNumber(ConvertedNumber, ConvertedTextualNumber, ConvertToWhichSystem);

	return ConvertedNumber;
}

stNumber ConvertToBaseN(stNumber OriginalNumber, enNumberingSystem ConvertToWhichSystem)
{
	short ConvertToWhichBase = GetNumberingSystemBase(ConvertToWhichSystem);

	if (ConvertToWhichBase == 10)
		return ConvertToDecimal(OriginalNumber);
	else
		return ConvertDecimalToBaseN(OriginalNumber, ConvertToWhichSystem);
}

string GetConvertedTextualNumber(stNumber OriginalNumber, enNumberingSystem ConvertToWhichSystem)
{
	// This function converts numbers by converting to decimal firstly,
	// then, convert to whatever system was selected.

	if (OriginalNumber.NumberingSystem == ConvertToWhichSystem)
		return OriginalNumber.TextualNumber;

	else 
	{    
		stNumber ConvertedNumber;

		ConvertedNumber = ConvertToBaseN(OriginalNumber, enNumberingSystem::Decimal);
		ConvertedNumber = ConvertToBaseN(ConvertedNumber, ConvertToWhichSystem);

		return ConvertedNumber.TextualNumber;
	}

	// i made the ELSE just to make it easy to read although
	// it can function without it.

}

void FillConvertedNumberInfo(stNumber OriginalNumber, stNumber& ConvertedNumber)
{
	ConvertedNumber.NumberingSystem = ReadNumberingSystem("converted");
	ConvertedNumber.Base = GetNumberingSystemBase(ConvertedNumber.NumberingSystem);
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