#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

enum enWinner {Player=1, Computer, Draw, Undetermined};
enum enWhoPlayThisTurn {PlayerTurn=1, ComputerTurn};

struct stGameInfo
{
	char Board[9];

	char PlayerSymbol;
	char ComputerSymbol;

	enWhoPlayThisTurn WhoPlayThisTurn = enWhoPlayThisTurn::PlayerTurn;
	enWinner Winner = enWinner::Undetermined; 
};

void ResetGame()
{
	system("cls");
	system("color 0F");
}

void FillBoardWithEmptySpaces(char Board[9])
{
	for (int i = 0; i < 9; i++)
		Board[i] = ' ';
}

bool PlayerSelectedInvalidSymbol(char PlayerSymbol)
{
	// this function checks if player entered a WRONG symbol.
	return !(PlayerSymbol == 'X' || PlayerSymbol == 'O'); // means: none of them.
}

char GetCapitalLetter(char Letter)
{
	if (int(Letter) >= 97) // indicates it is a small letter.
		return char(int(Letter) - 32); // shifting from small to capital.
	else
		return Letter; // if not >= 97 then it is capital already.
}

short RandomNumber(short From, short To)
{
	return rand() % (To - From + 1) + From;
}

char ReadPlayerSymbol()
{
	char PlayerSymbol;

	do
	{
		cout << "Please choose you symbol (X/O): ";
		cin >> PlayerSymbol;
		PlayerSymbol = GetCapitalLetter(PlayerSymbol); //  to ensure its capital.

	} while (PlayerSelectedInvalidSymbol(PlayerSymbol));

	return PlayerSymbol;
}

char GetComputerSymbol(char PlayerSymbol)
{
	if (PlayerSymbol == 'X')
		return 'O';
	else
		return 'X';
}

void PrintBoard(char Board[9])
{	
	system("cls");
	cout << " " << Board[0] << " | " << Board[1] << " | " << Board[2] << endl;
	cout << "-----------\n";
	cout << " " << Board[3] << " | " << Board[4] << " | " << Board[5] << endl;
	cout << "-----------\n";
	cout << " " << Board[6] << " | " << Board[7] << " | " << Board[8] << endl;

	// Also, i can say in a for loop from 1-5: 
	//		if it is an odd number:
	//			Print   |   |
	//      if it is an even number:
	//			Print -----------
}

bool InvalidPlaceSelected(char Board[9], short SelectedPlace)
{
	bool PlaceIsTaken = (Board[SelectedPlace] != ' ');
	bool PlaceNumberIsOutOfRange = (SelectedPlace < 0 || SelectedPlace > 8);

	return (PlaceIsTaken || PlaceNumberIsOutOfRange);
}

short AskPlayerWhereToPlay(char Board[9])
{
	short PlaceToPlayAt;

	do
	{
		cout << "You will play at (1-9): ";
		cin >> PlaceToPlayAt;
		PlaceToPlayAt--;

	} while (InvalidPlaceSelected(Board, PlaceToPlayAt));

	return PlaceToPlayAt;
}

short GetComputerPlace(char Board[9], short PlayerPlace)
{
	short ComputerPlace;

	do
		ComputerPlace = RandomNumber(0, 8);

	while (InvalidPlaceSelected(Board, ComputerPlace));

	return ComputerPlace;
}

void SetSymbolOnPlace(char Board[9], short WhereToPlay, char Symbol)
{
	Board[WhereToPlay] = Symbol;
}

bool AllPlacesAreFull(char Board[9])
{
	for (int i = 0; i < 9; i++)
	{
		if (Board[i] == ' ') // once it finds an empty place, it will return false.
			return false;
	}

	return true;
}

bool CheckHorizontalCase(char Board[9], char WinnerSymbol)
{
	for (int i = 0; i < 9; i += 3)
	{
		if (Board[i] == WinnerSymbol &&
			Board[i] == Board[i + 1] &&
			Board[i + 1] == Board[i + 2])
		{
			return true;
		}
	}

	return false;
}

bool CheckVerticalCase(char Board[9], char WinnerSymbol)
{
	for (int i = 0; i < 3; i++)
	{
		if (Board[i] == WinnerSymbol &&
			Board[i] == Board[i + 3] &&
			Board[i + 3] == Board[i + 6])
		{
			return true;
		}
	}

	return false;
}

bool CheckDiagonalCase(char Board[9], char WinnerSymbol)
{
	bool DiagonalCase1 = (
		Board[0] == WinnerSymbol &&
		Board[0] == Board[4] &&
		Board[4] == Board[8]
		);

	bool DiagonalCase2 = (
		Board[2] == WinnerSymbol &&
		Board[2] == Board[4] &&
		Board[4] == Board[6]
		);


	return (DiagonalCase1 || DiagonalCase2);
}

