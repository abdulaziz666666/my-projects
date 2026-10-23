#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

//enum enRockPaperScissors { Rock = 1, Paper, Scissors };
enum enRPSChoices { Rock = 1, Paper, Scissors };

// struct stGameStatus
struct stGameInfo
{
	int Rounds, PlayerWins, ComputerWins, DrawTimes;
	string LastRoundWinner;
};

struct stRoundChoices
{
	enRPSChoices PlayerChoice, ComputerChoice;
};

int ReadPositiveNumber(string Message)
{
	int Num;

	do
	{
		cout << Message << endl;
		cin >> Num;
	} while (Num <= 0);

	return Num;
}

int GetRandomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

void PrintHLine(int Length)
{
	for (int i = 1; i <= Length; i++)
		cout << "-";
}

string GetChoiceName(enRPSChoices Choice)
{
	switch (Choice)
	{
		case enRPSChoices::Rock:
			return "Rock";
		case enRPSChoices::Paper:
			return "Paper";
		case enRPSChoices::Scissors:
			return "Scissors";
	}
}

enRPSChoices AskPlayerWhatToThrow()
{
	int ChoiceNumber;

	cout << "\n[1]: Rock, [2]: Paper, [3]: Scissors\n";
	cout << "Your Choice: ";

	cin >> ChoiceNumber;

	return (enRPSChoices)ChoiceNumber;
}

void SetGameInfo(stRoundChoices RoundChoices, stGameInfo& GameInfo)
{
	bool PlayerIsRock = RoundChoices.PlayerChoice == enRPSChoices::Rock;
	bool PlayerIsPaper = RoundChoices.PlayerChoice == enRPSChoices::Paper;
	bool PlayerIsScissors = RoundChoices.PlayerChoice == enRPSChoices::Scissors;

	bool ComputerIsRock = RoundChoices.ComputerChoice == enRPSChoices::Rock;
	bool ComputerIsPaper = RoundChoices.ComputerChoice == enRPSChoices::Paper;
	bool ComputerIsScissors = RoundChoices.ComputerChoice == enRPSChoices::Scissors;

	if (RoundChoices.PlayerChoice == RoundChoices.ComputerChoice)
		GameInfo.LastRoundWinner = "[No Winner]";

	else
	{
		if (PlayerIsRock && ComputerIsScissors)
			GameInfo.LastRoundWinner = "[Player]";
		else if (PlayerIsScissors && ComputerIsRock)
			GameInfo.LastRoundWinner = "[Computer]";

		else if (PlayerIsPaper && ComputerIsRock)
			GameInfo.LastRoundWinner = "[Player]";
		else if (PlayerIsRock && ComputerIsPaper)
			GameInfo.LastRoundWinner = "[Computer]";

		else if (PlayerIsScissors && ComputerIsPaper)
			GameInfo.LastRoundWinner = "[Player]";
		else if (PlayerIsPaper && ComputerIsScissors)
			GameInfo.LastRoundWinner = "[Computer]";
	}
	
	if (GameInfo.LastRoundWinner == "[Player]")
		GameInfo.PlayerWins++;
	else if (GameInfo.LastRoundWinner == "[Computer]")
		GameInfo.ComputerWins++;
	else
		GameInfo.DrawTimes++;
}

void PrintRoundResults(int RoundNumber, stRoundChoices RoundChoices, stGameInfo GameInfo)
{
	cout << endl;
	PrintHLine(10);
	cout << "Round [" << RoundNumber << "]";
	PrintHLine(10);
	cout << endl;

	cout << endl;
	cout << "Player Choice\t: " << GetChoiceName(RoundChoices.PlayerChoice) << endl;
	cout << "Computer Choice\t: " << GetChoiceName(RoundChoices.ComputerChoice) << endl;
	cout << "Round Winner\t: " << GameInfo.LastRoundWinner << endl;
	cout << endl;

	PrintHLine(29);
	cout << endl;
}

void RespondToWinner(string Winner)
{
	if (Winner == "[Player]")
		system("color 2F"); // green
	else if (Winner == "[Computer]")
	{
		system("color 4F"); // red
		cout << "\a";
	}
	else
		system("color 6F"); // yellow
}

void PlayRound(int RoundNumber, stGameInfo &GameInfo)
{
	cout << "\nRound [" << RoundNumber << "] Begins:\n";

	stRoundChoices RoundChoices;
	RoundChoices.PlayerChoice = AskPlayerWhatToThrow();
	RoundChoices.ComputerChoice = (enRPSChoices)GetRandomNumber(1, 3);

	SetGameInfo(RoundChoices, GameInfo);
	PrintRoundResults(RoundNumber, RoundChoices, GameInfo);
	RespondToWinner(GameInfo.LastRoundWinner);
}

void PrintGameoverHeader()
{
	// Upper Horizontal Line
	cout << endl;
	cout << "\t\t\t";
	PrintHLine(54);

	cout << endl;
	cout << "\n\t\t\t\t\t";
	cout << "+++ G a m e   O v e r +++\n";
	cout << endl;

	// Lower Horizontal Line
	cout << "\t\t\t";
	PrintHLine(54);
	cout << endl;
}

string GetFinalWinner(stGameInfo GameInfo)
{
	if (GameInfo.PlayerWins > GameInfo.ComputerWins)
		return "[Player]";
	else if (GameInfo.ComputerWins > GameInfo.PlayerWins)
		return "[Computer]";
	else
		return "[No Winner]";
}

void PrintGameResults(stGameInfo GameInfo)
{
	cout << endl;

	cout << "\t\t\t";
	PrintHLine(20);
	cout << "[Game Results]";
	PrintHLine(20);
	cout << endl;
	
	cout << endl;
	cout << "\t\t\t";
	cout << "Game Rounds\t: " << GameInfo.Rounds << endl;

	cout << "\t\t\t";
	cout << "Player Wins\t: " << GameInfo.PlayerWins << endl;

	cout << "\t\t\t";
	cout << "Computer Wins\t: " << GameInfo.ComputerWins << endl;

	cout << "\t\t\t";
	cout << "Draw Times\t: " << GameInfo.DrawTimes << endl;

	cout << "\t\t\t";
	cout << "Final Winner\t: " << GetFinalWinner(GameInfo) << endl;
	cout << endl;

	cout << "\t\t\t";
	PrintHLine(50);
	cout << endl;
}

void PrintGameoverScreen(stGameInfo GameInfo)
{
	PrintGameoverHeader();
	PrintGameResults(GameInfo);
}

bool AskPlayerToPlayAgain()
{
	char Answer;

	cout << "\n\t\t\t";
	cout << "Do you want to play again? (Y/N): ";
	cin >> Answer;

	return Answer == 'y' || Answer == 'Y';
}

//void ResetGameInfo(stGameInfo& GameInfo)
//void ResetGame(stGameInfo& GameInfo)
void ResetGameSettings(stGameInfo& GameInfo)
{
	GameInfo.Rounds = 0;
	GameInfo.PlayerWins = 0;
	GameInfo.ComputerWins = 0;
	GameInfo.DrawTimes = 0;

	system("cls");
	system("color 0F");
}

int main()
{
	srand((unsigned)time(NULL));

	stGameInfo GameInfo;

	do
	{
		ResetGameSettings(GameInfo);
		
		GameInfo.Rounds = ReadPositiveNumber("How many rounds do you want to play?: ");
		
		for (int i = 1; i <= GameInfo.Rounds; i++)
			PlayRound(i, GameInfo);

		PrintGameoverScreen(GameInfo);

	} while (AskPlayerToPlayAgain());

	return 0;
}