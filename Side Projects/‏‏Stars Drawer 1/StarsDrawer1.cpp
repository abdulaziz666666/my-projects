#include <iostream>
#include "MyInputLib.h"
using namespace std;

enum enDiagonalSide { Left, Right };

struct stStarDrawing
{
	int Scale;
	//int PointsCoordinates[1024][2];
	char PointsMap[100][100];
};

void FillHorizontalLineCoords(stStarDrawing& StarDrawing)
{
	const int Y = StarDrawing.Scale / 2;

	for (int x = 0; x < StarDrawing.Scale; x++)
		StarDrawing.PointsMap[Y][x] = '*';
}

void FillVerticalLineCoords(stStarDrawing& StarDrawing)
{
	const int X = StarDrawing.Scale / 2;

	for (int y = 0; y < StarDrawing.Scale; y++)
		StarDrawing.PointsMap[y][X] = '*';
}

int GetDiagonalStartingPoint(int StarScale, enDiagonalSide DiagonalSide)
{
	switch (DiagonalSide)
	{
	case enDiagonalSide::Left:
		return 0;
	case enDiagonalSide::Right:
		return StarScale * 1;
	default:
		return 0;
	}
}

int GetDiagonalEndingPoint(int StarScale, enDiagonalSide DiagonalSide)
{
	switch (DiagonalSide)
	{
	case enDiagonalSide::Left:
		return StarScale * 1;
	case enDiagonalSide::Right:
		return 0;
	default:
		return 0;
	}
}

void FillRightDiagonalLine(stStarDrawing& StarDrawing)
{
	int x = StarDrawing.Scale - 1;

	for (int y = 0; y < StarDrawing.Scale; y++)
	{
		StarDrawing.PointsMap[y][x] = '*';
		x--;
	}
}

void FillLeftDiagonalLine(stStarDrawing& StarDrawing)
{
	for (int DiagonalStep = 0; DiagonalStep < StarDrawing.Scale; DiagonalStep++)
		StarDrawing.PointsMap[DiagonalStep][DiagonalStep] = '*';
}

void FillDiagonalLineCoords(stStarDrawing& StarDrawing, enDiagonalSide DiagonalSide)
{
	switch (DiagonalSide)
	{
	case enDiagonalSide::Left:
		FillLeftDiagonalLine(StarDrawing);
		break;

	case enDiagonalSide::Right:
		FillRightDiagonalLine(StarDrawing);
	}
}

void FillStarPointsCoordinates(stStarDrawing& StarDrawing)
{
	FillHorizontalLineCoords(StarDrawing);
	FillVerticalLineCoords(StarDrawing);
	FillDiagonalLineCoords(StarDrawing, enDiagonalSide::Left);
	FillDiagonalLineCoords(StarDrawing, enDiagonalSide::Right);
}

void RepresentStar(stStarDrawing& StarDrawing)
{
	for (int y = 0; y < StarDrawing.Scale; y++)
	{
		for (int x = 0; x < StarDrawing.Scale; x++)
		{
			if (StarDrawing.PointsMap[y][x] == '*')
				cout << '*';
			else
				cout << ' ';
		}
		cout << endl;
	}
}

void StartProgram()
{
	stStarDrawing StarDrawing;

	StarDrawing.Scale = MyInputLib::ReadNumberInRange(1, 100);
	FillStarPointsCoordinates(StarDrawing);
	RepresentStar(StarDrawing);
}

int main()
{
	StartProgram();

	// My new goal is to optimize that program..
	// i'm acknowleged it is really bad in terms of optimization, 
	// but i promise i will make it capable of drawing a 1000-chars 
	// star without any problems. That could be done by printing
	// its points through coordinates, not by char arrays.

	return 0;
}