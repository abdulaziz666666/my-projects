#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct stArray
{
	int Elements[100];
	int Length;
};

int ReadPositiveNumber(string Message)
{
	int Num;

	do
	{
		cout << Message << " (Should be positive): ";
		cin >> Num;
	} while (Num <= 0);

	return Num;
}

int RandomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

//void FillArray(stArray& Array)
void FillArrayWith1ToN(stArray& Array)
{
	for (int i = 0; i < Array.Length; i++)
		Array.Elements[i] = i + 1;
}

void PrintArray(stArray Array)
{
	cout << endl;

	for (int i = 0; i < Array.Length; i++)
	{
		cout << Array.Elements[i] << "\t";
	}

	cout << endl;
}
// before that lesson, i thought i can not change array elements 
// but through pointing to them by their index. ex: arr[i] = 5.
// Now, i knew i can do it even through their values (NOT literals) ex: arr[i] as parameter.
// by calling them by reference, which is strange from my way of
// perspective. A new thing has been learned today!
void SwapElements1(stArray &Array, int Index1, int Index2)
{
	int Temp = Array.Elements[Index1];
	Array.Elements[Index1] = Array.Elements[Index2];
	Array.Elements[Index2] = Temp;
}

void SwapElements2(int& A, int& B)
{
	int Temp = A;
	A = B;
	B = Temp;
}

// My way.
void ShuffleArray1(stArray& Array)
{
	int RandomIndex;

	for (int i = 0; i < Array.Length; i++)
	{
		while (true) // continues until indexes are different.
		{
			RandomIndex = RandomNumber(0, Array.Length - 1);

			if (i != RandomIndex) 
			{
				SwapElements1(Array, i, RandomIndex);
				break; 
			}
		}
	}
}

// Dr.Mohammed's way, which is much much better.. Allahuma Barik.
// i can make my function just like his function, though.
void ShuffleArray2(stArray& Array)
{
	for (int i = 1; i <= Array.Length; i++)
		SwapElements2(Array.Elements[RandomNumber(0, Array.Length - 1)],
					  Array.Elements[RandomNumber(0, Array.Length - 1)]);
}

// this is how my function will be if i don't check if the two indexes
// were different. I thought it is not guaranteed it will be randomized
// very well, but the opposite was proven.
void ShuffleArray3(stArray& Array)
{
	int RandomIndex;
	int ElementA, ElementB;

	for (int i = 0; i < Array.Length; i++)
	{
		RandomIndex = RandomNumber(0, Array.Length - 1);
		// Not through passing them as literals.
		//ElementA = Array.Elements[i];
		//ElementB = Array.Elements[RandomIndex];
		SwapElements2(Array.Elements[i], Array.Elements[RandomIndex]); // that way is correct.
	}
}

int main()
{
	srand((unsigned)time(NULL));

	stArray Array;

	Array.Length = ReadPositiveNumber("Please enter the length of the array");
	FillArrayWith1ToN(Array);
	
	cout << "\nArray Elements Before The Shuffle: ";
	PrintArray(Array);

	ShuffleArray3(Array);

	cout << "\nArray Elements After The Shuffle: ";
	PrintArray(Array);

	return 0;
}