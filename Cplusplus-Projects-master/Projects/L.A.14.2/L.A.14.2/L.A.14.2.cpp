// L.A.14.2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>

void average(std::ifstream &inFile, std::ofstream &outFile);

int main()
{
	std::ifstream inFile("numbers.txt", std::ios::in);
	std::ofstream outFile("numbers.txt", std::ios::app);

	average(inFile, outFile);
    return 0;
}

void average(std::ifstream &inFile, std::ofstream &outFile) {
	long int total = 0;
	int cur;
	int count = 0;

	while (inFile >> cur) {
		count++;
		total += cur;
	}
	outFile.precision(4);
	outFile << (float)(total) / count;
}
