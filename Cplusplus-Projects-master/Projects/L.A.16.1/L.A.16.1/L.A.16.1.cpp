// L.A.16.1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include "Apvector.h"
#include <fstream>
#include <iostream>
#include <iomanip>

int findCount(std::string fileName);
void fillVector(apvector<int> &nums, std::string fileName);
float average(const apvector<int> &nums, int count);
float standardDev(const apvector<int> &nums, float avg, int count);
apvector<int> mode(const apvector<int> &nums, int count);

int main()
{
	int count = findCount("numbers.txt");
	apvector<int> nums(count);
	fillVector(nums, "numbers.txt");
	float avg = average(nums, count);
	float stdDev = standardDev(nums, avg, count);
	apvector<int> modes = mode(nums, count);
	std::cout << std::setprecision(2) << std::fixed;
	std::cout << "The average of the numbers is " << avg << std::endl;
	std::cout << "The standard deviation of the numbers is " << stdDev << std::endl;
	std::cout << "The mode of the numbers is ";
	int length = modes.length();
	for (int i = 0; i < length; i++) {
		if (i == length - 1) {
			std::cout << modes[i] << std::endl;
		}
		else {
			std::cout << modes[i] << ", ";
		}
	}
    return 0;
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

//finds the average of the numbers
float average(const apvector<int> &nums, int count) {
	long int total = 0;
	for (int i = 0; i < count; i++) {
		total += nums[i];
	}
	return (float)(total) / count;
}

/*
	finds the standard deviation of the data

	@parmeters
		nums = the vector of numbers
		avg = the average of the numbers
		count = the number of numbers
	@return
		the standard deviation
*/
float standardDev(const apvector<int> &nums, float avg, int count) {
	float total = 0;
	for (int i = 0; i < count; i++) {
		total += pow((nums[i] - avg), 2);
	}
	return sqrt((total / (count - 1)));
}

apvector<int> mode(const apvector<int>& nums, int count) {
	apvector<int> freqs(101, 0);
	for (int i = 0; i < count; i++) {
		freqs[nums[i]]++;
	}
	int highest = 0;
	int highs = 0;
	int cur;
	for (int i = 1; i < 101; i++) {
		cur = freqs[i];
		if (cur > highest) {
			highest = cur;
			highs = 1;
		}
		else if (cur == highest) {
			highs++;
		}
	}
	apvector<int> modes(highs);
	int slot = 0;
	for (int i = 1; i < 101; i++) {
		if (freqs[i] == highest) {
			modes[slot] = i;
			slot++;
		}
	}
	return modes;
}
