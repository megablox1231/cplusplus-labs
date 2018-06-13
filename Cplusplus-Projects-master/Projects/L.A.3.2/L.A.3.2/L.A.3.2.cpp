// L.A.3.2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string make;
	string model;
	char letter1;
	char letter2;
	char letter3;
	int num;

	cout << "Enter in the make: ";
	cin >> make;
	cout << "Enter in the model: ";
	cin >> model;
	cout << "Enter in the license plate: ";
	cin >> letter1 >> letter2 >> letter3 >> num;

	int sum = letter1 + letter2 + letter3 + num;
	char front = 65 + (sum % 26);
	string plate = (string)"" + letter1 + letter2 + letter3 + ' ';

	cout << "\nMake = " << make << endl;
	cout << "Model = " << model << endl;
	cout << plate << num << " = " << front << sum;

    return 0;
}

