#pragma once

#include <iostream>
#include <string>
#include <istream>
#include <fstream>
#include <vector>
#include <windows.h>


using namespace std;



class Block {
	friend class Board;
protected:
	int row, col;
	int value;
	int userValue;// 0 for not guessed, -1 for given
	int correct;//-1 not guessed, 0 incorrect, 1 correct

public:
	Block();
	Block(int r, int c, int num);
	virtual ~Block() {}
	friend ostream& operator<<(ostream& os, const Board& b);
	virtual bool isEditable() const = 0;
	virtual int guess(int num) = 0;
	virtual int check() = 0;
	virtual void note(int num) = 0;
	virtual bool viewNote() const = 0;
};

class GivenBlock : public Block {
public: 
	GivenBlock(int r, int c, int num) : Block(r, c, num) { userValue = num;correct = 1; }
	bool isEditable() const override { return false; }
	int guess(int num) override {throw runtime_error("Cannot guess on a given cell");}
	int check() override { return 1; }
	void note(int num) override {}
	bool viewNote() const override { return 1; }
};

class InputBlock : public Block {
private:
	bool notes[9];
	bool viewnote = true;
public:
	InputBlock(int r, int c, int num) : Block(r, c, num), notes{ false } { userValue = 0;correct = -1; }
	bool isEditable() const override { return true; }
	int guess(int num) override { userValue = num;viewnote = false;if (num == 0)viewnote = true;return 0; }
	int check() override {if (userValue == 0) correct = -1;else if (userValue == value) correct = 1;else correct = 0;return correct;}
	void note(int num) override { viewnote = true; if (notes[num - 1]) notes[num - 1] = false;else notes[num - 1] = true; }
	bool viewNote() const override { return viewnote; }
	const bool* getNotes() const { return notes; }
};


class Board {
private:
	Block* board[9][9];
public:
	Board(string difficulty);
	~Board();
	int cursorRow = 0;
	int cursorCol = 0;
	friend ostream& operator<<(ostream &os, const Board &b);
	Block& locate(int x, int y);
	bool isGiven() { Block* block = board[cursorRow - 1][cursorCol - 1]; bool given = block->isEditable(); return given; }
	int win();
};

string chooseBoard();