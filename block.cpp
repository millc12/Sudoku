#include "Board.h"

Block::Block() : row(0), col(0), given(false), value(0), userValue(0), correct(-1) {}

Block::Block(int r, int c, int num, bool cov) {
	row = r;
	col = c;
	given = cov;
	value = num;
	userValue = -1;
	correct = 1;
	if (!given) {
		userValue = 0;
		correct = -1;
	}
}

void Block::tempToggle(int num) {
	temp[num - 1] = !temp[num - 1];
}

int Block::guess(int num) {
	if (given) return 1;
	userValue = num;
	return 0;
}

int Block::check() {
	if (given) {
		correct = 1;
		return correct;
	}
	correct = (userValue == 0) ? -1 : (userValue == value) ? 1 : 0;
	return correct;
}
