// L.A.9.1.cpp : Defines the entry podouble for the console application.
//

#include "stdafx.h"
#include <math.h>
#include <iostream>
#include <iomanip>

void prompt(double &, double &, double &, double &);
void output(double, double, double, double);

int main()
{
	double prin;
	double years, low, high;
	prompt(prin, years, low, high);
	output(prin, years, low, high);
    return 0;
}

void prompt(double &prin, double &years, double &low, double &high) {
	std::cout << "Enter in Time in years: ";
	std::cin >> years;
	std::cout << "\nEnter in Principal : ";
	std::cin >> prin;
	std::cout << "\nEnter in Low Rate in % : ";
	std::cin >> low;
	std::cout << "\nEnter in High Rate in % : ";
	std::cin >> high;
}

void output(double prin, double years, double low, double high) {
	std::cout << std::fixed << std::setprecision(2);
	std::cout << "\nTime = " << years << " years" << std::endl;
	std::cout << "Principal = " << prin << std::endl;
	std::cout << "Low Rate = " << low << "%" << std::endl;
	std::cout << "High Rate = " << high << "%" << std::endl;
	std::cout << "\nAnnual Interest Rate\tMonthly Payment" << std::endl;

	double rate = low / 100;
	high /= 100;
	double payment;
	double monthly;
	double c;
	while (rate <= high + .000001) {
		monthly = rate / 12.0;
		 c = pow(1 + monthly, years * 12);
		payment = (prin * monthly * c) / (c - 1);
		std::cout << "\t" << rate * 100 << "\t\t   " << payment << std::endl;
		rate += .0025;
	}
}