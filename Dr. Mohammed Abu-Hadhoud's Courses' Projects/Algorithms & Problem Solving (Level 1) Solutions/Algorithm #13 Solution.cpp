#include <iostream>
#include <string>
using namespace std;

void Read3Numbers(int& A, int& B, int& C)
{
	cout << "Please enter the first number: ";
	cin >> A;

	cout << "Please enter the second number: ";
	cin >> B;

	cout << "Please enter the third number: ";
	cin >> C;
}

string MaxOf3Numbers(int A, int B, int C)
{
	if (A > B)
	{
		if (A > C)
			return to_string(A) + " (first number)";
		else
			return to_string(C) + " (third number)";
	}
	else
	{
		if (B > C)
			return to_string(B) + " (second number)";
		else
			return to_string(C) + " (third number)";
	}

	// there is a tricky way where i can leave the case of "C is Max"
	// and return it at the end of the function where it should be
	// the only true case if the others aren't.

	/*
	Just Like That:

	if (A > B)
	{
		if (A > C)
			return to_string(A) + " (first number)";
	}
	else
	{
		if (B > C)
			return to_string(B) + " (second number)";
	}

	return to_string(C) + " (third number)";
	*/
}

void PrintMax(int A, int B, int C) 
{
	cout << "\nThe Max of " << A << ", " << B << ", and " << C;
	cout << " is " << MaxOf3Numbers(A, B, C) << endl;
}

int main()
{
	int A, B, C;

	Read3Numbers(A, B, C);
	PrintMax(A, B, C); 

	return 0;
}