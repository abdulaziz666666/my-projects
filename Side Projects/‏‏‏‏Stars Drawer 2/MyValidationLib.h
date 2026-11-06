#pragma once

#include <iostream>
#include "MyEnums.h";
using namespace std;

namespace MyValidationLib
{
	bool IsNumeralDigit(int CharAsciiCode, int FromNumber, int ToNumber)
	{
		return (CharAsciiCode >= int(FromNumber + '0') && CharAsciiCode <= int(ToNumber + '0'));
	}

	bool IsAlphabeticDigit(int CharAsciiCode, char FromChar, char ToChar)
	{
		return (CharAsciiCode >= int(FromChar) && CharAsciiCode <= int(ToChar));
	}

	bool IsHexChar(int CharAsciiCode)
	{
		return IsNumeralDigit(CharAsciiCode, 0, 9) || IsAlphabeticDigit(CharAsciiCode, 'a', 'f') || IsAlphabeticDigit(CharAsciiCode, 'A', 'F');
	}

	bool IsNumberInRange(int Num, int From, int To)
	{
		return (Num >= From && Num <= To);
	}

	MyEnums::enNumberPrimary CheckPrime(int Num)
	{
		// excluding some cases to deal with odd numbers only.
		if (Num <= 1) // 1 or less
			return MyEnums::enNumberPrimary::NotPrime;

		else if (Num == 2) // the only even and prime number
			return MyEnums::enNumberPrimary::Prime;

		else if (Num % 2 == 0) // even but not 2
			return MyEnums::enNumberPrimary::NotPrime;

		// odd numbers left..
		for (int Counter = 3; Counter <= round(Num / 2); Counter += 2)
		{
			if (Num % Counter == 0)
				return MyEnums::enNumberPrimary::NotPrime;
		}

		return MyEnums::enNumberPrimary::Prime;
	}

	MyEnums::enNumberType CheckNumberType(int Num)
	{
		if (Num % 2 == 0)
			return MyEnums::enNumberType::Even;
		else
			return MyEnums::enNumberType::Odd;
	}
}