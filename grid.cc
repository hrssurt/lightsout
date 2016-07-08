#include <iostream>
#include <vector>
#include "grid.h"
using namespace std;

Grid::Grid() {}

Grid::~Grid() {
	delete td;
}

void Grid::clearGrid() {
	for (int i = 0; i < gridSize; ++i) {
		theGrid[i].clear();
	}
	theGrid.clear();
}

bool Grid::isWon() const {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (theGrid[i][j].getState() == false) {
				return false;
			}
		}
	}
	return true;
}

void Grid::init(int n) {
	//clear old grid (not completed)
	clearGrid();
	gridSize = n;
	for (int i = 0; i < n; ++i) {
		vector<Cell> Gridrow;
		for (int j = 0; j < n; ++j) {
			Cell c;
			c.setCoords(i,j);
			//what else
			Gridrow.emplace_back(c);
		}
		theGrid.emplace_back(Gridrow);
	}

	//add observers cell
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			currentGrid = theGrid[i][j];

			if (i > 0) {
				currentGrid.attach(&theGrid[i-1][j]);
			}

			if (i + 1 < n) {
				currentGrid.attach(&theGrid[i+1][j]);
			}

			if (j > 0) {
				currentGrid.attach(&theGrid[i][j-1]);
			}

			if (j + 1 < n) {
				currentGrid.attach(&theGrid[i][j+1]);
			}

			currentGrid.attach(td);
		}
	}
}

void Grid::turnOn(int r, int c) {
  theGrid[r][c].setOn();
  td->notify(theGrid[r][c]);
}

void Grid::toggle(int r, int c) {
  theGrid[r][c].toggle();
}

ostream &operator<<(ostream &out, const Grid &g) {
	out << *(g.td);
	return out;
}
