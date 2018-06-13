// L.A.17.1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "dice.h"
#include <iostream>

int main()
{
	dice die1(6);
	dice die2(6);
	dice die3(6);
	int num1, num2, num3;
	do {
		num1 = die1.roll();
		num2 = die2.roll();
		num3 = die3.roll();
		std::cout << num1 << " " << num2 << " " << num3 << std::endl;
	} while ((num1 == num2) || (num1 == num3) || (num2 == num3));

	std::cout << "cout = " << die1.numRolls() << std::endl;

    return 0;
}

