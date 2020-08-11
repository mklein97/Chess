#include "stdafx.h"
#include "Bishop.hpp"

using namespace std;

vector<Point> Bishop::getValidMoves(const vector<Piece*>& allPieces)
{
	vector<Point> points;
	int n = 0;
	//northeast
	for (int i = 1; i < 8; i++) 
	{
		std::pair<bool, Piece*> pair = occupied(allPieces, row + i, col + i);
		if (!pair.first || (pair.second && pair.second->getIsWhite() != getIsWhite()))
		{
			points.push_back(Point(row + i, col + i));
			if (pair.second && pair.second->getIsWhite() != getIsWhite())
				break;
		}
		else
			break;
	}
	//northwest
	for (int i = 1; i < 8; i++) 
	{
		std::pair<bool, Piece*> pair = occupied(allPieces, row + i, col - i);
		if (!pair.first || (pair.second && pair.second->getIsWhite() != getIsWhite()))
		{
			points.push_back(Point(row + i, col - i));
			if (pair.second && pair.second->getIsWhite() != getIsWhite())
				break;
		}
		else
			break;
	}
	//southeast
	for (int i = 1; i < 8; i++) 
	{
		std::pair<bool, Piece*> pair = occupied(allPieces, row - i, col + i);
		if (!pair.first || (pair.second && pair.second->getIsWhite() != getIsWhite()))
		{
			points.push_back(Point(row - i, col + i));
			if (pair.second && pair.second->getIsWhite() != getIsWhite())
				break;
		}
		else 
			break;
	}
	//southwest
	for (int i = 1; i < 8; i++) 
	{
		std::pair<bool, Piece*> pair = occupied(allPieces, row - i, col - i);
		if (!pair.first || (pair.second && pair.second->getIsWhite() != getIsWhite()))
		{
			points.push_back(Point(row - i, col - i));
			if (pair.second && pair.second->getIsWhite() != getIsWhite())
				break;
		}
		else
			break;
	}
	return points;
}

int Bishop::getType()
{
	return 3;
}
