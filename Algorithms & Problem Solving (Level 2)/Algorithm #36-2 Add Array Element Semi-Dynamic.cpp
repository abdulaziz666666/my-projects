#include <iostream>
using namespace std;

// only for purpose of learning, i left the structure of array (stArray).
// Otherwise, i will continue using it as it is much convenient to deal with.

void PrintArray(int Array[100], int ArrayLength)
{
	for (int i = 0; i < ArrayLength; i++)
	{
		cout << Array[i] << " ";
	}

	cout << endl;
}

int ReadNumber()
{
	int Num;

	cout << "\nPlease enter a number: ";
	cin >> Num;

	return Num;
}

// my way
void ReadArray(int Array[100], int& ArrayLength)
{
	int Num;
	ArrayLength = 0;
	bool WantToContinue;

	do
	{
		Num = ReadNumber();

		Array[ArrayLength++] = Num; // assign then increase.

		cout << "\nDo you want to add more numbers?\n";
		cout << "(1) Yes\n(0) No\nYour Choice ? : ";
		cin >> WantToContinue;
		cout << endl;

	} while (WantToContinue);
}

// dr.mohammed's way
// I changed some things, though.
void AddArrayElement(int Element, int Array[100], int& ArrayLength)
{
	Array[ArrayLength++] = Element;
}

void AskContinueOrNot(bool& WantToContinue)
{
	cout << "\nDo you want to continue implementing elements?\n";
	cout << "(1) Yes\n(2) No\nYour Choice?: ";
	cin >> WantToContinue;
}

//void InputUserNumbersInArray(int Array[100], int& ArrayLength) // dr's name.
void FillArrayWithUserInput(int Array[100], int& ArrayLength) // my name. i feel "ReadArray" is better anyway.
{
	//bool AddMore; 
	bool WantToContinue; // i prefer that.

	do
	{
		AddArrayElement(ReadNumber(), Array, ArrayLength);
		AskContinueOrNot(WantToContinue); // that is not from dr.mohammed. i thought it might be good.

	} while (WantToContinue);
}

int main()
{
	//int Array[100], ArrayLength;
	int Array[100], ArrayLength = 0;

	//ReadArray(Array, ArrayLength);
	FillArrayWithUserInput(Array, ArrayLength);

	cout << "\nArray Length: " << ArrayLength << endl;
	cout << "Array Elements: ";
	PrintArray(Array, ArrayLength);

	return 0;
}