#include "Board.h"




ostream& operator<<(ostream &os, const Board &b){
	string cyan = "\033[36m";
	string yellow = "\033[33m";
	string red = "\033[31m";
	string reset = "\033[0m";
	system("CLS");
	os << red << "   1 2 3   4 5 6   7 8 9" << reset << endl;
	for (int i = 0; i < 9; i++) {
		os << red << i + 1 << "  " << reset;
		for (int j = 0; j < 9; j++) {
			const Block& cell = *b.board[i][j];
			if (i == b.cursorRow && j == b.cursorCol)os << "\033[7m";
			if (!cell.isEditable())os << cell.value << " ";
			else if (cell.userValue == 0) os << ". ";
			else os << cyan << cell.userValue << " " << reset;
			if (i == b.cursorRow && j == b.cursorCol)os << "\033[0m";
			if (j == 2 || j == 5)os << yellow << "| " << reset;
		}
		os << endl;
		if (i == 2 || i == 5)os << yellow << "   ------+-------+------" << reset << endl;

	}
	return os;
};