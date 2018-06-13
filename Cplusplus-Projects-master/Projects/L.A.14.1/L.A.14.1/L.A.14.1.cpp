// L.A.14.1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <string>
#include <iomanip>

void squeeze(std::ifstream &inFile, std::ofstream &outFile);

int main()
{
	std::ifstream inFile("C:\\Users\\600218\\Documents\\Visual Studio 2017\\Projects\\L.A.14.1\\L.A.14.1\\Before and After\\L.A.12.1.cpp", std::ios::in);
	std::ofstream outFile("C:\\Users\\600218\\Documents\\Visual Studio 2017\\Projects\\L.A.14.1\\L.A.14.1\\Before and After\\0name.cpp", std::ios::out);
	squeeze(inFile, outFile);
    return 0;
}

/**
	Removes the leading whitespaces in the source file "L.A.12.1.cpp" and outputs it to "0name.cpp".

	@vars whites = amount of leading white spaces, whiteDone = true when no more leads for the current line
	@params inFile = the ifstream, outFile = the ofstream
*/
void squeeze(std::ifstream &inFile, std::ofstream &outFile) {
	char streamer;
	int whites = 0;
	bool whiteDone = false;

	while (inFile.get(streamer)) {
		// 32 is the whitespace ' ', 9 is a tab '\t' which is 4 spaces long
		if (!whiteDone && (streamer == 32 || streamer == 9)) {
			if (streamer == 32) {
				whites++;
			}
			else {
				whites += 4;
			}
		}
		else if (whiteDone) {
			outFile << streamer;
			if (streamer == 10) {
				whiteDone = false;
			}
		}
		else {
			if (streamer == 10) {
				outFile << streamer;
			}
			else {
				whiteDone = true;
				outFile << std::setw(2) << whites << "  " << streamer;
				whites = 0;
			}
		}
	}
}
