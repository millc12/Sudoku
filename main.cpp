
#include "Board.h"

int main() {
	Board b;
	b.printBoard();
	int row;
	int col;
	int guess;

	do {
		cout << "Enter a row: ";
		cin >> row;
		cout << "Enter a column: ";
		cin >> col;
		cout << "Enter a guess: ";
		cin >> guess;
		b.locate(row, col).guess(guess);
		b.locate(row, col).check();
		b.printBoard();
		if (b.win()) break;
	} while (true);

	return 0;
}