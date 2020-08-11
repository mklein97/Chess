#include "stdafx.h"
#include "Knight.hpp"

using namespace std;

vector<Point> Knight::getValidMoves(const vector<Piece*>& allPieces)
{
	vector<Point> points;
	//point1
	std::pair<bool, Piece*> pair = occupied(allPieces, row + 2, col - 1);
	if (!pair.first || (pair.second && pair.second->getIsWhite() != getIsWhite()))
		points.push_back(Point(row + 2, col - 1));

	//point2
	pair = occupied(allPieces, row + 2, col + 1);
	if (!pair.first || (pair.second && pair.second->getIsWhite() != getIsWhite()))
		points.push_back(Point(row + 2, col + 1));

	//point3
	pair = occupied(allPieces, row + 1, col + 2);
	if (!pair.first || (pair.second && pair.second->getIsWhite() != getIsWhite()))
		points.push_back(Point(row + 1, col + 2));

	//point4
	pair = occupied(allPieces, row - 1, col + 2);
	if (!pair.first || (pair.second && pair.second->getIsWhite() != getIsWhite()))
		points.push_back(Point(row - 1, col + 2));

	//point5
	pair = occupied(allPieces, row - 2, col + 1);
	if (!pair.first || (pair.second && pair.second->getIsWhite() != getIsWhite()))
		points.push_back(Point(row - 2, col + 1));

	//point6
	pair = occupied(allPieces, row - 2, col + 1);
	if (!pair.first || (pair.second && pair.second->getIsWhite() != getIsWhite()))
		points.push_back(Point(row - 2, col - 1));

	//point7
	pair = occupied(allPieces, row - 1, col - 2);
	if (!pair.first || (pair.second && pair.second->getIsWhite() != getIsWhite()))
		points.push_back(Point(row - 1, col - 2));

	//point8
	pair = occupied(allPieces, row + 1, col - 2);
	if (!pair.first || (pair.second && pair.second->getIsWhite() != getIsWhite()))
		points.push_back(Point(row + 1, col - 2));
	return points;
}

int Knight::getType()
{
	return 2;
}
