#include <iostream>
#include "textdisplay.h"
#include "cell.h"
using namespace std;


TextDisplay::TextDisplay(int n) {
	gridSize = n;
	for (int i = 0; i < n; ++i) {
		vector<char> v;
		for (int j = 0; j < n; ++j) {
			v.emplace_back('_');
		}
		theDisplay.emplace_back(v);
	}
}

void TextDisplay::notify(Cell &c) {
	//observer
  int tr = c.getRow();
	int tc = c.getCol();
	if (c.getState()) {
		theDisplay[tr][tc] = 'X';
	} else {
		theDisplay[tr][tc] = '_';
	}
}

TextDisplay::~TextDisplay() {}

SubscriptionType TextDisplay::subType() {
  return SubscriptionType::All;
}

ostream &operator<<(ostream &out, const TextDisplay &td) {
	for (int i = 0; i < td.gridSize; ++i) {
		for (int j = 0; j < td.gridSize; ++j) {
			out << td.theDisplay[i][j];
		}
		out << endl;
	}
	out << endl;
  return out;
}