enWinner CheckTheWinner(stGameInfo GameInfo)
{
	bool ConditionMetForPlayer = false, ConditionMetForComputer = false;

	ConditionMetForPlayer = (
		CheckHorizontalCase(GameInfo.Board, GameInfo.PlayerSymbol) ||
		CheckVerticalCase(GameInfo.Board, GameInfo.PlayerSymbol) ||
		CheckDiagonalCase(GameInfo.Board, GameInfo.PlayerSymbol)
		);

	ConditionMetForComputer = (
		CheckHorizontalCase(GameInfo.Board, GameInfo.ComputerSymbol) ||
		CheckVerticalCase(GameInfo.Board, GameInfo.ComputerSymbol) ||
		CheckDiagonalCase(GameInfo.Board, GameInfo.ComputerSymbol)
		);

	if (ConditionMetForPlayer)
		return enWinner::Player;
	else if (ConditionMetForComputer)
		return enWinner::Computer;
	else
		return enWinner::Undetermined;
}

void PlayPlayerTurn(stGameInfo& GameInfo, short& PlayerPlace)
{
	PlayerPlace = AskPlayerWhereToPlay(GameInfo.Board);
	SetSymbolOnPlace(GameInfo.Board, PlayerPlace, GameInfo.PlayerSymbol);

	GameInfo.WhoPlayThisTurn = enWhoPlayThisTurn::ComputerTurn;
}

void PlayComputerTurn(stGameInfo& GameInfo, short& ComputerPlace, short PlayerPlace)
{
	ComputerPlace = GetComputerPlace(GameInfo.Board, PlayerPlace);
	SetSymbolOnPlace(GameInfo.Board, ComputerPlace, GameInfo.ComputerSymbol);

	GameInfo.WhoPlayThisTurn = enWhoPlayThisTurn::PlayerTurn;
}

void Play(stGameInfo& GameInfo)
{
	short PlayerPlace = 0, ComputerPlace = 0;

	PrintBoard(GameInfo.Board); // just to show it at the first time.

	while (GameInfo.Winner == enWinner::Undetermined)
	{
		switch (GameInfo.WhoPlayThisTurn)
		{
		case enWhoPlayThisTurn::PlayerTurn:
			PlayPlayerTurn(GameInfo, PlayerPlace);
			break;

		case enWhoPlayThisTurn::ComputerTurn:
			PlayComputerTurn(GameInfo, ComputerPlace, PlayerPlace);
			break;
		}

		PrintBoard(GameInfo.Board);

		GameInfo.Winner = CheckTheWinner(GameInfo);

		// If the winner is a certain one, the loop won't continue.
		// In contrast, if it is not determined and the board is
		// full, it'll be a draw.
		if (AllPlacesAreFull(GameInfo.Board) && GameInfo.Winner == enWinner::Undetermined)
		{
			GameInfo.Winner = enWinner::Draw;
			break;
		}
	}	
}

string GetWinnerText(enWinner Winner)
{
	string WinnerTextArray[3] = {"Player Wins!", "Computer Wins!", "Draw!"};

	return WinnerTextArray[Winner-1];
}

string GetCenteredText(string Text, short TotalLength)
{
	string Whitespaces = "";
	short TextLength = Text.length();
	short WhitespacesLength = (TotalLength - TextLength) / 2;

	for (int i = 1; i <= WhitespacesLength; i++)
		Whitespaces += " ";

	return Whitespaces + Text + Whitespaces;
}

void SetScreenColorForWinner(enWinner Winner)
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
		break;
	}
}

void ShowResults(stGameInfo GameInfo)
{
	cout << "\n----------------\n\n";
	cout << GetCenteredText(GetWinnerText(GameInfo.Winner), 17) << endl;
	cout << "\n----------------\n\n";
	
	SetScreenColorForWinner(GameInfo.Winner);
}

void PlayTicTacToe()
{
	stGameInfo GameInfo;

	GameInfo.PlayerSymbol = ReadPlayerSymbol();
	GameInfo.ComputerSymbol = GetComputerSymbol(GameInfo.PlayerSymbol);
	FillBoardWithEmptySpaces(GameInfo.Board); // so it is easier to print it at the first time.

	Play(GameInfo);
	
	ShowResults(GameInfo);
}

bool AskPlayerToPlayAgain()
{
	char PlayAgain;

	cout << "\nDo you want to play again (Y/N) ?: ";
	cin >> PlayAgain;

	PlayAgain = GetCapitalLetter(PlayAgain);

	return PlayAgain == 'Y';
}

void StartGame()
{
	do
	{ 
		ResetGame();
		PlayTicTacToe();

	} while (AskPlayerToPlayAgain());
}

int main()
{
	srand((unsigned)time(NULL));

	StartGame();

	return 0;
}

/*
What do you want to play as (X/O) ? x


   |   |
-----------
   |   |
-----------
   |   |

Play At (1-9): 5

   |   |
-----------
   | X |
-----------
   |   |

*Computer Plays*

   |   | O
-----------
   | X |
-----------
   |   |

*
* 
* 

----------------
  Player Wins!
----------------
*Screen Turns To Green
Or Red If Computer Wins
Otherwise, It Will Be
Yellow, Indicating It
Is A Draw*

*/