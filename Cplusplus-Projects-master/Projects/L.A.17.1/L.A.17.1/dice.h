

// dice.h
/* class for simulating a die to generate an integer random number.

dice(int sides) --	constructor, sides specifies number of "sides"
for the die, 2 for a coin, 6 for a regular die, etc.

int roll() --	returns the random roll of the die, a (hopefully) uniformly
distributed random number between 1 and # of sides

int numSides() -- access function, returns # of sides

Modeled after a dice class from Owen Astrachan, Duke University.
A Computer Science Tapestry, McGraw Hill, Custom College Series, © 1997.
Last revised, Cary Matsuoka,  5/30/96  */

#ifndef _DICE_H
#define _DICE_H

/* This version of dice.h requires a different process for initializing the
random number generator in stdlib.h.  We need to explicitly access the system clock to
get an initial long integer seed value. */

#include <stdlib.h>    // srand() and rand() are inside of stdlib.h
#include <time.h>
#include <limits.h>
#include <chrono>

class dice {
public:
	dice(int sides);		// constructor
	int roll();			// return the random roll
	int numSides();		// returns number of sides on die
	int numRolls();
private:
	int mySides;
	int myRollCount;
};								// note semicolon after closing brace of class

dice::dice(int sides)
// postcondition:  all private fields initialized
// srand() called to set random number generator
{
	time_t timer;
	struct tm y2k = { 0 };
	y2k.tm_hour = 0;   y2k.tm_min = 0; y2k.tm_sec = 0;
	y2k.tm_year = 100; y2k.tm_mon = 0; y2k.tm_mday = 1;
	timer = time(NULL);
	unsigned int joe = difftime(timer, mktime(&y2k));
	//std::cout << time;
	srand(joe);
	mySides = sides;
	myRollCount = 0;
}

int dice::roll()
// postcondition: # of rolls updated, returns random die roll
{
	myRollCount++;
	return  ( rand() % mySides) + 1;	//  adjust value to fit in range 1 - mySides
}

int dice::numSides()
// postcondition:  return # of sides of die
{
	return mySides;
}

int dice::numRolls() {
	return myRollCount;
}

#endif
