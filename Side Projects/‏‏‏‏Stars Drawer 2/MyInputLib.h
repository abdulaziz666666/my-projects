#pragma once

#include <iostream>
#include <string>

#include "MyValidationLib.h";
#include "MyEnums.h"

using namespace std;

namespace MyInputLib
{
	int ReadNumber()
	{
		int Num;

		cout << "Please enter a number: ";
		cin >> Num;

		while (cin.fail())
		{
			cin.clear();
			//cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "Invalid number, please enter a valid one: " << endl;
			cin >> Num;
		}

		return Num;
	}

	int ReadPositiveNumber(string Message)
	{
		int Num;

		cout << Message << " (Should be positive): ";
		cin >> Num;

		while (Num <= 0 || cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "Invalid number, please enter a valid one: " << endl;
			cin >> Num;
		}

		return Num;
	}

	int ReadNumberInRange(int From, int To)
	{
		int Num;

		cout << "Please enter a number from " << From << " to " << To << ": ";
		cin >> Num;

		while (cin.fail() || !MyValidationLib::IsNumberInRange(Num, From, To))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "Invalid number, please enter a valid one: " << endl;
			cin >> Num;
		}

		return Num;
	}

	void ReadArray(int Array[100], int ArrayLength)
	{
		for (int i = 0; i < ArrayLength; i++)
		{
			cout << "Please enter element [" << i + 1 << "]: ";
			cin >> Array[i];
		}
	}

	string ReadName(string NameOfWhat, bool IsFirstInput)
	{
		string Name;

		cout << "Please enter " << NameOfWhat << ": ";

		if (!IsFirstInput)
			cin.ignore(1, '\n');

		getline(cin, Name);

		return Name;
	}
}