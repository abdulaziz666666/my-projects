#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void LoadFileToVector(string FileName, vector<string>& vFileLinesContent)
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

void ClearTargetDataFromVector(vector<string>& Vector, string TargetString)
{
	for (string& Text : Vector)
	{
		if (Text == TargetString)
			Text.clear();
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
			// Dr. Mohammed made it ignores the empty strings, while i didn't.
			if (Line != "") // ensure its not empty, then write it.
				File << Line << endl;
		}

		File.close();
	}
}

void RemoveDataFromFile(string FileName, string TargetString)
{
	vector<string> vFileLinesContent;

	LoadFileToVector(FileName, vFileLinesContent);
	ClearTargetDataFromVector(vFileLinesContent, TargetString);
	SaveVectorToFile(vFileLinesContent, FileName);
}

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

int main()
{
	cout << "Before Deletion:\n";
	PrintFileContent("MyFile.txt");

	cout << "\n\nAfter Deletion:\n";
	RemoveDataFromFile("MyFile.txt", "Ali");
	PrintFileContent("MyFile.txt");

	return 0;
}