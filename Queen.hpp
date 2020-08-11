#pragma once
#include <vector>
#include "Piece.hpp"

class Queen : public Piece
{
public:
	Queen(int r, int c, bool white, std::string imgpath)
		: Piece(r, c, white, imgpath) {}
	std::vector<Point> getValidMoves(const std::vector<Piece*>& allPieces);
	int getType();
};

