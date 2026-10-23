#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

enum enQuestionsLevel { Easy = 1, Med, Hard, MixedDifficulties };
enum enOperationType { Add = 1, Sub, Mul, Div, MixedOperations };
enum enPassFail { Fail, Pass }; // So Fail is 0

struct stQuiz
{
	short TotalQuestions = 0;
	enQuestionsLevel QuestionsLevel;
	enOperationType QuestionsOperationType;
	short CorrectAnswersNumber = 0;
	short WrongAnswersNumber = 0;
	enPassFail PassOrFail;
};

struct stMathOperation
{
	short Num1 = 0;
	short Num2 = 0;
	enOperationType OperationType;
	short Answer = 0;;
};

short ReadHowManyQuestions()
{
	short HowManyQuestions;

	do
	{
		cout << "How many questions do you want to answer ?: ";
		cin >> HowManyQuestions;
	} while (HowManyQuestions <= 0);

	return HowManyQuestions;
}

enQuestionsLevel ReadQustionsLevel()
{
	short LevelNumber;

	do
	{
		cout << "Enter questions level [1] Easy, [2] Med, [3] Hard, [4] Mix ? ";
		cin >> LevelNumber;
	} while (LevelNumber < 1 || LevelNumber > 4);

	return (enQuestionsLevel)LevelNumber;
}

enOperationType ReadQuestionsOperationType()
{
	short OperationTypeNumber;

	do
	{
		cout << "Enter questions Operation Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix ? ";
		cin >> OperationTypeNumber;
	} while (OperationTypeNumber < 1 || OperationTypeNumber > 5);

	return (enOperationType)OperationTypeNumber;
}

stQuiz ReadQuizInfo()
{
	stQuiz Quiz;

	Quiz.TotalQuestions = ReadHowManyQuestions();
	Quiz.QuestionsLevel = ReadQustionsLevel();
	Quiz.QuestionsOperationType = ReadQuestionsOperationType();

	return Quiz;
}

bool AskPlayerToPlayAgain()
{
	char PlayAgain;

	cout << "\nDo you want to play again (Y/N)? ";
	cin >> PlayAgain;

	return (PlayAgain == 'Y' || PlayAgain == 'y');
}

void ResetScreen()
{
	system("cls");
	system("color 0F");
}

void ShowQuestionHeader(short QuestionNumber, short TotalQuestions)
{
	cout << "\nQuestion [" << QuestionNumber << "/" << TotalQuestions << "]\n\n";
}

short RandomNumber(short From, short To)
{
	return rand() % (To - From + 1) + From;
}

char OperationSymbol(stMathOperation MathOperation)
{
	switch (MathOperation.OperationType)
	{
	case enOperationType::Add:
		return '+';
	case enOperationType::Sub:
		return '-';
	case enOperationType::Mul:
		return 'x';
	case enOperationType::Div:
		return '/';
	}
}

void FillMathOperationNumbers(stMathOperation& MathOperation, enQuestionsLevel QuestionsLevel)
{
	switch (QuestionsLevel)
	{
	case enQuestionsLevel::Easy:
		MathOperation.Num1 = RandomNumber(1, 9);
		MathOperation.Num2 = RandomNumber(1, 9);
		break;
	case enQuestionsLevel::Med:
		MathOperation.Num1 = RandomNumber(10, 99);
		MathOperation.Num2 = RandomNumber(10, 99);
		break;
	case enQuestionsLevel::Hard:
		MathOperation.Num1 = RandomNumber(50, 150);
		MathOperation.Num2 = RandomNumber(50, 150);
		break;
	case enQuestionsLevel::MixedDifficulties:
		short RandomNumbers[3] = { RandomNumber(1, 9) , RandomNumber(10, 99), RandomNumber(50, 150) };
		MathOperation.Num1 = RandomNumbers[RandomNumber(0, 2)];
		MathOperation.Num2 = RandomNumbers[RandomNumber(0, 2)];
		break;
	}
}

void FillMathOperationType(stMathOperation& MathOperation, enOperationType QuestionsType)
{
	if (QuestionsType == enOperationType::MixedOperations)
	{
		MathOperation.OperationType = (enOperationType)RandomNumber(1, 4);
	}
	else
		// as operation type is same as question type, except for MIX, which is excluded here.
		MathOperation.OperationType = (enOperationType)QuestionsType;
}

stMathOperation GenerateMathOperation(stQuiz &Quiz)
{
	stMathOperation MathOperation;

	FillMathOperationNumbers(MathOperation, Quiz.QuestionsLevel);
	FillMathOperationType(MathOperation, Quiz.QuestionsOperationType);

	return MathOperation;
}

