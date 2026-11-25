#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector <int> vNumbers;

	vNumbers.push_back(1);
	vNumbers.push_back(2);
	vNumbers.push_back(3);
	vNumbers.push_back(4);
	vNumbers.push_back(5);

	cout << "Stack Size BEFORE popping: " << vNumbers.size() << endl;

	// To pop elements from vector's stack, we can say:
	//vNumbers.pop_back();
	//vNumbers.pop_back();
	//vNumbers.pop_back();
	//vNumbers.pop_back();
	//vNumbers.pop_back();

	// Also, we can say:
	//while (!vNumbers.empty())
	//{
	//	vNumbers.pop_back();
	//}

	// Furthermore, we can use empty() with if statement to lock 
	// for additional pop if vector stack was NOT empty.

	// Another way to check the vector stack is size():
	//while (vNumbers.size() > 0)
	//{
	//	vNumbers.pop_back();
	//}
	
	// Although the past ways work, this way is the best:
	vNumbers.clear();

	cout << "Stack Size AFTER popping: " << vNumbers.size() << endl;

	for (int& Number : vNumbers)
	{
		cout << Number << endl;
	}

	return 0;
}