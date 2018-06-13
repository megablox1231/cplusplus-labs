// L.A.8.1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>

double calcTax(std::string, double);

int main()
{
	std::string status;
	double taxable;
	std::cout << "Enter filing status: ";
	std::cin >> status;
	std::cout << "\nEnter taxable income: ";
	std::cin >> taxable;

	double taxes = calcTax(status, taxable);

	std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(2); //can just std::fixed too
	std::cout << std::endl << status << std::endl;
	std::cout << "Taxable income = $" << taxable << std::endl;
	std::cout << "Federal tax = $" << taxes;
    return 0;
}

double calcTax(std::string status, double taxable) {
	double taxes;
	if (status == "Single") {
		if (taxable <= 24650) {
			taxes = .15 * taxable;
		}
		else if (taxable <= 59750) {
			taxes = 3697.50 + .28 * (taxable - 24650);
		}
		else {
			taxes = 22532 + .31 * (taxable - 59750);
		}
	}
	if (status == "Married") {
		if (taxable <= 41200) {
			taxes = .15 * taxable;
		}
		else if (taxable <= 99600) {
			taxes = 6180 + .28 * (taxable - 41200);
		}
		else {
			taxes = 22532 + .31 * (taxable - 99600);
		}
	}
	return taxes;
}