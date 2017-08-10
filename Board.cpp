#include "Board.h"

Board::Board() {

	srand(time(nullptr));

	for (int i = 0; i < NUM_COLS * NUM_ROWS; i++) {	
		if (rand() % 10 > 8) {
			board.push_back(true);
			newBoard.push_back(true);
		}
		else {
			board.push_back(false);
			newBoard.push_back(false);
		}
	}

}

bool Board::getState(int x, int y) { // status
	return board[arrIndex(x, y)];
}

int Board::arrIndex(int x, int y) { // 2d --> 1d
	return x + (y * NUM_ROWS);
}

void Board::update() {	// create or destroy life
	for (int x = 0; x < NUM_COLS; x++) {
		for (int y = 0; y < NUM_ROWS; y++) {
			if (getState(x,y)) {
				if (checkNeighbours(x, y) < 2) {
					newBoard[arrIndex(x, y)] = false;
				}
				else if (checkNeighbours(x, y) < 4 && checkNeighbours(x, y) > 1) {
					newBoard[arrIndex(x, y)] = true;
				}
				else {
					newBoard[arrIndex(x, y)] = false;
				}
			}
			else {
				if (checkNeighbours(x, y) == 3) {
					newBoard[arrIndex(x, y)] = true;
				}
				else {
					newBoard[arrIndex(x, y)] = false;
				}
			}
		}
	}
	board = newBoard;
}

int Board::checkNeighbours(int x, int y) {
	int total = 0;

	//left
	if (x - 1 >= 0) {
		if (getState(x - 1, y))
			total++;
	}

	//right
	if (x + 1 <= NUM_COLS) {
		if (getState(x + 1, y))
			total++;
	}

	//bottom
	if (y + 1 <= NUM_ROWS) {
		//left
		if (x - 1 >= 0) {
			if (getState(x - 1, y + 1))
				total++;
		}

		//right
		if (x + 1 <= NUM_COLS) {
			if (getState(x + 1, y + 1))
				total++;
		}

		//center
		if (getState(x, y + 1))
			total++;
	}

	//top
	if (y - 1 >= 0) {
		//left
		if (x - 1 >= 0) {
			if (getState(x - 1, y - 1))
				total++;
		}

		//right
		if (x + 1 <= NUM_COLS) {
			if (getState(x + 1, y - 1))
				total++;
		}

		//center
		if (getState(x, y - 1))
			total++;
	}

	return total;
}