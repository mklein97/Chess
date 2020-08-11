#pragma once
#include "stdafx.h"
#include "SFML/Graphics.hpp"
#include <algorithm>

void drawBoard(sf::RenderWindow& rw)
{
	sf::RectangleShape rect;
	rect.setSize(sf::Vector2f(50.0, 50.0));
	sf::Color c1(242, 218, 155), c2(145, 117, 79);
	rect.setOrigin(sf::Vector2f(0, 0));
	bool light = true;
	float x = 0, y = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			switch (light) {
			case(true):
				rect.setFillColor(c1);
				light = false;
				break;
			case(false):
				rect.setFillColor(c2);
				light = true;
				break;
			}
			rect.setPosition(x, y);
			x += 50;
			rw.draw(rect);
		}
		y += 50;
		x = 0;
		light = !light;
	}
}

std::vector<Piece*> initPieces()
{
	std::vector<Piece*> pieces;

	//black pieces
	for (int i = 1; i <= 8; i++)
		pieces.push_back(new Pawn(2, i, false, "sprites/blackPawn.png"));
	pieces.push_back(new Rook(1, 1, false, "sprites/blackRook.png"));
	pieces.push_back(new Rook(1, 8, false, "sprites/blackRook.png"));
	pieces.push_back(new Knight(1, 2, false, "sprites/blackKnight.png"));
	pieces.push_back(new Knight(1, 7, false, "sprites/blackKnight.png"));
	pieces.push_back(new Bishop(1, 3, false, "sprites/blackBishop.png"));
	pieces.push_back(new Bishop(1, 6, false, "sprites/blackBishop.png"));
	pieces.push_back(new Queen(1, 4, false, "sprites/blackQueen.png"));
	pieces.push_back(new King(1, 5, false, "sprites/blackKing.png"));

	//white pieces
	for (int i = 1; i <= 8; i++)
		pieces.push_back(new Pawn(7, i, true, "sprites/whitePawn.png"));
	pieces.push_back(new Rook(8, 1, true, "sprites/whiteRook.png"));
	pieces.push_back(new Rook(8, 8, true, "sprites/whiteRook.png"));
	pieces.push_back(new Knight(8, 2, true, "sprites/whiteKnight.png"));
	pieces.push_back(new Knight(8, 7, true, "sprites/whiteKnight.png"));
	pieces.push_back(new Bishop(8, 3, true, "sprites/whiteBishop.png"));
	pieces.push_back(new Bishop(8, 6, true, "sprites/whiteBishop.png"));
	pieces.push_back(new Queen(8, 4, true, "sprites/whiteQueen.png"));
	pieces.push_back(new King(8, 5, true, "sprites/whiteKing.png"));

	return pieces;
}

void promotePawn(std::vector<Piece*>& allPieces, Piece* pawn, int type)
{
	
	if (pawn->getType() != tPawn)
		std::cout << "Attempted promoted piece is not a Pawn!" << std::endl;
	else
	{
		std::vector<Piece*>::iterator iter = std::find(allPieces.begin(), allPieces.end(), pawn);
		if (iter != allPieces.end())
		{
			allPieces.erase(iter);
			switch (type)
			{
			case tQueen:
				if (pawn->getIsWhite())
					allPieces.push_back(new Queen(pawn->getRow(), pawn->getColumn(), pawn->getIsWhite(), "sprites/whiteQueen.png"));
				if (!pawn->getIsWhite())
					allPieces.push_back(new Queen(pawn->getRow(), pawn->getColumn(), pawn->getIsWhite(), "sprites/blackQueen.png"));
				break;
			case tBishop:
				if (pawn->getIsWhite())
					allPieces.push_back(new Bishop(pawn->getRow(), pawn->getColumn(), pawn->getIsWhite(), "sprites/whiteBishop.png"));
				if (!pawn->getIsWhite())
					allPieces.push_back(new Bishop(pawn->getRow(), pawn->getColumn(), pawn->getIsWhite(), "sprites/blackBishop.png"));
				break;
			case tRook:
				if (pawn->getIsWhite())
					allPieces.push_back(new Rook(pawn->getRow(), pawn->getColumn(), pawn->getIsWhite(), "sprites/whiteRook.png"));
				if (!pawn->getIsWhite())
					allPieces.push_back(new Rook(pawn ->getRow(), pawn->getColumn(), pawn->getIsWhite(), "sprites/blackRook.png"));
				break;
			case tKnight:
				if (pawn->getIsWhite())
					allPieces.push_back(new Knight(pawn->getRow(), pawn->getColumn(), pawn->getIsWhite(), "sprites/whiteKnight.png"));
				if (!pawn->getIsWhite())
					allPieces.push_back(new Knight(pawn->getRow(), pawn->getColumn(), pawn->getIsWhite(), "sprites/blackKnight.png"));
				break;
			}
		}
	}
}