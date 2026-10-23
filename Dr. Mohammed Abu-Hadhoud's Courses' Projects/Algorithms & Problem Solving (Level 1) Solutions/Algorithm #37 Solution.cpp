#include <iostream>
#include <string>
using namespace std;

float ReadNumber(string Message)
{
	float Num;

	cout << Message;
	cin >> Num;

	return Num;
}

string MakeMessageWithCounterAndFlag(float Flag, int Counter)
{
	return "Please enter a number (" + to_string(Flag) + " to stop) (current: " + to_string(Counter) + "): ";
}

float SumUntilFlag(float Flag)
{
	float Num = 0, Sum = 0;
	int Counter = 1;
	string Message;

	while (true)
	{
		Message = MakeMessageWithCounterAndFlag(Flag, Counter);
		Num = ReadNumber(Message);

		if (Num == Flag)
			break;

		Sum += Num;
		Counter++;
	}

	return Sum;
}

int main()
{
	float Sum = SumUntilFlag(-99);

	cout << "\nSum = " << Sum << endl;

	return 0;
}