#include <iostream>
using namespace std;

struct stPerson
{
	string FirstName;
	string LastName;
	unsigned short Age;
	string Phone;
};

struct stPeople
{
	stPerson ListOfPeople[100];
	unsigned short NumberOfPeople;
};

void ReadPersonInfo(stPerson &Person)
{
	cout << "Please enter the following:\n\n";

	cout << "First Name: ";
	cin >> Person.FirstName;;

	cout << "Last Name: ";
	cin >> Person.LastName;

	cout << "Age: ";
	cin >> Person.Age;

	cout << "Phone: ";
	cin >> Person.Phone;

	cout << endl;
}

void PrintPersonInfo(stPerson Person)
{
	cout << "*******************************" << endl;

	cout << "First Name:\t" << Person.FirstName << endl;
	cout << "Last Name:\t" << Person.LastName << endl;
	cout << "Age:\t\t" << Person.Age << endl;
	cout << "Phone:\t\t" << Person.Phone << endl;

	cout << "*******************************" << endl;

	cout << endl;
}

void ReadPeopleInfo(stPeople &People)
{	
	cout << "How many people do yo want to enter? (Max: 100): ";
	cin >> People.NumberOfPeople;

	cout << endl;

	for (int i = 0; i < People.NumberOfPeople; i++)
	{
		cout << "Person [" << i + 1 << "]: " << endl;
		ReadPersonInfo(People.ListOfPeople[i]);
	}

	//ReadPersonInfo(People[0]);
	//ReadPersonInfo(People[1]);
}

void PrintPeopleInfo(stPeople People)
{
	for (int i = 0; i < People.NumberOfPeople; i++)
	{
		cout << "Person [" << i + 1 << "]: " << endl;
		PrintPersonInfo(People.ListOfPeople[i]);
	}
	//PrintPersonInfo(People[0]);
	//PrintPersonInfo(People[1]);
}

int main()
{
	stPeople People;

	ReadPeopleInfo(People);
	PrintPeopleInfo(People);

	return 0;
}