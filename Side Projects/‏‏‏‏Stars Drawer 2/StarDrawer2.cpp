#include <iostream>
#include "MyInputLib.h"
using namespace std;

// a huge number the program wouldn't reach anyway. As i need
// to skip some values, i can hide them through this number.
const short HIDING_VALUE = 30000;

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
		return StarScale * 1;
	default:
		return 0;
	}
}

short GetDiagonalEndingPoint(short StarScale, enDiagonalSide DiagonalSide)
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

short GetLowestYPoint(stStarDrawing& StarDrawing)
{
	short LowestY = HIDING_VALUE;

	for (short Point = 0; Point < StarDrawing.NumberOfPoints; Point++)
	{
		if (StarDrawing.PointsCoordinates[Point][0] < LowestY)
			LowestY = StarDrawing.PointsCoordinates[Point][0];
	}

	return LowestY;
}

short GetLowestXAccordingToY2(stStarDrawing& StarDrawing, short Y)
{
	short LowestX = HIDING_VALUE;
	bool IsSameYLevel;

	for (short Point = 0; Point < StarDrawing.NumberOfPoints; Point++)
	{
		IsSameYLevel = StarDrawing.PointsCoordinates[Point][0] == Y;

		if (IsSameYLevel && StarDrawing.PointsCoordinates[Point][1] < LowestX)
			LowestX = StarDrawing.PointsCoordinates[Point][1];
	}

	return LowestX;
}

void HideTakenPoint(stStarDrawing& StarDrawing, short TempPoint[2])
{
	bool IsSameYValue, IsSameXValue;

	for (short i = 0; i < StarDrawing.NumberOfPoints; i++)
	{
		IsSameYValue = StarDrawing.PointsCoordinates[i][0] == TempPoint[0];
		IsSameXValue = StarDrawing.PointsCoordinates[i][1] == TempPoint[1];

		if (IsSameYValue && IsSameXValue)
		{
			StarDrawing.PointsCoordinates[i][0] = HIDING_VALUE;
			StarDrawing.PointsCoordinates[i][1] = HIDING_VALUE;
		}
	}
}

void AssignAllPointsInCurrentYLevel(stStarDrawing& StarDrawing, short TempPoint[2], short OrderedPointsCoordinates[1024][2], short CurrentPoint)
{
	while (true)
	{
		TempPoint[1] = GetLowestXAccordingToY2(StarDrawing, TempPoint[0]);

		if (TempPoint[1] == HIDING_VALUE) // meaning it didn't change -> all are taken.
			break;

		HideTakenPoint(StarDrawing, TempPoint); // to skip it.

		OrderedPointsCoordinates[CurrentPoint][0] = TempPoint[0];
		OrderedPointsCoordinates[CurrentPoint][1] = TempPoint[1];
	}
}

void FillPointsCoordinatesWithOrder(stStarDrawing& StarDrawing, short OrderedPointsCoordinates[1024][2])
{
	short TempPoint[2];

	for (short Point = 0; Point < StarDrawing.NumberOfPoints; Point++)
	{
		TempPoint[0] = GetLowestYPoint(StarDrawing);

		if (TempPoint[0] == HIDING_VALUE) // it is already taken.
			continue;
		else
			AssignAllPointsInCurrentYLevel(StarDrawing, TempPoint, OrderedPointsCoordinates, Point);
	}
}

void CopyOrderedPointsCoordinates(stStarDrawing& StarDrawing, short OrderedPointsCoordinates[1024][2])
{
	for (short Point = 0; Point < StarDrawing.NumberOfPoints; Point++)
	{
		StarDrawing.PointsCoordinates[Point][0] = OrderedPointsCoordinates[Point][0];
		StarDrawing.PointsCoordinates[Point][1] = OrderedPointsCoordinates[Point][1];
	}
}

void OrderPointsCoordinates(stStarDrawing& StarDrawing)
{
	short OrderedPointsCoordinates[1024][2];

	FillPointsCoordinatesWithOrder(StarDrawing, OrderedPointsCoordinates);
	CopyOrderedPointsCoordinates(StarDrawing, OrderedPointsCoordinates);
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
	// although it is maximized with 256, it can be easily go beyond,
	// but with a greater usage of memory of course.

	return 0;
}