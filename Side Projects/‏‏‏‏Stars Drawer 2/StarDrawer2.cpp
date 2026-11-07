#include <iostream>
#include "MyInputLib.h"
using namespace std;

enum enDiagonalSide { Left, Right };

struct stStarDrawing
{
	short Scale;
	short PointsCoordinates[1024][2];
	short NumberOfPoints = 0;
};

void FillHorizontalLineCoords(stStarDrawing& StarDrawing)
{
	const short Y = StarDrawing.Scale / 2;

	for (short x = 0; x < StarDrawing.Scale; x++)
	{
		StarDrawing.PointsCoordinates[StarDrawing.NumberOfPoints][0] = Y;
		StarDrawing.PointsCoordinates[StarDrawing.NumberOfPoints][1] = x;
		StarDrawing.NumberOfPoints++;
	}
}

void FillVerticalLineCoords(stStarDrawing& StarDrawing)
{
	const short X = StarDrawing.Scale / 2;

	for (short y = 0; y < StarDrawing.Scale; y++)
	{
		StarDrawing.PointsCoordinates[StarDrawing.NumberOfPoints][0] = y;
		StarDrawing.PointsCoordinates[StarDrawing.NumberOfPoints][1] = X;
		StarDrawing.NumberOfPoints++;
	}
}

short GetDiagonalStartingPoint(short StarScale, enDiagonalSide DiagonalSide)
{
	switch (DiagonalSide)
	{
	case enDiagonalSide::Left:
		return 0;
	case enDiagonalSide::Right:
		return StarScale;
	default:
		return 0;
	}
}

short GetDiagonalEndingPoint(short StarScale, enDiagonalSide DiagonalSide)
{
	switch (DiagonalSide)
	{
	case enDiagonalSide::Left:
		return StarScale;
	case enDiagonalSide::Right:
		return 0;
	default:
		return 0;
	}
}

void FillRightDiagonalLine(stStarDrawing& StarDrawing)
{
	short x = StarDrawing.Scale - 1;

	for (short y = 0; y < StarDrawing.Scale; y++)
	{
		StarDrawing.PointsCoordinates[StarDrawing.NumberOfPoints][0] = y;
		StarDrawing.PointsCoordinates[StarDrawing.NumberOfPoints][1] = x;
		x--;
		StarDrawing.NumberOfPoints++;
	}
}

void FillLeftDiagonalLine(stStarDrawing& StarDrawing)
{
	for (short DiagonalStep = 0; DiagonalStep < StarDrawing.Scale; DiagonalStep++)
	{
		StarDrawing.PointsCoordinates[StarDrawing.NumberOfPoints][0] = DiagonalStep;
		StarDrawing.PointsCoordinates[StarDrawing.NumberOfPoints][1] = DiagonalStep;
		StarDrawing.NumberOfPoints++;
	}
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


void PrintPointIfPositionMatches(stStarDrawing& StarDrawing, short x, short y)
{
	bool IsSameYValue = 0, IsSameXValue = 0;

	for (int i = 0; i < StarDrawing.NumberOfPoints; i++)
	{
		IsSameYValue = StarDrawing.PointsCoordinates[i][0] == y;
		IsSameXValue = StarDrawing.PointsCoordinates[i][1] == x;

		if (IsSameYValue && IsSameXValue)
			break;
	}

	if (IsSameYValue && IsSameXValue)
		cout << "*";
	else
		cout << " ";
}

void RepresentStar(stStarDrawing& StarDrawing)
{
	// As i didn't observe a way to print points according to its
	// coordinates, i asked an AI tool. Now i've learned a new thing.
	for (short y = 0; y < StarDrawing.Scale; y++)
	{
		for (short x = 0; x < StarDrawing.Scale; x++)
			PrintPointIfPositionMatches(StarDrawing, x, y);

		cout << endl;
	}
}

void StartProgram()
{
	stStarDrawing StarDrawing;

	StarDrawing.Scale = MyInputLib::ReadNumberInRange(1, 256);
	FillStarPointsCoordinates(StarDrawing);

	RepresentStar(StarDrawing);
}

int main()
{
	StartProgram();
	// although it is maximized with 256, it can easily go beyond,
	// but with a greater usage of memory of course.

	return 0;
}