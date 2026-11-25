#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

//void SaveFileContentIntoVector(vector<string>& vFileLinesContent, string FileName)
void LoadDataFromFileToVector(vector<string>& vFileLinesContent, string FileName)
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

void PrintVectorContent(vector<string>& Vector)
{
	for (string& Element : Vector)
	{
		cout << Element << endl;
	}
}

int main()
{
	vector<string> vFileLinesContent;

	LoadDataFromFileToVector(vFileLinesContent, "MyFile.txt");
	PrintVectorContent(vFileLinesContent);

	return 0;
}