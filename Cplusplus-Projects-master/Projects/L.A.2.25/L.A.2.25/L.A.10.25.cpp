// L.A.10.2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>

void input(double &, double &, double &, int &);
void print(double, double, double, int);

int main()
{
	double prin;
	double rate;
	double monthly;
	int months;
	input(prin, rate, monthly, months);
	print(prin, rate, monthly, months);
	return 0;
}

void input(double &prin, double &rate, double &monthly, int &months) {
	std::cout << "Enter in the starting principal to invest: ";
	std::cin >> prin;
	std::cout << "\nEnter in the annual rate of return: ";
	std::cin >> rate;
	std::cout << "\nEnter in the monthly addition to the principal: ";
	std::cin >> monthly;
	std::cout << "\nEnter in the number of months: ";
	std::cin >> months;
}

/*
calculate the monthly rate
start the loop
do the calcuations
print it
check if the balance below payment
print total interest
*/
void print(double prin, double rate, double monthly, int months) {
	int month = 1;
	double balance;
	double interest;
	double totI = 0;
	rate /= 100;
	rate /= 12;
	std::cout << "\nMonth     Principal     Interest     Investment     New Balance\n" << std::endl;
	std::cout << std::setiosflags(std::ios::right) << std::setiosflags(std::ios::fixed) << std::setprecision(2);
	do {
		interest = prin * rate;
		totI += interest;
		balance = prin + interest + monthly;
		std::cout << std::setw(5) << month << std::setw(14) << prin << std::setw(13) << interest << std::setw(12) << monthly << std::setw(16) << balance << std::endl;
		prin = balance;
		month++;
	} while (month <= months);
	std::cout << std::endl;
	std::cout << "                 " << totI << "     total interest" << std::endl;
	std::cout << "                 " << balance << "     final balance" << std::endl;
}
