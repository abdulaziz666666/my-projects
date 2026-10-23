#include <iostream>
using namespace std;

struct stMathOperation
{
	float Num1;
	float Num2;
	char Operation;
};

void ReadMathOperation(stMathOperation &MathOperation)
{
	cout << "Please Enter The First Number: ";
	cin >> MathOperation.Num1;

	cout << "Please Enter The Second Number: ";
	cin >> MathOperation.Num2;

	cout << "Please Enter The Operation (+ - * /): ";
	cin >> MathOperation.Operation;

	cout << endl;
}

float Calculate(stMathOperation MathOperation)
{
	switch (MathOperation.Operation)
	{
	case '+':
		return MathOperation.Num1 + MathOperation.Num2;
		break;

	case '-':
		return MathOperation.Num1 - MathOperation.Num2;
		break;

	case '*':
		return MathOperation.Num1 * MathOperation.Num2;
		break;

	case '/':
		return MathOperation.Num1 / MathOperation.Num2;
		break;

	default:
		return 0;
	}
	// The past way.
	//if (MathOperation.Operation == '+')
	//{
	//	return MathOperation.Num1 + MathOperation.Num2;
	//}
	//else if (MathOperation.Operation == '-')
	//{
	//	return MathOperation.Num1 - MathOperation.Num2;
	//}
	//else if (MathOperation.Operation == '*')
	//{
	//	return MathOperation.Num1 * MathOperation.Num2;
	//}
	//else if (MathOperation.Operation == '/')
	//{
	//	return MathOperation.Num1 / MathOperation.Num2;
	//}
	//else {
	//	return 0;
	//}
}

void PrintCalculations(stMathOperation MathOperation)
{
	cout << MathOperation.Num1 << endl;
	cout << MathOperation.Num2 << "\t" << MathOperation.Operation << endl;

	cout << "-------------------------" << endl;

	cout << "= " << Calculate(MathOperation) << endl;
}

int main()
{
	stMathOperation MathOperation;

	ReadMathOperation(MathOperation);
	PrintCalculations(MathOperation);

	return 0;
}