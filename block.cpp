#include "Board.h"

Block::Block() : row(0), col(0), covered(false), value(0), userValue(0), correct(-1) {}

Block::Block(int r, int c, int num, bool cov) {
	row = r; 
	col = c; 
	covered = cov; 
	value = num; 
	userValue = num; 
	correct = 1;
	if (cov) { 
		userValue = 0; 
		correct = -1; 
	}
}

void Block::tempToggle(int num) {
	temp[num - 1] = !temp[num - 1];
}

void Block::guess(int num) {
	userValue = num;
}

void Block::check() {
	correct = (userValue == 0) ? -1 : (userValue == value) ? 1 : 0;
}