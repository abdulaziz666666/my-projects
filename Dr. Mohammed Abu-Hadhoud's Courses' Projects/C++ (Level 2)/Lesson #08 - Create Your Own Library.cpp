#include <iostream>
#include "MyLib.h";
#include "MyInputLib.h";
#include "MyValidationLib.h";

using namespace std;
//using namespace MyLib;
//using namespace MyInputLib;

int main()
{

	MyLib::Test();
	cout << MyLib::Sum2Numbers(10, 20) << endl;
	//cout << Sum2Numbers(10, 20) << endl;
	string Name = MyInputLib::ReadName("your name", true);

	cout << Name << endl;

	//int Number = ReadNumber();
	int Number = MyInputLib::ReadNumber();
	cout << MyValidationLib::IsNumberInRange(Number, 1, 10) << endl;

	return 0;
}