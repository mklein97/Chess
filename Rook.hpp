#pragma once
#include "Piece.hpp"
class Rook : public Piece
{
public:
	Rook(int r, int c, bool white, std::string imgpath)
		: Piece(r, c, white, imgpath) {}
	std::vector<Point> getValidMoves(const std::vector<Piece*>& allPieces);
	int getType();
};

