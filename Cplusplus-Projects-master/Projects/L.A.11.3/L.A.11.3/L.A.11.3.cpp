// L.A.11.3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int diceRoll();
void output(int);
int move(int, bool &);
void backToStart(int &, int &, int &, int);

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
check if player 1 or 2 or 3
move them
grab input
print final positions
*/
void output(int num) {
	std::cout << "Line #" << num << ": ";
	int turn = 1;
	int p1Pos = 1;
	int p2Pos = 1;
	int p3Pos = 1;
	bool skip1 = false, skip2 = false, skip3 = false, noDice = false;
	int input = diceRoll();

	while (input != 0 && p1Pos < 31 && p2Pos < 31 && p3Pos < 31) {
		if (turn == 1) {					//player 1
			if (skip1) {
				skip1 = false;
				noDice = true;
			}
			else {
				p1Pos += move(input, skip1);
				if (p1Pos < 1) {
					p1Pos = 1;
				}
			}
		} 

		if (turn == 2) {					//player 2
			if (skip2) {
				skip2 = false;
				noDice = true;
			}
			else {
				p2Pos += move(input, skip2);
				if (p2Pos < 1) {
					p2Pos = 1;
				}
			}
		}

		if (turn == 3) {				//player 3
			if (skip3) {
				skip3 = false;
				noDice = true;
			}
			else {
				p3Pos += move(input, skip3);
				if (p3Pos < 1) {
					p3Pos = 1;
				}
			}
			turn = 0;
		}

		if ((p1Pos == p2Pos && p1Pos != 1) || (p1Pos == p3Pos && p1Pos != 1) || (p2Pos == p3Pos && p2Pos != 1)) {			//land on eachother
			backToStart(p1Pos, p2Pos, p3Pos, turn);
		}
		if (noDice) {
			noDice = false;
		}
		else {
			input = diceRoll();
		}
		turn++;
	}

	std::cout << "Output #" << num << ": A-";
	if (p1Pos == 1) {
		std::cout << "START";
	}
	else if (p1Pos > 30) {
		std::cout << "END";
	}
	else {
		std::cout << (p1Pos - 1);
	}
	std::cout << ", B-";
	if (p2Pos == 1) {
		std::cout << "START";
	}
	else if (p2Pos > 30) {
		std::cout << "END";
	}
	else {
		std::cout << (p2Pos - 1);
	}
	std::cout << ", C-";
	if (p3Pos == 1) {
		std::cout << "START";
	}
	else if (p3Pos > 30) {
		std::cout << "END";
	}
	else {
		std::cout << (p3Pos - 1);
	}
	std::cout << std::endl << std::endl;
	std::cin.clear();
	std::cin.ignore(INT_MAX, '\n');
}

int move(int input, bool &skipMe) {
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
		movement = 0;
		skipMe = true;
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

void backToStart(int &p1Pos, int &p2Pos, int &p3Pos, int turn) {
	if (turn == 1 && p1Pos == p2Pos) {
		p2Pos = 1;
	}
	else if (turn == 1 && p1Pos == p3Pos) {
		p3Pos = 1;
	}
	else if (turn == 2 && p1Pos == p2Pos) {
		p1Pos = 1;
	}
	else if (turn == 2 && p3Pos == p2Pos) {
		p3Pos = 1;
	}
	else if (turn == 0 && p3Pos == p1Pos) {
		p1Pos = 1;
	}
	else if (turn == 0 && p3Pos == p2Pos) {
		p2Pos = 1;
	}
}