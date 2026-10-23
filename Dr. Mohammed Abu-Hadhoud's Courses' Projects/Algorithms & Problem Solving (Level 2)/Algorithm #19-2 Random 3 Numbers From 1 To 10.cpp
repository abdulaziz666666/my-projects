#include <iostream>
#include <cstdlib>
using namespace std;

int RandomNumber(int From, int To)
{
	// rand() generates a random number in range of positive
	// integers as we instructed in srand().
	// here we took the remainder of the random number divided
	// by "To" to ensure the number won't excess the range.
	// After that, we added "From" to ensure that the number
	// would be "From" at least.
	// Ex: 
	//		rand()  = 14
	//		From    = 3
	//		To      = 15
	//		Randnum = 14 % (15 - 3 + 1) + 3 -> 14 + 3 -> 3.
	int RandNum = rand() % (To - From + 1) + From; // i was wrong by thinking it is working that way.
	//int RandNum = rand() % To + From; // i was wrong by thinking it'll work that way.

	return RandNum;
}

int main()
{	
	srand((unsigned)time(NULL));

	cout << RandomNumber(1, 10) << endl;
	cout << RandomNumber(7, 12) << endl;
	cout << RandomNumber(25, 35) << endl;
	return 0;
}