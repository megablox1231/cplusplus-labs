// L.A.10.2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>

void input(double &, double &, double &);
void print(double, double, double);

int main()
{
	double prin;
	double rate;
	double monthly;
	input(prin, rate, monthly);
	print(prin, rate, monthly);
    return 0;
}

void input(double &prin, double &rate, double &monthly) {
	std::cout << "Enter in the Principal: ";
	std::cin >> prin;
	std::cout << "\nEnter in the Annual Interest Rate: ";
	std::cin >> rate;
	std::cout << "\nEnter in the Monthly Payment: ";
	std::cin >> monthly;
}

/*
calculate the monthly rate
start the loop
	do the calcuations
	print it
check if the balance below payment
print total interest
*/
void print(double prin, double rate, double monthly) {
	int month = 1;
	double balance;
	double interest;
	double totI = 0;
	rate /= 100;
	rate /= 12;
	std::cout << "\nMonth     Principal     Interest     Payment     New Balance\n" << std::endl;
	std::cout << std::setiosflags(std::ios::right) << std::setiosflags(std::ios::fixed) << std::setprecision(2);
	do {
		interest = prin * rate;
		totI += interest;
		balance = prin + interest - monthly;
		std::cout << std::setw(5) << month << std::setw(14) << prin << std::setw(13) << interest << std::setw(12) << monthly << std::setw(16) << balance << std::endl;
		prin = balance;
		month++;
	} while (balance > monthly);
	std::cout << std::endl;
	std::cout << "                 " << totI << "     total interest" << std::endl;
}
