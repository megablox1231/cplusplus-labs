// L.A.3.1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "iomanip"

using namespace std;

int main()
{
	double cost;
	double amtPaid;
	cout << "Amount of purchase = ";
	cin >> cost;
	cout << "\nCash tendered = ";
	cin >> amtPaid;
	cout << "\nAmount of coins needed:\n" << endl;
	double change = amtPaid - cost;
	change = change - int(change) + .0001;
	change = int(change * 100);
	cout << setw(3) << change << " cents =\n" << endl;

	//Calculating change needed
	int quarters = change / 25;
	change -= quarters * 25;
	int dimes = change / 10;
	change -= dimes * 10;
	int nickels = change / 5;
	change -= nickels * 5;
	
	cout << setw(2) << quarters << " quarters" << endl;
	cout << setw(2) << dimes << " dimes" << endl;
	cout << setw(2) << nickels << " nickels" << endl;
	cout << setw(2) << change << " pennies" << endl;
    return 0;
}

