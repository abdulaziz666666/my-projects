#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

enum enGameChoices { Rock = 1, Paper, Scissors };
enum enWinner { Player = 1, Computer, Draw };

struct stRoundInfo
{
	short RoundNumber = 0;
	enGameChoices PlayerChoice;
	enGameChoices ComputerChoice;
	enWinner Winner;
	string WinnerName;
};

struct stGameResults
{
	short GameRounds = 0;
	short PlayerWinTimes = 0;
	short ComputerWinTimes = 0;
	short DrawTimes = 0;
	enWinner GameWinner;
	string WinnerName = "";
};

short ReadHowManyRounds()
{
	short GameRounds = 1;

	do
	{
		cout << "How Many Rounds 1 to 10 ?\n";
		cin >> GameRounds;
	} while (GameRounds < 1 || GameRounds > 10);

	return GameRounds;
}

enGameChoices ReadPlayerChoice()
{
	int Choice = 1;

	do
	{
		cout << "What is your choice? [1] Rock, [2] Paper, [3] Scissors ? ";
		cin >> Choice;
	} while (Choice < 1 || Choice > 3);

	return (enGameChoices)Choice;
}

int RandomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

enGameChoices GetComputerChoice()
{
	return (enGameChoices)RandomNumber(1, 3);
}

enWinner WhoWonTheRound(stRoundInfo RoundInfo)
{
	if (RoundInfo.PlayerChoice == RoundInfo.ComputerChoice)
		return enWinner::Draw;

	switch (RoundInfo.PlayerChoice)
	{
	case enGameChoices::Rock:
		if (RoundInfo.ComputerChoice == enGameChoices::Paper)
			return enWinner::Computer;
	case enGameChoices::Paper:
		if (RoundInfo.ComputerChoice == enGameChoices::Scissors)
			return enWinner::Computer;
	case enGameChoices::Scissors:
		if (RoundInfo.ComputerChoice == enGameChoices::Rock)
			return enWinner::Computer;
	}

	return enWinner::Player;
}

string WinnerName(enWinner Winner)
{
	string WinnersNamesArray[3] = {"Player", "Computer", "No Winner"};
	return WinnersNamesArray[Winner - 1];
}

string ChoiceName(enGameChoices Choice)
{
	string GameChoicesArray[3] = { "Rock", "Paper", "Scissors" };
	return GameChoicesArray[Choice - 1];
}

void SetWinnerScreenColor(enWinner Winner)
{
	switch (Winner)
	{
	case enWinner::Player:
		system("color 2F");
		break;
	case enWinner::Computer:
		system("color 4F");
		cout << "\a";
		break;
	case enWinner::Draw:
		system("color 6F");
	}
}

void PrintRoundResults(stRoundInfo RoundInfo)
{ 
	cout << "\n----------Round [" << RoundInfo.RoundNumber << "]----------\n";
	cout << "Player Choice  : " << ChoiceName(RoundInfo.PlayerChoice) << endl;
	cout << "Computer Choice: " << ChoiceName(RoundInfo.ComputerChoice) << endl;
	cout << "Round Winner   : [" << RoundInfo.WinnerName << "]" << endl;
	cout << "\n-----------------------------------\n";

	SetWinnerScreenColor(RoundInfo.Winner);
}

enWinner WhoWonTheGame(short PlayerWinTimes, short ComputerWinTimes)
{
	if (PlayerWinTimes > ComputerWinTimes)
		return enWinner::Player;
	else if (ComputerWinTimes > PlayerWinTimes)
		return enWinner::Computer;
	else
		return enWinner::Draw;
}

stGameResults FillGameResults(short HowManyRounds, short PlayerWinTimes, short ComputerWinTimes, short DrawTimes)
{
	stGameResults GameResults;

	GameResults.GameRounds = HowManyRounds;
	GameResults.PlayerWinTimes = PlayerWinTimes;
	GameResults.ComputerWinTimes = ComputerWinTimes;
	GameResults.DrawTimes = DrawTimes;
	GameResults.GameWinner = WhoWonTheGame(PlayerWinTimes, ComputerWinTimes);
	GameResults.WinnerName = WinnerName(GameResults.GameWinner);

	return GameResults;
}

stGameResults PlayGame(short HowManyRounds)
{
	stRoundInfo RoundInfo;
	short PlayerWinTimes = 0, ComputerWinTimes = 0, DrawTimes = 0;

	for (int GameRound = 1; GameRound <= HowManyRounds; GameRound++)
	{
		cout << "\nRound [" << GameRound << "] begins:\n";
		RoundInfo.RoundNumber = GameRound;
		RoundInfo.PlayerChoice = ReadPlayerChoice();
		RoundInfo.ComputerChoice = GetComputerChoice();
		RoundInfo.Winner = WhoWonTheRound(RoundInfo);
		RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);

		if (RoundInfo.Winner == enWinner::Player)
			PlayerWinTimes++;
		else if (RoundInfo.Winner == enWinner::Computer)
			ComputerWinTimes++;
		else
			DrawTimes++;

		PrintRoundResults(RoundInfo);
	}

	return FillGameResults(HowManyRounds, PlayerWinTimes, ComputerWinTimes, DrawTimes);
}

void ResetScreen()
{
	system("cls");
	system("color 0F");
}

string Tabs(short Length)
{
	string T = "";

	for (int i = 1; i <= Length; i++)
		T += "\t";

	return T;
}

void ShowGameoverHeader()
{
	cout << endl;
	cout << Tabs(2) << "------------------------------------------------------\n\n";
	cout << Tabs(2) << "              +++ G a m e   O v e r +++\n\n";
	cout << Tabs(2) << "------------------------------------------------------\n\n";
}

void ShowGameResults(stGameResults GameResults)
{
	cout << Tabs(2) << "--------------------[Game Results]--------------------\n\n";
	cout << Tabs(2) << "Game Rounds:\t" << GameResults.GameRounds << endl;
	cout << Tabs(2) << "Player Wins:\t" << GameResults.PlayerWinTimes << endl;
	cout << Tabs(2) << "Computer Wins:\t" << GameResults.ComputerWinTimes << endl;
	cout << Tabs(2) << "Draws:\t\t" << GameResults.DrawTimes << endl;
	cout << Tabs(2) << "Final Winner:\t" << GameResults.WinnerName << endl << endl;
	cout << Tabs(2) << "------------------------------------------------------\n";

	SetWinnerScreenColor(GameResults.GameWinner);
}

void StartGame()
{
	char PlayAgain = 'Y';

	do
	{
		ResetScreen();
		stGameResults GameResults = PlayGame(ReadHowManyRounds());
		ShowGameoverHeader(); // Actually it was ShowGameoverScreen() but it was confusing.
		ShowGameResults(GameResults); // This also was ShowFinalGameResults() which wasn't clear.

		cout << endl << Tabs(3) << "Do you want to play again? Y/N? ";
		cin >> PlayAgain;

	} while (PlayAgain == 'Y' || PlayAgain == 'y');
}

int main()
{
	srand((unsigned)time(NULL));

	StartGame();

	return 0;
}