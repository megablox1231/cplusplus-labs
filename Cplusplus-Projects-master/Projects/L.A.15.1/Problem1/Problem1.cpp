// Problem1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "frog.h"

int main()
{
	int numSteps;
	frog slippy;

	std::cout << "Number of steps to take: ";
	std::cin >> numSteps;

	while (numSteps < 0) {
		slippy.move();
	}
	std::cout << "\nFinal Position: " << slippy.getPos();

    return 0;
}

