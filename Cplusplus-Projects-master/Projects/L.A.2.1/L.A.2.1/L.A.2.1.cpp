// L.A.2.1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

int main()
{
	int num1 = 1;
	cout << "The value of num1 = " << num1;
	cout << "   The byte size of num1 is " << sizeof(num1) << " bytes." << endl;

	long int num2 = 2;
	cout << "The value of num2 = " << num2;
	cout << "   The byte size of num2 is " << sizeof(num2) << " bytes." << endl;

	unsigned int num3 = 3;
	cout << "The value of num3 = " << num3;
	cout << "   The byte size of num3 is " << sizeof(num3) << " bytes." << endl;

	char letter = 'd';
	cout << "The value of letter = " << letter;
	cout << "   The byte size of letter is " << sizeof(letter) << " bytes." << endl;

	float num4 = 5.5;
	cout << "The value of num4 = " << num4;
	cout << "   The byte size of num4 is " << sizeof(num4) << " bytes." << endl;

	double num5 = 6.6;
	cout << "The value of num5 = " << num5;
	cout << "   The byte size of num5 is " << sizeof(num5) << " bytes." << endl;

	long double num6 = 7.7;
	cout << "The value of num6 = " << num6;
	cout << "   The byte size of num6 is " << sizeof(num6) << " bytes." << endl;

	bool answer = true;
	cout << "The value of answer = " << answer;
	cout << "   The byte size of answer is " << sizeof(answer) << " bytes." << endl;

	int ascii = letter;
	cout << "Letter = " << letter << "   ASCII position = " << ascii << endl;

	int pos = 42;
	char symbol = pos;
	cout << "ASCII position = " << pos << "   Letter = " << symbol;
    return 0;
}

