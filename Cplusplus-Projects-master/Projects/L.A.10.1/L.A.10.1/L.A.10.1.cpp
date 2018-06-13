// L.A.10.1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>

void printTable(int, int);
void pyramid(int);

int main()
{
	printTable(4, 6);
	std::cin.get();		// freezes the output screen to see the picture
	printTable(11, 12);
	std::cin.get();
	pyramid(10);
	std::cin.get();
	pyramid(25);
	std::cin.get();

    return 0;
}

/*
print the column headings in a for loop
for loop through the rows
	print curent row heading
	for loop through columns
		do math and print num
	next line
*/
void printTable(int row, int col) {
	std::cout << " ";
		for (int i = 1; i <= col; i++) {
			std::cout << std::setw(6) << i;
	}
	std::cout << "\n\n";
	
	for (int r = 1; r <= row; r++) {
		std::cout << std::setw(5) << std::setiosflags(std::ios::left) << r;
		std::cout << std::resetiosflags(std::ios::left);
		if (r < 10) {
			std::cout << " ";
		}
		for (int c = 1; c <= col; c++) {
			std::cout << r * c;
			if (c < col) {
				std::cout << std::setw(6);
			}
		}
		std::cout << std::endl;
	}
}
/*
initialize a star and current string
for loop
add stars to curr
print out the stars
repeat till get to height
*/
void pyramid(int height) {
	std::string star = "*";
	std::string curr = "*";
	for (int row = 1; row <= height; row++) {
		std::cout << std::setw(height + row) << curr << std::endl;
		curr = star + curr + star;
	}
}