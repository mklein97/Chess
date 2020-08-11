#pragma once
#include "Piece.hpp"
class Pawn : public Piece
{
public:
	Pawn(int r, int c, bool white, std::string imgpath)
		: Piece(r, c, white, imgpath) {}
	std::vector<Point> getValidMoves(const std::vector<Piece*>& allPieces);
	int getType();
};

