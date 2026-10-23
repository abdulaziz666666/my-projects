#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

enum enQuestionsLevel { Easy = 1, Med, Hard, MixedDifficulty };
enum enOperationType { Add = 1, Sub, Mul, Div, MixedOperation };

struct stQuestion
{
	short Num1 = 0;
	short Num2 = 0;
	enOperationType OperationType;
	short CorrectAnswer = 0;
	short PlayerAnswer = 0;
	bool PlayerAnswerIsCorrect = false;
};

struct stQuiz
{
	stQuestion QuestionsList[100];
	short NumberOfQuestions;
	enQuestionsLevel QuestionsLevel;
	enOperationType QuestionsOpType;
	short NumberOfRightAnswers = 0;
	short NumberOfWrongAnswers = 0;
	bool IsPass = false;
};

short ReadHowManyQuestions()
{
	short NumberOfQuestions;

	do
	{
		cout << "How many questions do you want? (Max: 100): ";
		cin >> NumberOfQuestions;

	} while (NumberOfQuestions < 1 || NumberOfQuestions > 100);

	return NumberOfQuestions;
}

enQuestionsLevel ReadQuestionsLevel()
{
	int QuestionsLevelNumber;

	do
	{
		cout << "What level do you trigger? [1] Easy [2] Med [3] Hard [4] Mixed? : ";
		cin >> QuestionsLevelNumber;

	} while (QuestionsLevelNumber < 1 || QuestionsLevelNumber > 4);

	return (enQuestionsLevel)QuestionsLevelNumber;
}

enOperationType ReadQuestionsOpType()
{
	int QuestionsOpTypeNumber;

	do
	{
		cout << "What operation do you trigger?";
		cout << " [1] Add [2] Subtract [3] Multiplication [4] Divison [5] Mixed ? : ";
		cin >> QuestionsOpTypeNumber;

	} while (QuestionsOpTypeNumber < 1 || QuestionsOpTypeNumber > 5);

	return (enOperationType)QuestionsOpTypeNumber;

}

int RandomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

short SolveQuestion(stQuestion Question)
{
	switch (Question.OperationType)
	{
	case enOperationType::Add:
		return Question.Num1 + Question.Num2;

	case enOperationType::Sub:
		return Question.Num1 - Question.Num2;

	case enOperationType::Mul:
		return Question.Num1 * Question.Num2;

	case enOperationType::Div:
		return Question.Num1 / Question.Num2;
	}
}

stQuestion GenerateQuestion(enQuestionsLevel QuestionsLevel, enOperationType QuestionsOpType)
{
	stQuestion Question;

	if (QuestionsLevel == enQuestionsLevel::MixedDifficulty)
		QuestionsLevel = (enQuestionsLevel)RandomNumber(1, 3);

	if (QuestionsOpType == enOperationType::MixedOperation)
		QuestionsOpType = (enOperationType)RandomNumber(1, 4);

	Question.OperationType = QuestionsOpType;

	switch (QuestionsLevel)
	{
	case enQuestionsLevel::Easy:
		Question.Num1 = RandomNumber(1, 20);
		Question.Num2 = RandomNumber(1, 20);
		break;

	case enQuestionsLevel::Med:
		Question.Num1 = RandomNumber(20, 50);
		Question.Num2 = RandomNumber(20, 50);
		break;

	case enQuestionsLevel::Hard:
		Question.Num1 = RandomNumber(50, 150);
		Question.Num2 = RandomNumber(50, 150);
		break;
	}

	Question.CorrectAnswer = SolveQuestion(Question); // It will only use operands and operation type.
	
	return Question;
}

void GenerateQuizQuestions(stQuiz &Quiz)
{
	// although braces aren't needed, i added them to ensure the code can be read clearly.
	for (short QuestionNumber = 0; QuestionNumber < Quiz.NumberOfQuestions; QuestionNumber++)
	{
		Quiz.QuestionsList[QuestionNumber] = GenerateQuestion(Quiz.QuestionsLevel, Quiz.QuestionsOpType);
	} 
}

char GetOperationTypeSymbol(enOperationType OperationType)
{
	char OperationsSymbolsArray[4] = { '+', '-', '*', '/' };
	return OperationsSymbolsArray[OperationType - 1];
}

void PrintQuestion(stQuestion Question, short QuestionNumber)
{
	cout << "\n-----Question [" << QuestionNumber + 1 << "]-----\n\n";
	cout << Question.Num1 << endl;
	cout << Question.Num2 << "\t" << GetOperationTypeSymbol(Question.OperationType) << endl;
	cout << "----------\n";
}

short ReadPlayerAnswer()
{
	short PlayerAnswer;
	cin >> PlayerAnswer;
	return PlayerAnswer;
}

void SetScreenColor(bool AnsweredCorrectly)
{
	if (AnsweredCorrectly)
		system("color 2F");
	else
		system("color 4F");
}

void RingBellIfAnsweredWrongly(bool AnsweredWrongly)
{
	if (AnsweredWrongly)
		cout << "\a";
}

