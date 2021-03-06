#include "stdafx.h"
#include "board.hpp"
#include "Piece.hpp"
#include "PGNParser.hpp"

int main(int argc, char** argv)
{
	bool whiteTurn = true;
	bool promoting = false;
	sf::RenderWindow renderWindow(sf::VideoMode(400, 400), "Chess++");
	sf::Event event;
	vector<Piece*> pieces = initPieces();
	sf::RectangleShape sSquare(sf::Vector2f(50, 50));
	sSquare.setFillColor(sf::Color::Transparent);
	sSquare.setOutlineThickness(7);
	sSquare.setOutlineColor(sf::Color::Cyan);
	sf::CircleShape mCirc(15);
	mCirc.setFillColor(sf::Color::Red);
	sf::Texture proTex;
	proTex.loadFromFile("sprites/promoted.png");
	sf::Sprite proMessage;
	proMessage.setTexture(proTex);
	proMessage.setScale(0.5, 0.5);

	/*string filename;
	cout << "Please enter the name of PGN file to be played: " << endl;
	getline(cin, filename);
	PGNParser pp(filename);*/

	while (renderWindow.isOpen())
	{
		sf::Vector2i mPosition = sf::Mouse::getPosition();
		// Check for all the events that occured since the last frame.
		while (renderWindow.pollEvent(event))
		{
			//Handle events here
			if (event.type == sf::Event::EventType::Closed)
				renderWindow.close();
			if (event.type == sf::Event::EventType::KeyPressed) 
			{
				if (event.key.code == sf::Keyboard::Escape)
					renderWindow.close();
				if (promoting)
				{
					for (Piece* p : pieces)
					{
						if ((p->getIsWhite() && p->getType() == tPawn && p->getRow() == 1) ||
							(!p->getIsWhite() && p->getType() == tPawn && p->getRow() == 8))
						{
							switch (event.key.code)
							{
							case sf::Keyboard::Num1:
								promotePawn(pieces, p, tQueen);
								promoting = false;
								break;
							case sf::Keyboard::Num2:
								promotePawn(pieces, p, tKnight);
								promoting = false;
								break;
							case sf::Keyboard::Num3:
								promotePawn(pieces, p, tRook);
								promoting = false;
								break;
							case sf::Keyboard::Num4:
								promotePawn(pieces, p, tBishop);
								promoting = false;
								break;
							}
						}
					}
				}
				if (event.key.code == sf::Keyboard::K)
				{
					int num = 0;
					for (Piece* p : pieces)
					{
						if (p->getIsWhite() == whiteTurn)
						{
							if (whiteTurn)
							{
								if (p->getType() == tRook && (p->getRow() == 8 && p->getColumn() == 8))
								{
									if (!p->occupied(pieces, 8, 7).first && !p->occupied(pieces, 8, 6).first)
									{
										p->setPosition(8, 6);
										num += 1;
									}
								}
								if (p->getType() == tKing && (p->getRow() == 8 && p->getColumn() == 5))
								{
									if (!p->occupied(pieces, 8, 7).first)
									{
										p->setPosition(8, 7);
										num += 1;
									}
								}
							}
							else
							{
								if (p->getType() == tRook && (p->getRow() == 1 && p->getColumn() == 8))
								{
									if (!p->occupied(pieces, 1, 7).first && !p->occupied(pieces, 1, 6).first)
									{
										p->setPosition(1, 6);
										num += 1;
									}
								}
								if (p->getType() == tKing && (p->getRow() == 1 && p->getColumn() == 5))
								{
									if (!p->occupied(pieces, 1, 7).first)
									{
										p->setPosition(1, 7);
										num += 1;
									}
								}
							}
						}
					}
					if (num == 2)
						whiteTurn = !whiteTurn;
				}
				if (event.key.code == sf::Keyboard::Q)
				{
					int num = 0;
					for (Piece* p : pieces)
					{
						if (p->getIsWhite() == whiteTurn)
						{
							if (whiteTurn)
							{
								if (p->getType() == tRook && (p->getRow() == 8 && p->getColumn() == 1))
								{
									if (!p->occupied(pieces, 8, 2).first && !p->occupied(pieces, 8, 3).first && !p->occupied(pieces, 8, 4).first)
									{
										p->setPosition(8, 4);
										num += 1;
									}
								}
								if (p->getType() == tKing && (p->getRow() == 8 && p->getColumn() == 5))
								{
									if (!p->occupied(pieces, 8, 3).first)
									{
										p->setPosition(8, 3);
										num += 1;
									}
								}
							}
							else
							{
								if (p->getType() == tRook && (p->getRow() == 1 && p->getColumn() == 1))
								{
									if (!p->occupied(pieces, 1, 2).first && !p->occupied(pieces, 1, 3).first && !p->occupied(pieces, 1, 4).first)
									{
										p->setPosition(1, 4);
										num += 1;
									}
								}
								if (p->getType() == tKing && (p->getRow() == 1 && p->getColumn() == 5))
								{
									if (!p->occupied(pieces, 1, 3).first)
									{
										p->setPosition(1, 3);
										num += 1;
									}
								}
							}
						}
					}
					if (num == 2)
						whiteTurn = !whiteTurn;
				}
			}
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					for (Piece* p : pieces)
					{
						if (p->getSprite().getGlobalBounds().contains(renderWindow.mapPixelToCoords(sf::Mouse::getPosition(renderWindow)))
							&& p->getIsWhite() == whiteTurn)
						{
							for (Piece* p2 : pieces)
							{
								if (p2->isSelected())
									p2->select();
							}
							p->select();
							sSquare.setPosition(sf::Vector2f((p->getColumn() * 50) - 50, (p->getRow() * 50) - 50));
						}
						if (p->isSelected() && p->getIsWhite() == whiteTurn && p->makeMove(sf::Mouse::getPosition(renderWindow), pieces))
						{
							p->makeMove(sf::Mouse::getPosition(renderWindow), pieces);
							p->select();
							whiteTurn = !whiteTurn;
						}
						if ((p->getIsWhite() && p->getType() == tPawn && p->getRow() == 1) ||
							(!p->getIsWhite() && p->getType() == tPawn && p->getRow() == 8))
							promoting = true;
					}
				}
			}
		}
		renderWindow.clear(sf::Color::Black);
		drawBoard(renderWindow);
		for (Piece* p : pieces)
		{
			p->draw(renderWindow);
			if (p->isSelected())
			{
				renderWindow.draw(sSquare);
				for (Point point : p->getValidMoves(pieces))
				{
					mCirc.setPosition(sf::Vector2f((point.col * 50) - 40, (point.row * 50) - 40));
					renderWindow.draw(mCirc);
				}
			}
		}
		if (promoting)
			renderWindow.draw(proMessage);
		renderWindow.display();
	}
	for (Piece* p : pieces)
		delete p;
}
