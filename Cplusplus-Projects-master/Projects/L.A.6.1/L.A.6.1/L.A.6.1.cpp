// L.A.6.1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<iomanip>

using namespace std;

const double PI = 3.14159265359;

double fToC(double fare);
double cToF(double cel);
double vSphere(double radius);
double hypot(double, double);

int main()
{
	cout << setiosflags(ios::showpoint) << fixed << setprecision(2);
	cout << "212 degrees F ---> " << fToC(212) << " degrees C" << endl;
	cout << "98.6 degrees F ---> " << fToC(98.6) << " degrees C" << endl;
	cout << "10 degrees F ---> " << fToC(10) << " degrees C" << endl;
	cout << "-15 degrees C ---> " << cToF(-15) << " degrees F" << endl;
	cout << "0 degrees C ---> " << cToF(0) << " degrees F" << endl;
	cout << "70 degrees C ---> " << cToF(70) << " degrees F" << endl;
	cout << "Radius of 1.0 ---> Volume of " << vSphere(1.0) << endl;
	cout << "Radius of 2.25 ---> Volume of " << vSphere(2.25) << endl;
	cout << "Radius of 7.50 ---> Volume of " << vSphere(7.50) << endl;
	cout << "Sides of 3.0 and 4.0 ---> Hypotenuse of " << hypot(3.0, 4.0) << endl;
	cout << "Sides of 6.75 and 12.31 ---> Hypotenuse of " << hypot(6.75, 12.31) << endl;
    return 0;
}

double fToC(double fare) {
	return (5.0 / 9) * (fare - 32);
}

double cToF(double cel) {
	return (9.0 / 5) * cel + 32;
}

double vSphere(double radius) {
	return (4.0 / 3) * PI * pow(radius, 3);
}

double hypot(double a, double b) {
	return sqrt(pow(a, 2) + pow(b, 2));
}