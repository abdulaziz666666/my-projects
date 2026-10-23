#include <iostream>
using namespace std;

struct stPerson
{
	string FirstName;
	string LastName;
	unsigned short Age;
	string Phone;
};

int main()
{
	stPerson People[2];

	People[0].FirstName = "Ahmed";
	People[0].LastName = "Al-Obaidah";
	People[0].Age = 20;
	People[0].Phone = "0251765123";

	People[1].FirstName = "Al-Waleed";
	People[1].LastName = "Al-Hamad";
	People[1].Age = 51;
	People[1].Phone = "0539874269";

	cout << People[1].FirstName << endl;

	return 0;
}