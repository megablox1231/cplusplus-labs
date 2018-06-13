// L.A.13.1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int fiboR(int);
int fiboI(int);
int mult(int, int);

int main()
{
	std::cout << "fib (0) = " << fiboR(0) << std::endl;
	std::cout << "fib (3) = " << fiboR(3) << std::endl;
	std::cout << "fib (11) = " << fiboR(11) << std::endl;

	std::cout << "\nnonRecFib (1) = " << fiboI(1) << std::endl;
	std::cout << "nonRecFib (5) = " << fiboI(5) << std::endl;
	std::cout << "nonRecFib (14) = " << fiboI(14) << std::endl;

	std::cout << "\nmult (0,4) = " << mult(0,4) << std::endl;
	std::cout << "mult (3,1) = " << mult(3,1) << std::endl;
	std::cout << "mult (7,8) = " << mult(7,8) << std::endl;
	std::cout << "mult (5,0) = " << mult(5,0) << std::endl;
    return 0;
}

//recursive fibonacci method
int fiboR(int num) {
	if (num == 0) {
		return 0;
	}
	if (num == 1) {
		return 1;
	}
	return fiboR(num - 1) + fiboR(num - 2);
}

/**
	iterative fibonacci method

	@param num the position of the fibonacci number
	@return the fibonacci number at position digit
*/
int fiboI(int num) {
	int prevSum = 0;
	int tempSum = 0;
	int curSum = 0;
	for (int i = 0; i <= num; i++) {
		if (i == 1) {
			curSum++;
		}
		else {
			tempSum = curSum;
			curSum = curSum + prevSum;
			prevSum = tempSum;
		}
	}
	return curSum;
}

//  solves for (a * b) by recursively adding a, b times.
//  precondition:  0 <= a <= 10;  0 <= b <= 10.
int mult(int a, int b) {
	if (b == 0) {
		return 0;
	}
	return mult(a, b - 1) + a;
}