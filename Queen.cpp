#include "stdafx.h"
#include "Queen.hpp"
#include "Point.hpp"

using namespace std;

vector<Point> Queen::getValidMoves(const vector<Piece*>& allPieces)
{
	vector<Point> points;
	//forwards
	for (int i = 1; i < 8; i++) 
	{
		std::pair<bool, Piece*> pair = occupied(allPieces, row + i, col);
		if (!pair.first || (pair.second && pair.second->getIsWhite() != getIsWhite()))
		{
			points.push_back(Point(row + i, col));
			if (pair.second && pair.second->getIsWhite() != getIsWhite())
				break;
		}
		else 
			break;
	}
	//backwards
	for (int i = 1; i < 8; i++) 
	{
		std::pair<bool, Piece*> pair = occupied(allPieces, row - i, col);
		if (!pair.first || (pair.second && pair.second->getIsWhite() != getIsWhite()))
		{
			points.push_back(Point(row - i, col));
			if (pair.second && pair.second->getIsWhite() != getIsWhite())
				break;
		}
		else
			break;
	}
	//leftwards
	for (int i = 1; i < 8; i++) 
	{
		std::pair<bool, Piece*> pair = occupied(allPieces, row, col - i);
		if (!pair.first || (pair.second && pair.second->getIsWhite() != getIsWhite()))
		{
			points.push_back(Point(row, col - i));
			if (pair.second && pair.second->getIsWhite() != getIsWhite())
				break;
		}
		else
			break;
	}
	//rightwards
	for (int i = 1; i < 8; i++) 
	{
		std::pair<bool, Piece*> pair = occupied(allPieces, row, col + i);
		if (!pair.first || (pair.second && pair.second->getIsWhite() != getIsWhite()))
		{
			points.push_back(Point(row, col + i));
			if (pair.second && pair.second->getIsWhite() != getIsWhite())
				break;
		}
		else
			break;
	}
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

int Queen::getType()
{
	return 4;
}
