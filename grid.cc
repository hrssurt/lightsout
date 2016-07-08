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
}

void Grid::winthegame() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (theGrid[i][j].getState() == false) {
				won = false;
				break;
			}
		}
	}
	won = true;
}

bool Grid::isWon() const { return won; }

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
			if (i == 0 && j == 0) {
				theGrid[i][j].attach(&theGrid[i+1][j]);
				theGrid[i][j].attach(&theGrid[i][j+1]);
			} 
			else if (i == 0 && j == n-1) {
				theGrid[i][j].attach(&theGrid[i+1][j]);
				theGrid[i][j].attach(&theGrid[i][j-1]);
			} 
			else if (i == n-1 && j == 0) {
				theGrid[i][j].attach(&theGrid[i][j+1]);
				theGrid[i][j].attach(&theGrid[i-1][j]);
			}
			else if (i == n-1 && j == n-1) {
				theGrid[i][j].attach(&theGrid[i][j-1]);
				theGrid[i][j].attach(&theGrid[i-1][j]);
			}
			else if (i == 0) {
				theGrid[i][j].attach(&theGrid[i][j+1]);
				theGrid[i][j].attach(&theGrid[i+1][j]);
				theGrid[i][j].attach(&theGrid[i][j-1]);
			}
			else if (i == n-1) {
				theGrid[i][j].attach(&theGrid[i][j+1]);
				theGrid[i][j].attach(&theGrid[i][j-1]);
				theGrid[i][j].attach(&theGrid[i-1][j]);
			}
			else if (j == 0) {
				theGrid[i][j].attach(&theGrid[i][j+1]);
				theGrid[i][j].attach(&theGrid[i+1][j]);
				theGrid[i][j].attach(&theGrid[i-1][j]);
			}
			else if (j == n-1) {
				theGrid[i][j].attach(&theGrid[i-1][j]);
				theGrid[i][j].attach(&theGrid[i+1][j]);
				theGrid[i][j].attach(&theGrid[i][j-1]);
			} else {
				theGrid[i][j].attach(&theGrid[i-1][j]);
				theGrid[i][j].attach(&theGrid[i+1][j]);
				theGrid[i][j].attach(&theGrid[i][j-1]);
				theGrid[i][j].attach(&theGrid[i][j+1]);
			}
			theGrid[i][j].attach(td);
		}
	}
}

void Grid::turnOn(int r, int c) {
  theGrid[r][c].setOn();
  td->notify(theGrid[r][c]);
}

void Grid::toggle(int r, int c) {
  theGrid[r][c].toggle();
  winthegame();
}

ostream &operator<<(ostream &out, const Grid &g) {
	out << *(g.td);
	return out;
}
