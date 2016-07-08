#include <iostream>
#include "textdisplay.h"
#include "cell.h"
using namespace std;

TextDisplay::TextDisplay(int n) {}

void TextDisplay::notify(Cell &c) {
}

TextDisplay::~TextDisplay() {}

SubscriptionType TextDisplay::subType() {
  return SubscriptionType::All;
}

ostream &operator<<(ostream &out, const TextDisplay &td) {
}
