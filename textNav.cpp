#include "Board.h"

string chooseBoard() {
	cout << "Choose difficulty(e:easy, m:medium, h:hard)" << endl;
	char difficulty;
	cin >> difficulty;
	difficulty = tolower(difficulty);

	ifstream fin("track.txt");
	if (!fin.is_open()) {
		cerr << "Failed to open track.txt" << endl;
	}

	vector<string>lines(6);
	for (int i = 0; i < 6; i++) {
		getline(fin, lines[i]);
	}

	fin.close();

	int index = (difficulty == 'e') ? 0 :
		(difficulty == 'm') ? 1 :
		(difficulty == 'h') ? 2 : -1;

	if (index == -1) {
		cerr << "Invalid difficulty choice!" << endl;
		exit(1);
	}


	string current = lines[index];
	string maxID = lines[index + 3];

	int num = stoi(current.substr(1));
	int max = stoi(maxID.substr(1));

	string boardCode = string(1, difficulty) + to_string(num);

	num++;
	if (num > max) num = 1;

	lines[index] = string(1, difficulty) + to_string(num);


	ofstream fout("track.txt");
	for (const string& l : lines) {
		fout << l << endl;
	}
	fout.close();

	return boardCode;
}
