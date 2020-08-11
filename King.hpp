#pragma once
#include "Piece.hpp"

class King : public Piece
{
public:
	King(int r, int c, bool white, std::string imgpath)
		: Piece(r, c, white, imgpath) {}
	std::vector<Point> getValidMoves(const std::vector<Piece*>& allPieces);
	int getType();
};

