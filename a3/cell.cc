#include "observer.h"
#include "cell.h"

Cell::Cell() {}

bool Cell::getState() const { return isOn; }
int Cell::getRow() const { return r; }
int Cell::getCol() const { return c; }

void Cell::setOn() {
}

void Cell::toggle() {
}

void Cell::setCoords(int r, int c) { this->r = r; this->c = c; }

void Cell::attach(Observer *o) { }

void Cell::notify(Cell &) {
}

SubscriptionType Cell::subType() {
  return SubscriptionType::SwitchOnly;
}

void Cell::notifyAllObservers() {
}

void Cell::notifySwitchObservers() {
}
