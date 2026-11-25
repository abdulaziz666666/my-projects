#include <iostream>
using namespace std;

int main()
{
	int* ptrInt;
	float *ptrFloat;

	ptrInt = new int;
	ptrFloat = new float;

	*ptrInt = 12;
	*ptrFloat = 9.244;

	cout << *ptrInt << endl;
	cout << *ptrFloat << endl;

	delete ptrInt;
	delete ptrFloat;

	return 0;
}