#pragma once
#include <stdlib.h>
#include <vector>
#include <string>
#include <tuple>
#include "Point.hpp"
#include "SFML/Graphics.hpp"

class Piece
{
public:
	Piece();
	Piece(int r, int c, bool white, std::string imgpath);
	virtual ~Piece();
	int getColumn();
	int getRow();
	void setPosition(int r, int c);
	bool getIsWhite();
	sf::Sprite getSprite();
	void select();
	bool isSelected();
	std::pair<bool, Piece*> occupied(const std::vector<Piece*>& allPieces, int row, int col);
	bool makeMove(sf::Vector2i mPosition, std::vector<Piece*>& allPieces);
	void draw(sf::RenderWindow& rw);
	virtual std::vector<Point> getValidMoves(const std::vector<Piece*>& allPieces);
	virtual int getType();
protected:
	int col, row;
	bool hasMoved;
	bool isWhite;
	bool selected = false;
	sf::Texture tex;
	sf::Sprite sprite;
};

