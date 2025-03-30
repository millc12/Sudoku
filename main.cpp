#include "Board.h"
#include "ArrowNav.h"

void howToPlay() {
	
	cout << "How to play:" << endl;
	cout << "Each row, column and box should only have one of each digit. Fill out the whole board to win!" << endl;
	cout << "To navigate the board, use arrow keys" << endl;
	cout << "To guess a number, just type that number!" << endl;
	cout << "To remove a guess, press backspace or 0" << endl;
	cout << "To exit the game early, press the esc button" << endl << endl << endl;

	cout << "Press enter to continue" << endl;

	cin.ignore();
	cin.get();
}

int main() {
	srand(time(NULL));
	cout << "Welcome to Sudoku! " << endl << endl << endl;
	howToPlay();
	Board b(chooseBoard());

	cout<<b;
	int ch;
	int arrow;

	do {
		ch = _getch();

		if (ch == 224) {
			arrow = _getch();
			switch (arrow) {
			case 72:
				if (b.cursorRow > 0) b.cursorRow--;
				break;
			case 80:
				if (b.cursorRow < 8) b.cursorRow++;
				break;
			case 75:
				if (b.cursorCol > 0) b.cursorCol--;
				break;
			case 77:
				if (b.cursorCol < 8) b.cursorCol++;
				break;
			}
		}
		else if(ch == '?') howToPlay();
		else if (ch >= '1' && ch <= '9') {
			int guess = ch - '0';
			b.locate(b.cursorRow + 1, b.cursorCol + 1).guess(guess);
			b.locate(b.cursorRow + 1, b.cursorCol + 1).check();
		}
		else if (ch == '0' || ch == 8) {
			b.locate(b.cursorRow + 1, b.cursorCol + 1).guess(0);
			b.locate(b.cursorRow + 1, b.cursorCol + 1).check();
		}
		else if (ch == 27) {
			cout << "Exiting..." << endl;
			return 0;
		}

		cout << b;

		if (b.win()) break;
	} while (true);
	return 0;
}

