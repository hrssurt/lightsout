#include <iostream>
#include "graphicsdisplay.h"
#include "cell.h"
using namespace std;


GraphicsDisplay::GraphicsDisplay(Xwindow &newXw) {
  xw = newXw;
  xw.fillRectangle(0, 0, 500, 500, Xwindow::Black);
}

void GraphicsDisplay::init(int n) {
  gridSize = n;
  for (int i = 0; i < n; ++i) {
    vector<char> v;
    for (int j = 0; j < n; ++j) {
      v.emplace_back('_');
    }
    theDisplay.emplace_back(v);
  }
}

void GraphicsDisplay::notify(Cell &c) {
  //observer
  int tr = c.getRow();
  int tc = c.getCol();
  if (c.getState()) {
    theDisplay[tr][tc] = 'X';
  } else {
    theDisplay[tr][tc] = '_';
  }

  xw.fillRectangle(0, 0, 500, 500, Xwindow::Black);
  for (int i = 0; i < gridSize; ++i) {
    for (int j = 0; j < gridSize; ++j) {
      xw.fillRectangle(j*20, i*20, 10, 10, Xwindow::White);
    }
  }
}

GraphicsDisplay::~GraphicsDisplay() {}

SubscriptionType GraphicsDisplay::subType() {
  return SubscriptionType::All;
}
