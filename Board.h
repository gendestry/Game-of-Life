#pragma once

#include <vector>
#include <ctime>

#define CELL_SIZE 8
#define NUM_COLS 100
#define NUM_ROWS 75

class Board {
private:
	std::vector<bool> board;
	std::vector<bool> newBoard;

public:
	Board();
	void update();
	bool getState(int x, int y);
	int arrIndex(int x, int y);
	int checkNeighbours(int x, int y);
};