// L.A.7.1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


void get2Values(int &, int &);
void get2Values(double &, double &);
void print2Values(const int &, const int &);
void print2Values(const double &, const double &);
template <class type>
void swap(type &, type &);

int main()
{
	int integer1;
	int integer2;
	double doub1;
	double doub2;

	get2Values(integer1, integer2);
	get2Values(doub1, doub2);

	std::cout << "The two integers before swapping: ";
	print2Values(integer1, integer2);
	std::cout << "The two doubles before swapping: ";
	print2Values(doub1, doub2);

	swap(integer1, integer2);
	swap(doub1, doub2);

	std::cout << "\nThe two integers after swapping: ";
	print2Values(integer1, integer2);
	std::cout << "The two doubles after swapping: ";
	print2Values(doub1, doub2);
    return 0;
}

void get2Values(int &num1, int &num2) {
	std::cout << "Enter in 1st integer: ";
	std::cin >> num1;
	std::cout << "\nEnter in 2nd integer: ";
	std::cin >> num2;
	std::cout << std::endl;
}

void get2Values(double &num1, double &num2) {
	std::cout << "Enter in 1st double: ";
	std::cin >> num1;
	std::cout << "\nEnter in 2nd double: ";
	std::cin >> num2;
	std::cout << std::endl;
}

void print2Values(const int &num1, const int &num2) {
	std::cout << num1;
	std::cout << "  " << num2 << std::endl;
}

void print2Values(const double &num1, const double &num2) {
	std::cout << num1;
	std::cout << "  " << num2 << std::endl;
}

template <class type>
void swap(type &num1, type &num2) {
	type temp = num1;
	num1 = num2;
	num2 = temp;
}