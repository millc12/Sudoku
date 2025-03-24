#pragma once

#include <iostream>
#include <string>
#include <istream>
#include <fstream>


using namespace std;



class Block {
	friend class Board;
private:
	int row, col;
	bool given;
	int value;
	int userValue;// 0 for not guessed, -1 for given
	bool temp[9] = { false };
	int correct;//-1 not guessed, 0 incorrect, 1 correct

public:
	Block();
	Block(int r, int c, int num, bool cov);
	void tempToggle(int num);
	int guess(int num);
	int check();
};

class Board {
private:
	Block board[9][9];
public:
	Board(string difficulty);
	void printBoard();
	Block& locate(int x, int y);
	int win();
};
