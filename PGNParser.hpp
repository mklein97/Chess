#pragma once
#include "stdafx.h"
#include <string>
#include <stdio.h>
#include <fstream>

using namespace std;

class Move
{
public:
	std::string tag_pair;
	int type;
	int row;
	int col;
	int dCol;
	bool isWhite;
	Move(std::string s, int t, int r, int c, int colD, bool white)
	{
		tag_pair = s;
		type = t;
		row = r;
		col = c;
		dCol = colD;
		isWhite = white;
	}
};

class PGNParser
{
public:
	PGNParser();
	PGNParser(const std::string& filename);
	~PGNParser();
	void open(const std::string& filename);
	void close();
	bool getIsOpen()const;
	Move getMove();
	std::string::iterator it;
private:
	std::string myLine;
	std::ifstream myFile;
};

