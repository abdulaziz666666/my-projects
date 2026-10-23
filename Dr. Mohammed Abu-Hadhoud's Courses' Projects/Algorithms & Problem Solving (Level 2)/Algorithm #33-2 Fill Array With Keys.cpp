#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

enum enCharType { SmallLetter, CapitalLetter, SpecialCharachter, Digit };

// that way it is much more organized.
struct stKey
{
	short NumberOfParts;
	short PartLength;
	enCharType CharType;
	char Separator;
	string KeyString;
};

struct stArray
{
	string Elements[100];
	int Length;
};

int ReadPositiveNumber(string Message)
{
	int Num;

	do
	{
		cout << Message << " (Should be positive): ";
		cin >> Num;
	} while (Num <= 0);

	return Num;
}

int RandomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

stKey ReadKeyInfo()
{
	stKey Key;

	Key.NumberOfParts = ReadPositiveNumber("How many part in each key? (Ex: ABC-EFG is 2 parts)");
	Key.PartLength = ReadPositiveNumber("How many charachters for each part?");
	Key.CharType = enCharType::CapitalLetter;
	Key.Separator = '-';

	return Key;
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

// As a general function, i must not put stKey parameter here; i might use it somewhere
// else where i wouldn't deal with keys at all.
string GenerateWord(short length, enCharType CharType)
{
	string Word = "";

	for (int j = 1; j <= length; j++)
	{
		Word += GetRandomCharachter(CharType);
	}

	return Word;
}

// a general function that can be used with any application, not only with keys.
// thats why i didn't put stKey as a parameter
void AddSeparatorIfNeeded(string& Str, char Separator, int CurrentIndex, int NumberOfParts)
{
	// AKA if it is the last word meaning: no need to put "Separator".
	if (CurrentIndex < NumberOfParts)
		Str += Separator;
}

// I converted the function to a procedure; to build
// the key through the given measurements saved in it 
// instead of a function intializes another key and 
// copy the given key's data, which is useless.
void GenerateKey(stKey &Key)
{
	Key.KeyString = ""; // it should be intialized first.

	for (int i = 1; i <= Key.NumberOfParts; i++)
	{
		Key.KeyString += GenerateWord(Key.PartLength, Key.CharType);
		AddSeparatorIfNeeded(Key.KeyString, Key.Separator, i, Key.NumberOfParts);
	}
}

void PrintArray(stArray Array)
{
	for (int i = 0; i < Array.Length; i++)
		cout << Array.Elements[i] << "\t";

	cout << endl;
}
void PrintStringArray(stArray Array)
{
	for (int i = 0; i < Array.Length; i++)
	{
		cout << "Array [" << i + 1 << "]:\t";
		cout << Array.Elements[i] << endl;
	}

	cout << endl;
}

void FillArrayWithKeys(stArray& Array, stKey& Key)
{
	for (int i = 0; i < Array.Length; i++)
	{
		GenerateKey(Key);
		Array.Elements[i] = Key.KeyString;
	}
}

int main()
{
	srand((unsigned)time(NULL));

	stArray Array;
	Array.Length = ReadPositiveNumber("Please enter the number of keys to generate");

	stKey Key = ReadKeyInfo();
	
	FillArrayWithKeys(Array, Key);

	cout << "\nArray Elements:\n\n";
	PrintStringArray(Array);

	return 0;
}