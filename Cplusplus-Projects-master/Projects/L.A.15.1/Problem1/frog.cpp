//frog.cpp


#include "stdafx.h"
#include "frog.h"

frog::frog()
: myDie(2), myPosition(0)
{
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