#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

enum enCharType {SmallLetter, CapitalLetter, SpecialCharachter, Digit};

int RandomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

char GetRandomCharachter(enCharType CharType)
{
	switch (CharType)
	{
	case enCharType::SmallLetter:
		return char(RandomNumber(97, 122));
	case enCharType::CapitalLetter:
		return char(RandomNumber(65, 90));
	case enCharType::SpecialCharachter:
		return char(RandomNumber(33, 47));
	case enCharType::Digit:
		return char(RandomNumber(48, 57));
	}
}

int ReadPositiveNumber(string Message)
{
	int Num;

	do
	{
		cout << Message << " (Should be positive):\n";
		cin >> Num;
	} while (Num <= 0);

	return Num;
}

string GenerateWord(short length, enCharType CharType)
{
	string Word = "";

	for (int j = 1; j <= length; j++)
	{
		Word += GetRandomCharachter(CharType);
	}

	return Word;
}

void AddSeparatorIfNeeded(string &Str, char Separator, int CurrentIndex, int NumberOfParts)
{
	// AKA if it is the last word meaning: no need to put "Separator".
	if (CurrentIndex < NumberOfParts)
		Str += Separator;
}

string GenerateKey(short NumberOfParts, short PartLength, enCharType CharType)
{
	string Key = "";

	for (int i = 1; i <= NumberOfParts; i++)
	{
		Key += GenerateWord(PartLength, CharType);
		AddSeparatorIfNeeded(Key, '-', i, NumberOfParts);
	}

	return Key;
}

void PrintKeys(short NumberOfKeys, short KeyPartsNumber, short KeyPartsLength, enCharType CharType)
{
	cout << endl;

	for (int i = 1; i <= NumberOfKeys; i++)
	{
		cout << "Key [" << i << "]:\t";
		cout << GenerateKey(KeyPartsNumber, KeyPartsLength, CharType) << endl;
	}
}

int main()
{
	srand((unsigned)time(NULL));

	short NumberOfKeys = ReadPositiveNumber("Please enter the number of keys to generate");
	short KeyPartsNumber = ReadPositiveNumber("How many part in each key? (Ex: ABC-EFG is 2 parts)");
	short KeyPartsLength = ReadPositiveNumber("How many charachters for each Word?");

	PrintKeys(NumberOfKeys, KeyPartsNumber, KeyPartsLength, enCharType::CapitalLetter);

	return 0;
}