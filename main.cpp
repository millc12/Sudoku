#include "Board.h"
#include "ArrowNav.h"

void enableVirtualTerminal() {
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD dwMode = 0;
	GetConsoleMode(hOut, &dwMode);
	dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	SetConsoleMode(hOut, dwMode);
}

void howToPlay() {

	cout << "How to play:" << endl;
	cout << "Each row, column and box should only have one of each digit. Fill out the whole board to win!" << endl;
	cout << "To navigate the board, use arrow keys" << endl;
	cout << "To guess a number, just type that number!" << endl;
	cout << "To remove a guess, press backspace or 0" << endl;
	cout << "To exit the game early, press the esc button" << endl;
	cout << "For help, type '?'" << endl;

	cout << "Press enter to continue" << endl;

	cin.ignore();
	cin.get();
}

int main() {
	enableVirtualTerminal();
	srand(time(NULL));
	cout << "Welcome to Sudoku! " << endl << endl << endl;
	howToPlay();
	Board b(chooseBoard());

	cout << b;
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
		else if (ch == '?') howToPlay();
		else if (ch >= '1' && ch <= '9') {
			int guess = ch - '0';
			try {
				b.locate(b.cursorRow + 1, b.cursorCol + 1).note(guess);
			}
			catch (const exception& e) {
				cout << "\033[31m" << "Error: " << e.what() << "\033[0m" << endl;
				cout << "Press any key to continue";
				_getch();
				cout << b;
			}
		}
		else if (ch == '!' || ch == '@' || ch == '#' || ch == '$' || ch == '%' ||
			ch == '^' || ch == '&' || ch == '*' || ch == '(') {
			int num;
			switch (ch) {
			case '!': num = 1; break;
			case '@': num = 2; break;
			case '#': num = 3; break;
			case '$': num = 4; break;
			case '%': num = 5; break;
			case '^': num = 6; break;
			case '&': num = 7; break;
			case '*': num = 8; break;
			case '(': num = 9; break;
			default: num = 0; break;
			}
			try {
				b.locate(b.cursorRow + 1, b.cursorCol + 1).guess(num);
				b.locate(b.cursorRow + 1, b.cursorCol + 1).check();
			}
			catch (const exception& e) {
				cout << "\033[31m" << "Error: " << e.what() << "\033[0m" << endl;
				cout << "Press any key to continue";
				_getch();
			}
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
