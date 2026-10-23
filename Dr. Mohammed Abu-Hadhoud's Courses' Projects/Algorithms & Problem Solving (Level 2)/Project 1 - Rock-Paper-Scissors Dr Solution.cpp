// I may write my own solution with Dr. Mohammed's configurations,
// but not everything from his solution. I feel confused somehow 
// with his solution.
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

//enum enRockPaperScissors { Rock = 1, Paper, Scissors };
//enum enRPSChoices { Rock = 1, Paper, Scissors };
enum enPlayOptions { Rock = 1, Paper, Scissors };
enum enWinner { Player = 1, Computer, Draw };

// struct stGameStatus
struct stGameInfo
{
	short Rounds = 0;
	short PlayerWins = 0;
	short ComputerWins = 0;
	short DrawTimes = 0;
	enWinner LastRoundWinner;
};

//struct stRoundInfo
struct stRoundInfo
{
	enPlayOptions PlayerChoice, ComputerChoice;
};

//int ReadPositiveNumber(string Message)
short ReadPositiveNumber(string Message)
{
	short Num;

	do
	{
		cout << Message << endl;
		cin >> Num;
	} while (Num <= 0);

	return Num;
}

short GetRandomNumber(short From, short To)
{
	return rand() % (To - From + 1) + From;
}

string Tabs(short Length)
{
	string Tabs = "";

	for (int i = 1; i <= Length; i++)
		Tabs += "\t";

	return Tabs;
}

string GetPlayOptionName(enPlayOptions PlayOption)
{
	const string PlayOptionsArray[3] = { "Rock", "Paper", "Scissors" };
	return PlayOptionsArray[PlayOption - 1];
	//switch (Choice)
	//{
	//case enPlayOptions::Rock:
	//	return "Rock";
	//case enPlayOptions::Paper:
	//	return "Paper";
	//case enPlayOptions::Scissors:
	//	return "Scissors";
	//}
}

string GetWinnerName(enWinner Winner)
{
	const string WinnersArray[3] = { "[Player]", "[Computer]", "[No Winner]" };
	return WinnersArray[Winner - 1];
	//switch (Winner)
	//{
	//case enWinner::Player:
	//	return "[Player]";
	//case enWinner::Computer:
	//	return "[Computer]";
	//case enWinner::Draw:
	//	return "[No Winner]";
	//}
}

enPlayOptions AskPlayerWhatToThrow()
{
	short PlayOptionNumber;

	do
	{
		cout << "\n[1]: Rock, [2]: Paper, [3]: Scissors\n";
		cout << "Your Choice: ";

		cin >> PlayOptionNumber;

	} while (PlayOptionNumber < 1 || PlayOptionNumber > 3);

	return (enPlayOptions)PlayOptionNumber;
}

// although im not fully agree with separating this in
// another function.
enPlayOptions GetComputerChoice()
{
	return (enPlayOptions)GetRandomNumber(1, 3);
}

//void AssignWinner(stRoundInfo RoundInfo, stGameInfo& GameInfo)
enWinner WhoWonTheRound(stRoundInfo RoundInfo)
{
	if (RoundInfo.PlayerChoice == RoundInfo.ComputerChoice)
		return enWinner::Draw;

	switch (RoundInfo.PlayerChoice)
	{
	case enPlayOptions::Rock:
		if (RoundInfo.ComputerChoice == enPlayOptions::Paper)
			return enWinner::Computer;

	case enPlayOptions::Paper:
		if (RoundInfo.ComputerChoice == enPlayOptions::Scissors)
			return enWinner::Computer;

	case enPlayOptions::Scissors:
		if (RoundInfo.ComputerChoice == enPlayOptions::Rock)
			return enWinner::Computer;
	}

	return enWinner::Player;
	//bool PlayerIsRock = RoundInfo.PlayerChoice == enPlayOptions::Rock;
	//bool PlayerIsPaper = RoundInfo.PlayerChoice == enPlayOptions::Paper;
	//bool PlayerIsScissors = RoundInfo.PlayerChoice == enPlayOptions::Scissors;

	//bool ComputerIsRock = RoundInfo.ComputerChoice == enPlayOptions::Rock;
	//bool ComputerIsPaper = RoundInfo.ComputerChoice == enPlayOptions::Paper;
	//bool ComputerIsScissors = RoundInfo.ComputerChoice == enPlayOptions::Scissors;

	//if (RoundInfo.PlayerChoice == RoundInfo.ComputerChoice)
	//	GameInfo.LastRoundWinner = enWinner::Draw;
	//else
	//{
	//	if (PlayerIsRock && ComputerIsScissors)
	//		GameInfo.LastRoundWinner = enWinner::Player;
	//	else if (PlayerIsScissors && ComputerIsRock)
	//		GameInfo.LastRoundWinner = enWinner::Computer;

	//	else if (PlayerIsPaper && ComputerIsRock)
	//		GameInfo.LastRoundWinner = enWinner::Player;
	//	else if (PlayerIsRock && ComputerIsPaper)
	//		GameInfo.LastRoundWinner = enWinner::Computer;

	//	else if (PlayerIsScissors && ComputerIsPaper)
	//		GameInfo.LastRoundWinner = enWinner::Player;
	//	else if (PlayerIsPaper && ComputerIsScissors)
	//		GameInfo.LastRoundWinner = enWinner::Computer;
	//}
}

