// L.A.4.2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include <iomanip>

using namespace std;

int main()
{
	double a, b, c;
	cout << "Input a: ";
	cin >> a;
	cout << "\nInput b: ";
	cin >> b;
	cout << "\nInput c: ";
	cin >> c;

	double root1 = (-b + sqrt(pow(b, 2) - (4 * a * c))) / (2 * a);
	double root2 = (-b - sqrt(pow(b, 2) - (4 * a * c))) / (2 * a);

	cout << showpoint << setprecision(4) << fixed;
	cout << "\nx = " << root1 << ", " << root2;
    return 0;
}

