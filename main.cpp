#include "Board.h"


int main() {
	srand(time(NULL));
	cout << "Welcome to Sudoku!" << endl;
	Board b(chooseBoard());
	cout<<b;
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
		cout<<b;
		if (b.win()) break;
	} while (true);

	return 0;
}

