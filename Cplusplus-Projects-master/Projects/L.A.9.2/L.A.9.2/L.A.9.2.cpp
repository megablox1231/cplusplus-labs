// L.A.9.2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

void magicsquare(int);
long int reverse(long int);
int lcm(int, int);

int main()
{
	magicsquare(4);
	std::cout << "12345 reversed ---> " << reverse(12345) << std::endl;
	std::cout << "10001 reversed ---> " << reverse(10001) << std::endl;
	std::cout << "1200 reversed ---> " << reverse(1200) << std::endl;
	std::cout << "5 reversed ---> " << reverse(5) << std::endl << std::endl;
	std::cout << "LCM (15,18) = " << lcm(15, 18) << std::endl;
	std::cout << "LCM (40,12) = " << lcm(40, 12) << std::endl;
	std::cout << "LCM (2,7) = " << lcm(2, 7) << std::endl;
	std::cout << "LCM (100,5) = " << lcm(100, 5) << std::endl;
    return 0;
}

void magicsquare(int num) {
	std::cout << "The first " << num << " magic squares are : ";
	long int i = 1;
	long int square;
	long int sum;
	long int add;
	int count = 0;
	do {
		add = 1;
		square = pow(i, 2);
		do {
			sum = 0;
			for (int i = add; i >= 0; i--) {
				sum += i;
			}
			if (sum == square) {
				std::cout << square << " ";
				count++;
			}
			add++;
		} while (sum < square);
		i++;
	} while (count < num);
	std::cout << std::endl << std::endl;
}

long int reverse(long int num) {
	long int flip = 0;
	while (num > 0) {
		flip = flip * 10 + num % 10;
		num /= 10;
	}
	return flip;
}

int lcm(int num1, int num2){
	int mult1 = num1;
	int mult2 = num2;
	while (mult1 != mult2) {
		while (mult1 < mult2) {
			mult1 += num1;
		}
		while (mult2 < mult1) {
			mult2 += num2;
		}
	}
	return mult1;
}