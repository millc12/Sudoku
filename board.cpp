#include "Board.h"

Board::Board() {
	int sol[9][9];
	int cov[9][9];
	string line;

	ifstream fin("sudoku_boards.txt");

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
			board[i][j] = Block(i, j, sol[i][j], cov[i][j]);
		}
	}
}

Block& Board::locate(int x, int y) {
	return board[x - 1][y - 1];
}

int Board::win() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (board[i][j].correct != 1) return 0;
		}
	}
	cout << "You win!!!!" << endl;
	return 1;
}

