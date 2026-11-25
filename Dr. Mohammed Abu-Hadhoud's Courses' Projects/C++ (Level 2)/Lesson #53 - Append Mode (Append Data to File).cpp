#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	fstream MyFile;

	MyFile.open("MyFile.txt", ios::out | ios::app); // out if not exist OR append if exist.

	if (MyFile.is_open())
	{
		MyFile << 1 << endl;
		MyFile << 2 << endl;
		MyFile << 3 << endl;
		MyFile.close();
	}

	return 0;
}