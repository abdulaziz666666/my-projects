#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	fstream MyFile;

	MyFile.open("MyFile.txt", ios::out); // out = write mode

	if (MyFile.is_open())
	{
		MyFile << "Writing the first line..\n";
		MyFile << "Then the second line..\n";
		MyFile << "Also a third line..\n";
		MyFile << "And finally finishing.\n";

		/*
		MyFile << "b6tna b6t\n";
		MyFile << "b6n\n";
		MyFile << "b6tkm\n";
		MyFile << "at7da b6tkm tb6 b6n b6tna mthl ma b6tna b6t b6n b6tkm\n";
		*/

		MyFile.close();
	}

	return 0;
}