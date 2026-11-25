#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void PrintFileContent(string FileName)
{
	fstream File;

	File.open(FileName, ios::in);

	if (File.is_open())
	{
		string Line;

		while (getline(File, Line))
		{
			cout << Line << endl;
		}

		File.close();
	}
}

void LoadFileContentToVector(string FileName, vector<string>& vFileLinesContent)
{
	fstream File;

	File.open(FileName, ios::in);

	if (File.is_open())
	{
		string Line;

		while (getline(File, Line))
		{
			vFileLinesContent.push_back(Line);
		}

		File.close();
	}
}

void UpdateVectorContent(vector<string>& Vector, string TargetString, string NewString)
{
	for (string& Element : Vector)
	{
		if (Element == TargetString)
			Element = NewString;
	}
}

void SaveVectorToFile(vector<string>& vFileLinesContent, string FileName)
{
	fstream File;

	File.open(FileName, ios::out);

	if (File.is_open())
	{
		for (string& Line : vFileLinesContent)
		{
			File << Line << endl;
		}

		File.close();
	}
}

void UpdateFileContent(string FileName, string TargetString, string NewString)
{
	vector<string> vFileLinesContent;

	LoadFileContentToVector(FileName, vFileLinesContent);
	UpdateVectorContent(vFileLinesContent, TargetString, NewString);
	SaveVectorToFile(vFileLinesContent, FileName);
}

int main()
{
	cout << "Original:\n\n";
	PrintFileContent("MyFile.txt");

	UpdateFileContent("MyFile.txt", "Ali", "Omar");

	cout << "\n\nUpdated:\n";
	PrintFileContent("MyFile.txt");

	return 0;
}