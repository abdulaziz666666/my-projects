#include <iostream>
using namespace std;

void FillWithAlphabet(char Array[26])
{
	for (int i = 65; i <= 90; i++)
	{
		Array[i - 65] = char(i);
	}
}

int main()
{
	int Array[] = { 1, 2, 3, 4 };

	for (int Element : Array)
	{
		cout << Element << endl;
	}

	for (int Element : { 1, 2, 3, 4 })
	{
		cout << Element << endl;
	}

	cout << endl;

	char Alphabet[26];
	FillWithAlphabet(Alphabet);

	for (char Letter : Alphabet)
	{
		cout << Letter << endl;
	}

	return 0;
}