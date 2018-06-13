// L.A.4.1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;

const double FEDTAX = .15;
const double FICA = .08;
const double STATETAX = .032;

int main()
{
	int hWork;
	double hRate;
	cout << "Enter in your hours worked: ";
	cin >> hWork;
	cout << "\nEnter in your hourly rate: ";
	cin >> hRate;

	double gross = hWork * hRate;
	double fedTax = gross * FEDTAX;
	double fica = gross * FICA;
	double state = gross * STATETAX;
	double netPay = gross - fedTax - fica - state;

	cout << showpoint << setprecision(2) << fixed;
	cout << "\nHours worked	     " << hWork << endl;
	cout << "Hourly rate       " << hRate << endl;
	cout << "\nGross Pay:       " << gross << endl;
	cout << "\nFederal tax (15%) " << fedTax << endl;
	cout << "FICA (8%)         " << fica << endl;
	cout << "State tax (3.2%)  " << state << endl;
	cout << "\nNet pay          " << netPay;

    return 0;
}

