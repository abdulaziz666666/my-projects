#include <iostream>
#include <cstdlib>
using namespace std;

//enum enValueType {SmallLetter, CapitalLetter, SpecialCharachter, Digit};
enum enCharType {SmallLetter, CapitalLetter, SpecialCharachter, Digit};

int RandomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

//char RandomValue(enValueType Type)
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
		//return char(RandomNumber(0, 9));
		return char(RandomNumber(48, 57));
	}
}

int main()
{
	srand((unsigned)time(NULL));

	cout << GetRandomCharachter(enCharType::CapitalLetter) << endl;
	cout << GetRandomCharachter(enCharType::SmallLetter) << endl;
	cout << GetRandomCharachter(enCharType::SpecialCharachter) << endl;
	//cout << int(GetRandomCharachter(enValueType::Digit)) << endl;
	cout << GetRandomCharachter(enCharType::Digit) << endl;

	return 0;
}