#include <iostream>
#include <string>
using namespace std;

void Read2Numbers(int& Num1, int& Num2)
{
	cout << "Please enter the first number: ";
	cin >> Num1;

	cout << "Please enter the second number: ";
	cin >> Num2;
}

// It is my configuration to make that function returns a string
// instead of an integer; as it clarifies which is which.

//string GetMax(int Num1, int Num2)
string MaxOf2Numbers(int Num1, int Num2)
{
	if (Num1 > Num2)
		return to_string(Num1) + " (first number)";
	else
		return to_string(Num2) + " (second number)";
}

// although i think my way is better, i will apply dr. Mohammed's way

//void PrintMax(int Num1, int Num2) 
void PrintMax(string WhichIsMax)
{
	//cout << "\nThe Max of " << Num1 << " and " << Num2;
	//cout << " is " << MaxOf2Numbers(Num1, Num2) << endl;
	cout << "\nthe max number is " << WhichIsMax << endl;
}

int main()
{
	int Num1, Num2;

	Read2Numbers(Num1, Num2);
	PrintMax(MaxOf2Numbers(Num1, Num2));
	
	// this is much better; as it only needs the two numbers and it will bring the results.
	//PrintMax(Num1, Num2); 

	return 0;
}