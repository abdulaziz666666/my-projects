#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void SaveVectorToFile(vector<string>& vFileLinesContent, string FileName)
{
	fstream File;

	File.open(FileName, ios::out);

	if (File.is_open())
	{
		for (string& Line : vFileLinesContent)
		{
			// Dr. Mohammed made it ignores the empty strings, while i didn't.
			if (Line != "") // ensure its not empty, then write it.
				File << Line << endl;
		}

		File.close();
	}
}


int main()
{
	vector<string> vFileLinesContent = {"Ahmed", "Khalid", "Ali", "Yousef"};

	SaveVectorToFile(vFileLinesContent, "MyFile.txt");

	return 0;
}