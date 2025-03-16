#pragma once

#include <iostream>
using namespace std;



class Block {
	friend class Board;
private:
	int row, col;
	bool covered;
	int value;
	int userValue;// 0 for not guessed
	bool temp[9] = { false };
	int correct;//-1 not guessed, 0 incorrect, 1 correct

public:
	Block();
	Block(int r, int c, int num, bool cov);
	void tempToggle(int num);
	void guess(int num);
	void check();
};

class Board {
private:
	Block board[9][9];
public:
	Board();
	void printBoard();
};
