// L.A.11.1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

void input(double &, int &, bool &);
void output(double, int, bool);
int main()
{
	bool hasF = false;
	double gpa = 0;
	int classes = 0;
	input(gpa, classes, hasF);
	output(gpa, classes, hasF);
	return 0;
}

/*
give instructions
get first input
check if its good with while then add and repeat
*/
void input(double &gpa, int &classes, bool &hasF) {
	char input;
	std::cout << "Enter in each letter grade one by one." << std::endl << "(enter something other than a letter grade to finish)" << std::endl;
	std::cout << ":";
	std::cin >> input;
	while (input == 'A' || input == 'B' || input == 'C' || input == 'D' || input == 'F') {
		switch (input) {
		case 'A':
			gpa += 4;
			break;
		case 'B':
			gpa += 3;
			break;
		case 'C':
			gpa += 2;
			break;
		case 'D':
			gpa += 1;
			break;
		default:
			hasF = true;
			break;
		}
		classes++;
		std::cout << "\n:";
		std::cin >> input;
	}
	std::cout << std::endl;
	if (classes > 0) {
		gpa /= classes;
	}
}

/*
print out the gpa
if statements starting with 4 classes
print the message
*/
void output(double gpa, int classes, bool hasF) {
	std::cout << "GPA: " << gpa << std::endl;
	if (classes < 4) {
		std::cout << "Ineligible, taking less than 4 classes" << std::endl;
	}
	else if (gpa < 2 && hasF) {
		std::cout << "Ineligible, gpa below 2.0 and has F grade" << std::endl;
	}
	else if (gpa < 2) {
		std::cout << "Ineligible, gpa below 2.0" << std::endl;
	}
	else if (hasF) {
		std::cout << "Ineligible, gpa above 2.0 but has F grade" << std::endl;
	}
	else {
		std::cout << "Eligible";
	}
}