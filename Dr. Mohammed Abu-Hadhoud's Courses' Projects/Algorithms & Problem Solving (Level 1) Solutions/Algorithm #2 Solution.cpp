#include <iostream>
#include <string>
using namespace std;

// My way
//string ReadName()
//{
//	string Name;
//	
//	cin >> Name;
//
//	return Name;
//}

// Dr. Mohammed's way
string ReadName()
{
	string Name;
	
	cout << "Please enter your name: ";
	getline(cin, Name);

	return Name;
}

void PrintName(string Name)
{
	cout << "\nYour Name is: " << Name << endl;
}

int main()
{
	//string Name = ReadName();
	PrintName(ReadName());
	return 0;
}