void SetGameInfo(stGameInfo& GameInfo)
{
	if (GameInfo.LastRoundWinner == enWinner::Player)
		GameInfo.PlayerWins++;
	else if (GameInfo.LastRoundWinner == enWinner::Computer)
		GameInfo.ComputerWins++;
	else
		GameInfo.DrawTimes++;
}

void PrintRoundResults(short RoundNumber, stRoundInfo RoundInfo, stGameInfo GameInfo)
{
	cout << "\n----------Round [" << RoundNumber << "]----------\n";

	cout << endl;
	cout << "Player Choice\t: " << GetPlayOptionName(RoundInfo.PlayerChoice) << endl;
	cout << "Computer Choice\t: " << GetPlayOptionName(RoundInfo.ComputerChoice) << endl;
	cout << "Round Winner\t: " << GetWinnerName(GameInfo.LastRoundWinner) << endl;
	cout << endl;

	cout << "-----------------------------" << endl;
}

void RespondToWinner(enWinner Winner)
{
	switch (Winner)
	{
	case enWinner::Player:
		system("color 2F"); // green
		break;
	case enWinner::Computer:
		system("color 4F"); // red
		cout << "\a";
		break;
	default:
		system("color 6F"); // yellow
	}
}



void PlayRound(short RoundNumber, stGameInfo& GameInfo)
{
	cout << "\nRound [" << RoundNumber << "] Begins:\n";

	stRoundInfo RoundInfo;
	RoundInfo.PlayerChoice = AskPlayerWhatToThrow();
	RoundInfo.ComputerChoice = GetComputerChoice();

	GameInfo.LastRoundWinner = WhoWonTheRound(RoundInfo);
	RespondToWinner(GameInfo.LastRoundWinner);

	SetGameInfo(GameInfo);
	PrintRoundResults(RoundNumber, RoundInfo, GameInfo);
}

void PrintGameoverHeader()
{
	cout << endl;
	cout << Tabs(3) << "--------------------------------------------\n\n";
	cout << Tabs(3) << "          +++ G a m e   O v e r +++\n";
	cout << Tabs(3) << "--------------------------------------------\n\n";
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

	cout << Tabs(3) << "----------------[Game Results]----------------\n\n";
	cout << Tabs(3) << "Game Rounds\t: " << GameInfo.Rounds << endl;
	cout << Tabs(3) << "Player Wins\t: " << GameInfo.PlayerWins << endl;
	cout << Tabs(3) << "Computer Wins\t: " << GameInfo.ComputerWins << endl;
	cout << Tabs(3) << "Draw Times\t: " << GameInfo.DrawTimes << endl;
	cout << Tabs(3) << "Final Winner\t: " << GetFinalWinner(GameInfo) << endl;
	cout << endl;
	cout << "------------------------------------------------\n";
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

void StartGame()
{
	stGameInfo GameInfo;

	do
	{
		ResetGameSettings(GameInfo);

		GameInfo.Rounds = ReadPositiveNumber("How many rounds do you want to play?: ");

		for (int i = 1; i <= GameInfo.Rounds; i++)
			PlayRound(i, GameInfo);

		PrintGameoverScreen(GameInfo);

	} while (AskPlayerToPlayAgain());
}

int main()
{
	srand((unsigned)time(NULL));

	StartGame();

	return 0;
}