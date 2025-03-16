#include "Board.h"




void Board::printBoard() {
	cout << "Print board here" << endl;

	for (int i = 0; i < 9; i++) {
		for (int j	 = 0; j < 9; j++) {
			if (!board[i][j].covered) cout << "  ";
			else cout << board[i][j].value << " ";
		}
		cout << endl;
	}
};



