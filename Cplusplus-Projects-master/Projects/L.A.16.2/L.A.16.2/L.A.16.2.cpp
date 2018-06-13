// L.A.16.2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "apvector.h"
#include <fstream>
#include <iostream>

void  compact(apvector<int> &list, int  &N);
int findCount(std::string fileName);
void fillVector(apvector<int> &nums, std::string fileName);
void printVector(apvector<int> &nums, int &N);

int main()
{
	int count = findCount("compact.txt");
	apvector<int> nums(count);
	fillVector(nums, "compact.txt");

	std::cout << "Before:  ";
	printVector(nums, count);
	std::cout << std::endl;

	compact(nums, count);

	std::cout << "After:  ";
	printVector(nums, count);
	std::cout << std::endl;
    return 0;
}

/*
	remove the zeros from the vector by traversing the vector and if a 0 is found,
	it is switched with the next number that is not 0. 0's are counted up and placed at the
	end then vector is resized to remove them.
*/
void compact(apvector<int>& list, int & N) {
	bool afterZero = false;
	int zeros = 0;
	int slot;
	for (int i = 0; i < N; i++) {
		if (list[i] == 0) {
			slot = i;
			while (slot < N) {
				if (list[slot] != 0) {
					list[i] = list[slot];
					list[slot] = 0;
					zeros++;
					slot = N;
				}
				else if(slot == N - 1) {
					zeros += N - (zeros + i);
					i = N;
				}
				slot++;
			}
		}
	}
	list.resize(N - zeros);
	N = list.length();
}

//finds how many numbers are in the file
int findCount(std::string fileName) {
	std::ifstream inFile(fileName, std::ios::in);
	int num;
	int count = 0;
	while (inFile >> num) {
		count++;
	}
	return count;
}

//fills the vector with the numbers
void fillVector(apvector<int>& nums, std::string fileName) {
	std::ifstream inFile(fileName, std::ios::in);
	int num;
	int count = 0;
	while (inFile >> num) {
		nums[count] = num;
		count++;
	}
}

void printVector(apvector<int>& nums, int & N) {
	for (int i = 0; i < N; i++) {
		if (i == N - 1) {
			std::cout << nums[i] <<  std::endl;
		}
		else {
			std::cout << nums[i] << ", ";
		}
	}
}
