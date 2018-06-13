// L.A.11.2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int diceRoll();
void output(int);
int move(int);

int main()
{
	output(1);
	output(2);
	output(3);
	output(4);
	output(5);
    return 0;
}

/*
grab the input
print a comma
return the input
*/
int diceRoll() {
	int input;
	std::cin >> input;
	return input;
}

/*
print out initial stuff
grab input
while input isnt 0
	check if player 1 or 2
	move them
	grab input
print final positions
*/
void output(int num) {
	std::cout << "Line #" << num << ": ";
	bool isplayer1 = true;
	int p1Pos = 0;
	int p2Pos = 0;
	int input = diceRoll();

	while (input != 0 && p1Pos <= 40 && p2Pos <= 40) {
		if (isplayer1) {
			p1Pos += move(input);
			if(p1Pos < 0){
				p1Pos = 0;
			}
		}
		else {
			p2Pos += move(input);
			if (p2Pos < 0) {
				p2Pos = 0;
			}
		}
		if (p1Pos == p2Pos) {
			if (isplayer1) {
				p2Pos = 0;
			}
			else {
				p1Pos = 0;
			}
		}
		isplayer1 = !isplayer1;
		input = diceRoll();
	}

	std::cout << "Output #" << num << ": A-";
	if (p1Pos == 0) {
		std::cout << "START";
	}
	else if (p1Pos >= 40) {
		std::cout << "END";
	}
	else {
		std::cout << p1Pos;
	}
	std::cout << ", B-";
	if (p2Pos == 0) {
		std::cout << "START";
	}
	else if (p2Pos >= 40) {
		std::cout << "END";
	}
	else {
		std::cout << p2Pos;
	}
	std::cout << std::endl << std::endl;
	std::cin.clear();
	std::cin.ignore(INT_MAX, '\n');
}

int move(int input) {
	int movement;
	switch (input) {
	case 1:
		movement = 1;
		break;
	case 2:
		movement = 2;
		break;
	case 3:
		movement = 3;
		break;
	case 4:
		movement = -4;
		break;
	case 5:
		movement = 5;
		break;
	case 6:
		movement = -6;
		break;
	case 7:
		movement = 7;
		break;
	case 8:
		movement = 8;
		break;
	}
	return movement;
}