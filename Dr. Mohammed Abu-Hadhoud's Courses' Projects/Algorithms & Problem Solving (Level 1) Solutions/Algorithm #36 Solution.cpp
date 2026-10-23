#include <iostream>
using namespace std;

enum enOperationType { Addition = '+', Subtraction = '-', Multiplication = '*', Division = '/' };

struct stArithmeticalOperation
{
	float Num1, Num2;
	enOperationType Type;
};

float ReadNumber(string Message)
{
	float Num;

	cout << Message << endl;
	cin >> Num;

	return Num;
}

enOperationType ReadOperationType()
{
	char TypeNumber;

	cout << "Please enter the operation (+ - * /): " << endl;
	cin >> TypeNumber;

	return (enOperationType)TypeNumber;
}

stArithmeticalOperation ReadArithmeticalOperation()
{
	stArithmeticalOperation Operation;

	Operation.Num1 = ReadNumber("Please enter the first number:");
	Operation.Num2 = ReadNumber("Please enter the second number:");
	Operation.Type = ReadOperationType();

	return Operation;
}

float Calculate(stArithmeticalOperation Op)
{
	switch (Op.Type)
	{
		case enOperationType::Addition:
			return Op.Num1 + Op.Num2; // it doesn't need any breaks as it returns the value.

		case enOperationType::Subtraction:
			return Op.Num1 - Op.Num2;

		case enOperationType::Multiplication:
			return Op.Num1 * Op.Num2;

		case enOperationType::Division:
			return Op.Num1 / Op.Num2;

		default:
			return Op.Num1 + Op.Num2;
	}
}

void PrintCalculationResult(stArithmeticalOperation Operation)
{
	cout << endl;
	cout << Operation.Num1 << endl;
	cout << Operation.Num2 << "\t" << (char)Operation.Type << endl;
	cout << "-----------------" << endl;
	cout << "= " << Calculate(Operation) << endl;
}

int main()
{
	stArithmeticalOperation Op = ReadArithmeticalOperation();

	PrintCalculationResult(Op);

	return 0;
}