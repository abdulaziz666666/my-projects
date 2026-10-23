#include <iostream>
using namespace std;

//int ReadNumber(string Message)
//{
//	int Num;
//
//	cout << Message << endl;
//	cin >> Num;
//
//	return Num;
//}

int ReadNumber()
{
	int Num;

	cout << "Please enter a number: ";
	cin >> Num;

	return Num;
}

int ReadPower()
{
	int Power;

	cout << "Please enter the power: ";
	cin >> Power;

	return Power;
}

//void PrintNumToPowerOfN(int Num, int Power)
int PowerOfM(int Num, int M)
{
	int PoweredResult = 1;

	// this loop multiply M times (power of 2: two times, etc)
	for (int Counter = 1; Counter <= M; Counter++)
		PoweredResult *= Num;
	
	return PoweredResult;
}

int main()
{
	//int Num = ReadNumber("Please enter a number:");
	//int Power = ReadNumber("Please enter the power:");

	//cout << Num << " ^ " << Power << " = " << PowerOfM(Num, Power);

	// if the function parameters are given through functions, 
	// they will be excuted from the right to the left.
	cout << PowerOfM(ReadNumber(), ReadPower()); 

	return 0;
}