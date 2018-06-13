//frog.cpp

#include "frog.h"

frog::frog() {
}

int frog::getPos() const {
	return myPosition;
}

void frog::move() {
	(myDie.roll() == 1) ? myPosition++ : myPosition--;
}

int frog::getSteps() {
	return myDie.numRolls();
}