#include "Board.h"

Block::Block() : row(0), col(0), value(0), userValue(0), correct(-1) {}

Block::Block(int r, int c, int num) {
	row = r;
	col = c;
	value = num;
	userValue = 0;
	correct = -1;
}

