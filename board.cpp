#include "Board.h"

Board::Board(string difficulty) {
	int sol[9][9];
	int cov[9][9];
	string line;


	ifstream fin("boards.txt");

	string location;
	bool found = false;

	while (getline(fin, location)) {
		if (location == difficulty) {
			found = true;
			break;
		}
	}

	getline(fin, line);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cov[i][j] = line[i * 9 + j] - '0';
		}
	}

	getline(fin, line);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			sol[i][j] = line[i * 9 + j] - '0';
		}
	}
	fin.close();

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (cov[i][j] == 1)
				board[i][j] = new GivenBlock(i, j, sol[i][j]);
			else
				board[i][j] = new InputBlock(i, j, sol[i][j]);
		}
	}
}

Block& Board::locate(int x, int y) {
	return *board[x - 1][y - 1];
}

Board::~Board() { 
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			delete board[i][j];
		}
	}
	cout << "Game exited"; 
}

int Board::win() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (board[i][j]->check() != 1) return 0;
		}
	}
	cout << "You win!!!!" << endl;
	return 1;
}



