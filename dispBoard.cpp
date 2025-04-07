#include "Board.h"



string setColor(int fr, int fg, int fb, int br = -1, int bg = -1, int bb = -1) {
	string text = "\033[38;2;" + to_string(fr) + ";" + to_string(fg) + ";" + to_string(fb) + "m";
	string background = "";
	if (br != -1 && bg != -1 && bb != -1) {background = "\033[48;2;" + to_string(br) + ";" + to_string(bg) + ";" + to_string(bb) + "m";}
	return text + background;
}

ostream& operator<<(ostream& os, const Board& b) {
	string colors[10][2];

	string important = setColor(150, 110, 75, 0, 0, 0);

	// System-level (non-digit) colors
	colors[0][0] = setColor(70, 40, 20, 0, 0, 0);             // skeleton (reset)
	colors[0][1] = setColor(100,100,100, 0, 0, 0);           // notes (dark bacckground)

	// Digit colors
	colors[1][1] = setColor(180, 60, 60,0,0,0);             
	colors[1][0] = setColor(180, 60, 60, 25, 25, 25);		

	colors[2][1] = setColor(200, 120, 40,0,0,0);
	colors[2][0] = setColor(200, 120, 40, 25, 25, 25);

	colors[3][1] = setColor(200, 170, 40,0,0,0);
	colors[3][0] = setColor(200, 170, 40, 25, 25, 25);

	colors[4][1] = setColor(120, 180, 60,0,0,0);
	colors[4][0] = setColor(120, 180, 60, 25, 25, 25);

	colors[5][1] = setColor(60, 160, 140,0,0,0);
	colors[5][0] = setColor(60, 160, 140, 25, 25, 25);

	colors[6][1] = setColor(60, 120, 180,0,0,0);
	colors[6][0] = setColor(60, 120, 180, 25, 25, 25);

	colors[7][1] = setColor(100, 100, 180,0,0,0);
	colors[7][0] = setColor(100, 100, 180, 25, 25, 25);

	colors[8][1] = setColor(150, 100, 180,0,0,0);
	colors[8][0] = setColor(150, 100, 180, 25, 25, 25);

	colors[9][1] = setColor(180, 100, 140,0,0,0);
	colors[9][0] = setColor(180, 100, 140, 25, 25, 25);
	system("CLS");

	string numbers[3][9] = {
      // "1234567"  "1234567"  "1234567"  "1234567"  "1234567"  "1234567"  "1234567"  "1234567"  "1234567"
		{"  / |  ", " |_  ) ", " |__ / ", " | | | ", " | __| ", "  / /  ", " |__  |", " ( _ ) ", " / _ \\ "},
		{"  | |  ", "  / /  ", "  |_ \\ ", " |_  _|", " |__ \\ ", " / _ \\ ", "   / / ", " / _ \\ ", " \\_, / "},
		{"  |_|  ", " /___| ", " |___/ ", "   |_| ", " |___/ ", " \\___/ ", "  /_/  ", " \\___/ ", "  /_/  "},
	};

	string toPrint[9][9][3];
	int num;
	int numguess;
	string printnotes[9];
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			const Block& cell = *b.board[i][j];
			num = cell.value;
			numguess = cell.userValue;
			if (!cell.isEditable()) {
				toPrint[i][j][0] = colors[num][1] + numbers[0][num - 1];
				toPrint[i][j][1] = colors[num][1] + numbers[1][num - 1];
				toPrint[i][j][2] = colors[num][1] + numbers[2][num - 1];
			}
			else {
				const Block* base = b.board[i][j];
				const InputBlock* input = dynamic_cast<const InputBlock*>(base);
				if (cell.viewNote()) {
					const bool* notes = input->getNotes();
					for (int k = 0; k < 9; k++) {
						if (notes[k]) { printnotes[k] = to_string(k + 1); }
						else printnotes[k] = ' ';
					}
					toPrint[i][j][0] = colors[0][1] + " " + printnotes[0] + " " + printnotes[1] + " " + printnotes[2] + " ";
					toPrint[i][j][1] = colors[0][1] + " " + printnotes[3] + " " + printnotes[4] + " " + printnotes[5] + " ";
					toPrint[i][j][2] = colors[0][1] + " " + printnotes[6] + " " + printnotes[7] + " " + printnotes[8] + " ";
					
				}
				else {
					toPrint[i][j][0] = colors[numguess][0] + numbers[0][numguess - 1];
					toPrint[i][j][1] = colors[numguess][0] + numbers[1][numguess - 1];
					toPrint[i][j][2] = colors[numguess][0] + numbers[2][numguess - 1];
				}
			}
		}
	}
	os << colors[0][0] << "===========================================================================" << endl;

	for (int i = 0; i < 9; i++) {
		for (int line = 0; line < 3; line++) {
			os << colors[0][0] << "|";
			for (int j = 0; j < 9; j++) {
				if (i == b.cursorRow && j == b.cursorCol) os << "\033[7m";
				os << toPrint[i][j][line];
				if (i == b.cursorRow && j == b.cursorCol) os << "\033[0m";
				if (j == 2 || j == 5) os << important << "||";
				else os << colors[0][0] <<"|";
			}
			os << endl;
		}
		if (i == 2 || i == 5)
			os << important << "===========================================================================" << endl;
		else if (i != 8)
			os << colors[0][0] << "---------------------------------------------------------------------------" << endl;
	}
	os << colors[0][0] << "===========================================================================" << endl;
	return os;
};