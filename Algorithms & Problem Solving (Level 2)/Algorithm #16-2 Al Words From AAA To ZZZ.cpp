#include <iostream>
using namespace std;

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

//void PrintAll3LetterWords()
void PrintWordsFromAAAToZZZ()
{
	cout << endl;
	for (int Letter1 = 65; Letter1 <= 90; Letter1++)
	{
		for (int Letter2 = 65; Letter2 <= 90; Letter2++)
		{
			for (int Letter3 = 65; Letter3 <= 90; Letter3++)
			{
				cout << char(Letter1);
				cout << char(Letter2);
				cout << char(Letter3);
				cout << "\n"; // filling the buffer
			}
			cout << endl; // emptying the buffer
		}
	}
}
// a similar example.. although it is not convenient but fun ;)
void PrintAll4DigitNumbers()
{
	for (int i = 0; i <= 9; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			for (int k = 0; k <= 9; k++)
			{
				for (int l = 0; l <= 9; l++)
					cout << i << j << k << l << "\n";
			}
		}
		cout << endl; // emptying the buffer.
	}
}

int main()
{
	//PrintAll3LetterWords();
	PrintWordsFromAAAToZZZ();
	//PrintAll4DigitNumbers();
	return 0;
}