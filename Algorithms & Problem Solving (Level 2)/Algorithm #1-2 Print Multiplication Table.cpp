#include <iostream>
using namespace std;

//void PrintTitle(int NumberOfColumns)
void PrintTitle()
{
	cout << "\n\n"; // a Top-Margin

	for (int i = 1; i <= 4; i++)
		cout << "\t"; // justify the title to the center using tabs.

	cout << "Multiplication Table From 1 to 10";

	cout << "\n\n"; // a Bottom-Margin
}

//void PrintNumbersToN(int N)
void PrintNumbersTo10()
{
	cout << "\t"; // justifying the numbers to the center.

	for (int Counter = 1; Counter <= 10; Counter++)
	{
		cout << "\t" << Counter; 
	}

	cout << endl;
}

//void PrintHorizontalLine(int NumberOfColumns)
void PrintHorizontalLine()
{
	for (int i = 1; i <= 95; i++)
	{
		cout << "-";
	}
	cout << endl;
}

//void PrintNumberRow(int RowNumber, int NumberOfColumns)
void PrintNumberRow(int Number)
{
	cout << "   " << Number << "\t|";

	for (int Counter = 1; Counter <= 10; Counter++)
	{
		cout << "\t" << Counter * Number;
	}

	cout << endl;
}

//void PrintAllMultiplicationRows(int NumberOfRows, int NumberOfColumns)
void PrintTable()
{
	for (int i = 1; i <= 10; i++)
	{
		PrintNumberRow(i);
	}
}

//void PrintMultiplicationTable(int NumberOfRows, int NumberOfColumns)
void PrintMultiplicationTable()
{
	//PrintTitle(NumberOfColumns);
	//PrintNumbersToN(NumberOfColumns);
	//PrintHorizontalLine(NumberOfColumns);
	//PrintAllMultiplicationRows(NumberOfRows, NumberOfColumns);
	PrintTitle();
	PrintNumbersTo10();
	PrintHorizontalLine();
	PrintTable();
}

int main()
{
	// والله من أول محاولة ضبطته.. كانت المشكلة بس في السطور ناقصة أو شي زي كذا
	// Done By the first try! Only with an issue that some lines\spaces need to be there.
/*	this is how the first try was:
	

										Multiplication Table From 1 to 10
		1       2       3       4       5       6       7       8       9       10
______________________________________________________________________
1       |       1       2       3       4       5       6       7       8       9       10
2       |       2       4       6       8       10      12      14      16      18      20
3       |       3       6       9       12      15      18      21      24      27      30
4       |       4       8       12      16      20      24      28      32      36      40
5       |       5       10      15      20      25      30      35      40      45      50
6       |       6       12      18      24      30      36      42      48      54      60
7       |       7       14      21      28      35      42      49      56      63      70
8       |       8       16      24      32      40      48      56      64      72      80
9       |       9       18      27      36      45      54      63      72      81      90
10      |       10      20      30      40      50      60      70      80      90      100
	
*/
	// Simply Done by Divide & Conquer الحمد لله.
	PrintMultiplicationTable();

	//PrintMultiplicationTable(12, 4); // a try to make it dynamic but wasn't good enough.

	return 0;
}