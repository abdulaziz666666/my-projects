#include <iostream>
#include <cmath>
using namespace std;

int GetSquareOf(float Num)
{
	const unsigned int Squared = round(pow(Num, 2));
	return Squared;
}

int GetCubeOf(float Num)
{
	const int Cubed = round(pow(Num, 3)); // the result might be negative.
	return Cubed;
}

int GetQuadrupleOf(float Num)
{
	const unsigned int Quadrupled = round(pow(Num, 4));
	return Quadrupled;
}

int main()
{
	float Num;

	cout << "Please enter any number: ";
	cin >> Num;

	//The past way
	//const float Squared = Num * Num;
	//const float Cubed = Squared * Num;
	//const float Quadrupled = Squared * Squared;
	//const unsigned int Squared = round(pow(Num, 2));
	//const int Cubed = round(pow(Num, 3)); // the result might be negative.
	//const unsigned int Quadrupled = round(pow(Num, 4));

	cout << GetSquareOf(Num) << endl << GetCubeOf(Num) << endl << GetQuadrupleOf(Num) << endl;

	return 0;
}