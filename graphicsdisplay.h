#ifndef __GRAPHICSDISPLAY_H__
#define __GRAPHICSDISPLAY_H__
#include <iostream>
#include <vector>
#include "observer.h"
#include "graphicsdisplay.h"
#include "window.h"
class Cell;

class GraphicsDisplay: public Observer {
  std::vector<std::vector<char>> theDisplay;
  int gridSize;
  Xwindow xw;

 public:
  GraphicsDisplay(Xwindow &xw);

  void init(int n);
  void notify(Cell &c) override;
  SubscriptionType subType() override;

  ~GraphicsDisplay();

};

#endif
