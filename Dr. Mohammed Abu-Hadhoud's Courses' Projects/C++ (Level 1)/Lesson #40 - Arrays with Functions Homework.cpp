#include <iostream>
using namespace std;

struct stContribution
{
	float CollectedMoney;
	float Target;
	float Contributions[3];
};

void ReadMoneyAmount(stContribution &Contribution)
{
	cout << "Please enter the collected money amount:\n";
	cin >> Contribution.CollectedMoney;

	cout << endl;

	cout << "Please enter the target:\n";
	cin >> Contribution.Target;

	cout << endl;

	cout << "Please enter the first contribution:\n";
	cin >> Contribution.Contributions[0];

	cout << endl;

	cout << "Please enter the second contribution:\n";
	cin >> Contribution.Contributions[1];

	cout << endl;

	cout << "Please enter the third contribution:\n";
	cin >> Contribution.Contributions[2];
}

float GetExcessMoney(stContribution Contribution)
{
	return Contribution.CollectedMoney - Contribution.Target;
}

void PrintContributionResult(stContribution Contribution)
{
	//if GetExcessMoney(CollectedMoney, Target)
	//{

	//}

	cout << "\n******************************************\n\n";

	float ExcessMoney = GetExcessMoney(Contribution);

	cout << "The Net Money is " << ExcessMoney << endl;
	cout << "Everyone Can Take " << ExcessMoney / 3 << " Equally" << endl;
}

int main()
{
	stContribution Contribution;

	ReadMoneyAmount(Contribution);
	PrintContributionResult(Contribution);

	return 0;
}