void ShowAnswerResult(bool AnsweredCorrectly)
{
	if (AnsweredCorrectly)
		cout << "\nThe answer is correct :-)\n";
	else
		cout << "\nThe answer is wrong :-(\n";

	SetScreenColor(AnsweredCorrectly);
	RingBellIfAnsweredWrongly(!AnsweredCorrectly);
}

void ShowCorrectAnswerIfNeeded(bool AnsweredCorrectly, short CorrectAnswer)
{
	if (!AnsweredCorrectly)
		cout << "The correct answer is " << CorrectAnswer << endl;
}

void ShowResultAndCorrectAnswer(stQuestion Question)
{
	ShowAnswerResult(Question.PlayerAnswerIsCorrect);
	ShowCorrectAnswerIfNeeded(Question.PlayerAnswerIsCorrect, Question.CorrectAnswer);
}

void CheckPlayerAnswer(stQuiz& Quiz, stQuestion &Question)
{
	Question.PlayerAnswerIsCorrect = Question.PlayerAnswer == Question.CorrectAnswer;

	if (Question.PlayerAnswerIsCorrect)
		Quiz.NumberOfRightAnswers++;
	else
		Quiz.NumberOfWrongAnswers++;
}

void AskQuestionsAndReadAnswers(stQuiz &Quiz)
{
	for (short QuestionNumber = 0; QuestionNumber < Quiz.NumberOfQuestions; QuestionNumber++)
	{
		PrintQuestion(Quiz.QuestionsList[QuestionNumber], QuestionNumber);

		Quiz.QuestionsList[QuestionNumber].PlayerAnswer = ReadPlayerAnswer();
		CheckPlayerAnswer(Quiz, Quiz.QuestionsList[QuestionNumber]);

		ShowResultAndCorrectAnswer(Quiz.QuestionsList[QuestionNumber]);
	}

	Quiz.IsPass = (Quiz.NumberOfRightAnswers >= Quiz.NumberOfWrongAnswers);
}

string GetFinalResultText(bool IsPass)
{
	if (IsPass)
		return "Pass :-)";
	else
		return "Fail :-(";
}

string GetQuestionsLevelName(enQuestionsLevel QuestionsLevel)
{
	string QuestionsLevelArray[4] = { "Easy", "Med", "Hard", "Mix" };
	return QuestionsLevelArray[QuestionsLevel - 1];
}

string GetQuestionsOpTypeName(enOperationType OperationType)
{
	string OpTypeArray[5] = { "+", "-", "*", "/" , "Mix"};
	return OpTypeArray[OperationType - 1];
}

void PrintResults(stQuiz Quiz)
{
	cout << "\n--------------------------\n\n";
	cout << " Final result is " << GetFinalResultText(Quiz.IsPass) << endl;
	cout << "\n--------------------------\n\n";

	cout << "Total Questions:\t" << Quiz.NumberOfQuestions << endl;
	cout << "Questions Level:\t" << GetQuestionsLevelName(Quiz.QuestionsLevel) << endl;
	cout << "Questions Type:\t\t" << GetQuestionsOpTypeName(Quiz.QuestionsOpType) << endl;
	cout << "Right Answers:\t\t" << Quiz.NumberOfRightAnswers << endl;
	cout << "Wrong Answers:\t\t" << Quiz.NumberOfWrongAnswers << endl;
	cout << "\n--------------------------\n\n";

	SetScreenColor(Quiz.IsPass);
	RingBellIfAnsweredWrongly(!Quiz.IsPass); // Same as if answered wrongly, but used here.
}

void PlayMathGame()
{
	stQuiz Quiz;

	Quiz.NumberOfQuestions = ReadHowManyQuestions();
	Quiz.QuestionsLevel = ReadQuestionsLevel();
	Quiz.QuestionsOpType = ReadQuestionsOpType();

	GenerateQuizQuestions(Quiz);
	AskQuestionsAndReadAnswers(Quiz);
	PrintResults(Quiz);
}

void ResetScreen()
{
	system("cls");
	system("color 0F");
}

void StartGame()
{
	char PlayAgain = 'Y';

	do
	{
		ResetScreen();
		PlayMathGame();

		cout << "Do you want to play again (Y/N)? ";
		cin >> PlayAgain;

	} while (PlayAgain == 'Y' || PlayAgain == 'y');
}

int main()
{
	srand((unsigned)time(NULL));

	StartGame();

	// To make this type of programs, we need to write in a way we ensure
	// we have all needed inputs to output results. For instance, if we
	// have a structure that should be filled at the end of the program,
	// we have to harness functions for that purpose, so at the end we
	// can represent this structure very well. Also, we should code through
	// well-separated functions. After writing a function, mostly, it will
	// contain some inner-functions that do smaller tasks, so now you could
	// go to every single "inner-function" and write it without putting an
	// eye on how they will work (at first). Finally, we have wrote the 
	// program, we made it!

	return 0;
}