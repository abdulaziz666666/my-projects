#include <iostream>
using namespace std;

void PrintCapitalAlphabet()
{	
	for (int i = 65; i <= 90; i++) 
	{
		cout << char(i) << endl;
	}
}

void PrintSmallAlphabet()
{	
	//for (int i = 97; i <= 122; i++) 
	//{
	//	cout << char(i) << endl;
	//}
	int i = 97;

	while (i <= 122)
	{
		cout << char(i) << endl;
		i++;
	}
}

int main()
{
	PrintSmallAlphabet();
	return 0;
}