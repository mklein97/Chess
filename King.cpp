#include "stdafx.h"
#include "King.hpp"
#include "Piece.hpp"
#include "Point.hpp"
#include <stdlib.h>
#include <vector>

using namespace std;

vector<Point> King::getValidMoves(const vector<Piece*>& allPieces)
{
	vector<Point> points;
	//forward
	std::pair<bool, Piece*> pair = occupied(allPieces, row + 1, col);
	if (!pair.first || (pair.second && pair.second->getIsWhite() != getIsWhite()))
		points.push_back(Point(row + 1, col));

	//forward & to right
	pair = occupied(allPieces, row + 1, col + 1);
	if (!pair.first || (pair.second && pair.second->getIsWhite() != getIsWhite()))
		points.push_back(Point(row + 1, col + 1));

	//to right
	pair = occupied(allPieces, row, col + 1);
	if (!pair.first || (pair.second && pair.second->getIsWhite() != getIsWhite()))
		points.push_back(Point(row, col + 1));

	//back and to right
	pair = occupied(allPieces, row - 1, col + 1);
	if (!pair.first || (pair.second && pair.second->getIsWhite() != getIsWhite()))
		points.push_back(Point(row - 1, col + 1));

	//back left
	pair = occupied(allPieces, row - 1, col - 1);
	if (!pair.first || (pair.second && pair.second->getIsWhite() != getIsWhite()))
		points.push_back(Point(row - 1, col - 1));

	//back
	pair = occupied(allPieces, row - 1, col);
	if (!pair.first || (pair.second && pair.second->getIsWhite() != getIsWhite()))
		points.push_back(Point(row - 1, col));

	//left
	pair = occupied(allPieces, row, col - 1);
	if (!pair.first || (pair.second && pair.second->getIsWhite() != getIsWhite()))
		points.push_back(Point(row, col - 1));

	//forward left
	pair = occupied(allPieces, row + 1, col - 1);
	if (!pair.first || (pair.second && pair.second->getIsWhite() != getIsWhite()))
		points.push_back(Point(row + 1, col - 1));
	return points;
}

int King::getType()
{
	return 5;
}
