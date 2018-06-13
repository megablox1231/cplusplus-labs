// L.A.12.1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "dice.h"
#include <iostream>
#include <iomanip>

double prob(dice &, dice &, int);

int main()
{
	dice die1(6);
	dice die2(6);
	int num;
	double probab = 0;
	for (num = 2; num <= 12; num++) {
		probab = prob(die1, die2, num);
		std::cout << num << std::setw(7) << probab << " / 1000" << std::setw(7) << (probab / 1000) * 100 << " %" << std::endl;
	}

	std::cout << "\nNumber of rolls of die1 = " << die1.numRolls() << std::endl;
	std::cout << "Number of rolls of die2 = " << die2.numRolls() << std::endl;
    return 0;
}

double prob(dice &die1, dice &die2, int num) {
	int hits = 0;
	for (int i = 0; i < 1000; i++) {
		if (die1.roll() + die2.roll() == num)
			hits++;
	}
	return hits;
}