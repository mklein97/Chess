#pragma once
#include "Piece.hpp"

class Bishop : public Piece
{
public:
	Bishop(int r, int c, bool white, std::string imgpath)
		: Piece(r, c, white, imgpath) {}
	std::vector<Point> getValidMoves(const std::vector<Piece*>& allPieces);
	int getType();
};

