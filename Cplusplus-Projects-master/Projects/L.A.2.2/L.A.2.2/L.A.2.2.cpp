// L.A.2.2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

int main()
{
	int num1 = 4 + 9;
	double num2 = 46 / 7;
	int num3 = 46 % 7;
	float num4 = 2 * 3.0;
	float num5 = float(25) / 4;
	int num6 = int(7.75) + 2;
	int num7 = int('P');
	char letter = char(105);

	cout << "4 + 9 = " << num1 << endl;
	cout << "46 / 7 = " << num2 << endl;
	cout << "46 % 7 = " << num3 << endl;
	cout << "2 * 3.0 = " << num4 << endl;
	cout << "float(25) / 4 = " << num5 << endl;
	cout << "int(7.75) + 2 = " << num6 << endl;
	cout << "int('P') = " << num7 << endl;
	cout << "char(105) = " << letter << endl;

	cout << "The largest 2-byte integer = " << INT_MAX << endl;
	cout << "The smallest 2-byte integer = " << INT_MIN << endl;
	cout << "The largest unsigned (positives only) 2-byte integer = " << UINT_MAX << endl;
	cout << "The largest 4-byte integer = " << LONG_MAX << endl;
	cout << "The smallest 4-byte integer = " << LONG_MIN << endl;
	cout << "The largest unsigned (positives only) 4-byte integer = " << ULONG_MAX << endl;
	cout << "The largest 4-byte float = " << FLT_MAX << endl;
	cout << "The smallest 4-byte float = " << FLT_MIN << endl;
	cout << "The largest 8-byte float = " << DBL_MAX << endl;
	cout << "The smallest 8-byte float = " << DBL_MIN << endl;
    return 0;
}

