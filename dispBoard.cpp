#include "Board.h"




void Board::printBoard() {
	string cyan = "\033[36m";
	string yellow = "\033[33m";
	string red = "\033[31m";
	string reset = "\033[0m";
	system("CLS");
	cout << red << "   1 2 3   4 5 6   7 8 9" << reset << endl;
	for (int i = 0; i < 9; i++) {
		cout << red << i + 1 << "  " << reset;
		for (int j = 0; j < 9; j++) {
			if (board[i][j].given)cout << board[i][j].value << " ";
			else if (board[i][j].userValue == 0) cout << ". ";
			else cout << cyan << board[i][j].userValue << " " << reset;

			if (j == 2 || j == 5)cout << yellow << "| " << reset;
		}
		cout << endl;
		if (i == 2 || i == 5)cout << yellow << "   ------+-------+------" << reset << endl;

	}
};