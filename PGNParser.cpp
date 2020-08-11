#include "stdafx.h"
#include "PGNParser.hpp"
#include <iostream>
#include <fstream>
#include <ctype.h>

using namespace std;

PGNParser::PGNParser()
{

}

PGNParser::PGNParser(const std::string& filename)
{
	open(filename);
}


PGNParser::~PGNParser()
{
	close();
}

void PGNParser::open(const std::string& filename)
{
	myFile.open(filename, ios::in);
}

void PGNParser::close()
{
	if (getIsOpen())
		myFile.close();
}

bool PGNParser::getIsOpen() const
{
	return myFile.is_open();
}

Move PGNParser::getMove()
{
	while (!myFile.eof() && myLine.length() == 0)
	{
		getline(myFile, myLine);
		it = myLine.begin();
	}
		  
	if (myLine.front() == '[')
	{
		std::string tmp = myLine;
		myLine = "";
		return Move(tmp, -1, 0, 0, 0, false);
	}

	if (myLine.substr(0, 2) == "  ")
		return Move("Game Over", 0, 0, 0, 0, false);

	size_t p = myLine.find_first_of(' ');
	std::string curMove = myLine.substr(0, p);
	if (p == std::string::npos)
		myLine = "";
	else
		myLine = myLine.substr(p + 1, std::string::npos);

	bool isWhite;
	int pType = 0;
	if ((p = curMove.find('.')) != std::string::npos)
	{
		isWhite = true;
		curMove.erase(0, p + 1);
	}
	else
		isWhite = false;

	if (curMove.front() == 'O')
		curMove.erase(0, 2);

	if (isupper(curMove.front()))
	{
		switch (curMove.front())
		{
		case 'N':
			pType = tKnight;
			break;
		case 'K':
			pType = tKing;
			break;
		case 'Q':
			pType = tQueen;
			break;
		case 'B':
			pType = tBishop;
			break;
		case 'R':
			pType = tRook;
			break;
		case 'P':
			pType = tPawn;
			break;
		}
		curMove.erase(0, 1);
	}
	else
		pType = tPawn;

	if ((p = curMove.find('x')) != std::string::npos)
		curMove.erase(0, p + 1);

	int dCol = 0;
	if (curMove.length() == 3)
	{
		if (curMove.back() != '+' && curMove.back() != '#')
		{
			switch (curMove.front())
			{
			case 'a':
				dCol = 1;
				break;
			case 'b':
				dCol = 2;
				break;
			case 'c':
				dCol = 3;
				break;
			case 'd':
				dCol = 4;
				break;
			case 'e':
				dCol = 5;
				break;
			case 'f':
				dCol = 6;
				break;
			case 'g':
				dCol = 7;
				break;
			case 'h':
				dCol = 8;
				break;
			}
			curMove.erase(0, 1);
		}
	}

	int mCol = 0;
	switch (curMove.front())
	{
	case 'a':
		mCol = 1;
		break;
	case 'b':
		mCol = 2;
		break;
	case 'c':
		mCol = 3;
		break;
	case 'd':
		mCol = 4;
		break;
	case 'e':
		mCol = 5;
		break;
	case 'f':
		mCol = 6;
		break;
	case 'g':
		mCol = 7;
		break;
	case 'h':
		mCol = 8;
		break;
	}
	curMove.erase(0, 1);
	int mRow = 0;
	switch (curMove.front())
	{
	case '1':
		mRow = 8;
		break;
	case '2':
		mRow = 7;
		break;
	case '3':
		mRow = 6;
		break;
	case '4':
		mRow = 5;
		break;
	case '5':
		mRow = 4;
		break;
	case '6':
		mRow = 3;
		break;
	case '7':
		mRow = 2;
		break;
	case '8':
		mRow = 1;
		break;
	}
	curMove.erase(0, 1);
	if ((p = curMove.find('+')) != std::string::npos)
		curMove.erase(0, 1);
	else if ((p = curMove.find('#')) != std::string::npos)
		curMove.erase(0, 1);

	return Move("", pType, mRow, mCol, dCol, isWhite);
}