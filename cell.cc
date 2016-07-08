#include "observer.h"
#include "cell.h"

Cell::Cell() {}

bool Cell::getState() const { return isOn; }
int Cell::getRow() const { return r; }
int Cell::getCol() const { return c; }

void Cell::setOn() {
	isOn = true;
}

void Cell::toggle() {
	isOn = !isOn;
	notifySwitchObservers();
	notifyAllObservers();
}

void Cell::setCoords(int r, int c) { this->r = r; this->c = c; }

void Cell::attach(Observer *o) {
	observers.emplace_back(o);
}

void Cell::notify(Cell &c) {
	isOn = !isOn;
	notifyAllObservers();
}

SubscriptionType Cell::subType() {
  return SubscriptionType::SwitchOnly;
}

void Cell::notifyAllObservers() {
	for (auto &ob:observers) {
		if (ob.subType() == SubscriptionType::All) {
			ob.notify(*this);
		}
	}
}

void Cell::notifySwitchObservers() {
	for (auto &ob:observers) {
		if (ob.subType() == SubscriptionType::SwitchOnly) {
		 		ob.notify(*this);
		}
	}
}
