#include "stdafx.h"
#include "Piece.hpp"
#include <stdlib.h>
#include <vector>
#include "Point.hpp"

using namespace std;

Piece::Piece(){}

Piece::Piece(int r, int c, bool white, std::string imgpath)
{
	row = r;
	col = c;
	isWhite = white;
	tex.loadFromFile(imgpath);
	hasMoved = false;
}


Piece::~Piece()
{

}

int Piece::getColumn()
{
	return col;
}

int Piece::getRow()
{
	return row;
}

void Piece::setPosition(int r, int c)
{
	row = r;
	col = c;
}

bool Piece::getIsWhite()
{
	return isWhite;
}

sf::Sprite Piece::getSprite()
{
	return sprite;
}

void Piece::select()
{
	selected = !selected;
}

bool Piece::isSelected()
{
	return selected;
}

std::pair<bool, Piece*> Piece::occupied(const std::vector<Piece*>& allPieces, int row, int col)
{
	if (row < 0 || row > 8 || col < 0 || col > 8) 
		return std::make_pair(true, static_cast<Piece*>(NULL));
	for (Piece* p : allPieces) 
	{
		if (p->getRow() == row && p->getColumn() == col) 
			return std::make_pair(true, p);
	}
	return std::make_pair(false, static_cast<Piece*>(NULL));
}

bool Piece::makeMove(sf::Vector2i mPosition, vector<Piece*>& allPieces)
{
	int nrow, ncol;
	if (mPosition.x <= 50 && mPosition.x >= 0)
		ncol = 1;
	if (mPosition.x <= 100 && mPosition.x >= 50)
		ncol = 2;
	if (mPosition.x <= 150 && mPosition.x >= 100)
		ncol = 3;
	if (mPosition.x <= 200 && mPosition.x >= 150)
		ncol = 4;
	if (mPosition.x <= 250 && mPosition.x >= 200)
		ncol = 5;
	if (mPosition.x <= 300 && mPosition.x >= 250)
		ncol = 6;
	if (mPosition.x <= 350 && mPosition.x >= 300)
		ncol = 7;
	if (mPosition.x <= 400 && mPosition.x >= 350)
		ncol = 8;
	if (mPosition.y <= 50 && mPosition.y >= 0)
		nrow = 1;
	if (mPosition.y <= 100 && mPosition.y >= 50)
		nrow = 2;
	if (mPosition.y <= 150 && mPosition.y >= 100)
		nrow = 3;
	if (mPosition.y <= 200 && mPosition.y >= 150)
		nrow = 4;
	if (mPosition.y <= 250 && mPosition.y >= 200)
		nrow = 5;
	if (mPosition.y <= 300 && mPosition.y >= 250)
		nrow = 6;
	if (mPosition.y <= 350 && mPosition.y >= 300)
		nrow = 7;
	if (mPosition.y <= 400 && mPosition.y >= 350)
		nrow = 8;
	vector<Point> points = getValidMoves(allPieces);
	if (points.size() == 0)
		return false;
	bool valid_move = false;
	for (Point p : points) 
	{
		if (p.row == nrow && p.col == ncol) 
		{
			valid_move = true;
			break;
		}
	}
	if (valid_move)
	{
		row = nrow;
		col = ncol;
		hasMoved = true;
		for (unsigned int i = 0; i < allPieces.size(); i++)
		{
			if (allPieces[i]->getIsWhite() != getIsWhite() && allPieces[i]->row == row && allPieces[i]->col == col)
				allPieces.erase(allPieces.begin() + i);
		}
		return true;
	}
	else
		return false;
}

void Piece::draw(sf::RenderWindow& rw)
{
	sprite.setPosition(sf::Vector2f((col * 50.0) - 50.0, (row * 50.0) - 50.0));
	tex.setSmooth(true);
	sprite.setTexture(tex, true);
	rw.draw(sprite);
}

vector<Point> Piece::getValidMoves(const vector<Piece*>& allPieces)
{
	return vector<Point>();
}

int Piece::getType()
{
	return 0;
}
