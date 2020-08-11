#include "stdafx.h"
#include "Pawn.hpp"

using namespace std;

vector<Point> Pawn::getValidMoves(const vector<Piece*>& allPieces)
{
	vector<Point> points;
	if (!getIsWhite())
	{
		//diagonal
		std::pair<bool, Piece*> pair = occupied(allPieces, row + 1, col + 1);
		if (pair.second && (pair.first && pair.second->getIsWhite() != getIsWhite()))
			points.push_back(Point(row + 1, col + 1));
		pair = occupied(allPieces, row + 1, col - 1);
		if (pair.second && (pair.first && pair.second->getIsWhite() != getIsWhite()))
			points.push_back(Point(row + 1, col - 1));

		//move forward 1
		if (!occupied(allPieces, row + 1, col).first)
			points.push_back(Point(row + 1, col));

		if (!hasMoved) 
		{
			//move forward 2
			if (!occupied(allPieces, row + 2, col).first && !occupied(allPieces, row + 1, col).first)
				points.push_back(Point(row + 2, col));
		}
		return points;
	}
	else
	{
		//diagonal
		std::pair<bool, Piece*> pair = occupied(allPieces, row - 1, col - 1);
		if (pair.second && (pair.first && pair.second->getIsWhite() != getIsWhite()))
			points.push_back(Point(row - 1, col - 1));
		pair = occupied(allPieces, row - 1, col + 1);
		if (pair.second && (pair.first && pair.second->getIsWhite() != getIsWhite()))
			points.push_back(Point(row - 1, col + 1));

		//move forward 1
		if (!occupied(allPieces, row - 1, col).first)
			points.push_back(Point(row - 1, col));

		if (!hasMoved)
		{
			//move forward 2
			if (!occupied(allPieces, row - 2, col).first && !occupied(allPieces, row - 1, col).first)
				points.push_back(Point(row - 2, col));
		}
		return points;
	}
}

int Pawn::getType()
{
	return 0;
}
