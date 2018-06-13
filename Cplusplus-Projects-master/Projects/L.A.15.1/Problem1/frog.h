//frog.h
#pragma once

#ifndef _FROG_H
#define _FROG_H

#include "dice.h"

class frog {
public:
	frog();
	int getPos() const;
	void move();
	int getSteps();
private:
	int myPosition;
	dice myDie;
};

#include "frog.cpp"

#endif