void RepresentMathOperation(stMathOperation MathOperation)
{
	cout << MathOperation.Num1 << endl;

	cout << MathOperation.Num2 << "\t";
	cout << OperationSymbol(MathOperation) << endl;

	cout << "----------\n";
}

short SolveMathOperation(stMathOperation& MathOperation)
{
	switch (MathOperation.OperationType)
	{
	case enOperationType::Add:
		return MathOperation.Num1 + MathOperation.Num2;
	case enOperationType::Sub:
		return MathOperation.Num1 - MathOperation.Num2;
	case enOperationType::Mul:
		return MathOperation.Num1 * MathOperation.Num2;
	case enOperationType::Div:
		return MathOperation.Num1 / MathOperation.Num2;
	}
}

void SetScreenColorForAnswer(bool IsCorrectAnswer)
{
	if (IsCorrectAnswer)
	{
		system("color 2F");
		cout << "\nCorrect Answer :-)\n";
	}
	else
	{
		system("color 4F");
		cout << "\nWrong Answer :-(\n";
		cout << "\a";
	}
}

void CheckUserAnswer(stQuiz& Quiz, short UserAnswer, short CorrectAnswer)
{
	SetScreenColorForAnswer(UserAnswer == CorrectAnswer);

	if (UserAnswer == CorrectAnswer)
		Quiz.CorrectAnswersNumber++;
	else
	{
		Quiz.WrongAnswersNumber++;
		cout << "Correct Answer is " << CorrectAnswer << endl;
	}

}

enPassFail GetPassOrFail(stQuiz& Quiz)
{
	if (Quiz.CorrectAnswersNumber > Quiz.WrongAnswersNumber)
		return enPassFail::Pass;
	else
		return enPassFail::Fail;
}

string GetPassOrFailText(enPassFail PassFail)
{
	if (PassFail == enPassFail::Pass)
		return "Pass :-)";
	else
		return "Fail :-(";
}

void ShowGameoverHeader(stQuiz Quiz)
{
	cout << "\n\n--------------------------\n\n";
	cout << " Final Result is " << GetPassOrFailText(Quiz.PassOrFail);
	cout << "\n\n--------------------------\n\n";
}

string OperationName(enOperationType OperationType)
{
	switch (OperationType)
	{
	case enOperationType::Add:
		return "Addition";
	case enOperationType::Sub:
		return "Subtraction";
	case enOperationType::Mul:
		return "Multiplication";
	case enOperationType::Div:
		return "Division";
	case enOperationType::MixedOperations:
		return "Mixed";
	}
}

string QuestionsLevelName(enQuestionsLevel QuestionsLevel)
{
	switch (QuestionsLevel)
	{
	case enQuestionsLevel::Easy:
		return "Easy";
	case enQuestionsLevel::Med:
		return "Med";
	case enQuestionsLevel::Hard:
		return "Hard";
	case enQuestionsLevel::MixedDifficulties:
		return "Mixed";
	}
}

void ShowResults(stQuiz Quiz)
{
	cout << "Number of Questions:\t" << Quiz.TotalQuestions << endl;
	cout << "Questions Level:\t" << QuestionsLevelName(Quiz.QuestionsLevel) << endl;
	cout << "Questions Type:\t\t" << OperationName(Quiz.QuestionsOperationType) << endl;
	cout << "Correct Answers:\t" << Quiz.CorrectAnswersNumber << endl;
	cout << "Wrong Answers:\t\t" << Quiz.WrongAnswersNumber << endl;
}

void StartGame()
{
	do
	{
		ResetScreen();
		
		stQuiz Quiz = ReadQuizInfo();
		stMathOperation MathOperation;

		short UserAnswer = 0;

		for (short QuestionNumber = 1; QuestionNumber <= Quiz.TotalQuestions; QuestionNumber++)
		{
			ShowQuestionHeader(QuestionNumber, Quiz.TotalQuestions);

			MathOperation = GenerateMathOperation(Quiz);
			RepresentMathOperation(MathOperation);

			cin >> UserAnswer;
			MathOperation.Answer = SolveMathOperation(MathOperation);
			
			CheckUserAnswer(Quiz, UserAnswer, MathOperation.Answer);
		}

		Quiz.PassOrFail = GetPassOrFail(Quiz);
		
		SetScreenColorForAnswer(Quiz.PassOrFail);
		ShowGameoverHeader(Quiz);
		ShowResults(Quiz);

	} while (AskPlayerToPlayAgain());
}

int main()
{
	srand((unsigned)time(NULL));

	StartGame();

	return 0;
}