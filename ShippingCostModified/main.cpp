//*********************************************************************
// File name:			main.cpp
// Author:				chris lane
// Date:					Sept 14, 2022
// Class:					CS 150-01
// Assignment:		In Class Practice
// Purpose:				Practice with single-alternative ifs, nesting
// Hours Worked:	0.1
//*********************************************************************
#include <iostream>
#include <iomanip>

using namespace std;

int main() {

	double order;
	int shippingCost;

	const int HIGH_SHIPPING_CUTOFF = 30;
	const int LOW_SHIPPING_CUTOFF = 50;  

	const int HIGH_SHIPPING_COST = 5;
	const int MODERATE_SHIPPING_COST = 3;
	const int LOW_SHIPPING_COST = 2;   

	cout << "Enter order amount in dollars: $";
	cin >> order;

	if (order <= HIGH_SHIPPING_CUTOFF) {
		shippingCost = HIGH_SHIPPING_COST;
	}

	// Can do this using a NESTED if statement
	//if (order > HIGH_SHIPPING_CUTOFF) {
	//	if (order < LOW_SHIPPING_CUTOFF) {
	//		shippingCost = MODERATE_SHIPPING_COST;
	//	}

	//	if (order >= LOW_SHIPPING_CUTOFF) {
	//		shippingCost = LOW_SHIPPING_COST;
	//	}
	//}

	// Can also do this using compound statement && (AND)
	if (order > HIGH_SHIPPING_CUTOFF && order < LOW_SHIPPING_CUTOFF) {
		shippingCost = MODERATE_SHIPPING_COST;
	}

	if (order > HIGH_SHIPPING_CUTOFF && order >= LOW_SHIPPING_CUTOFF) {
		shippingCost = LOW_SHIPPING_COST; 
	}

	cout << "The shipping cost is: $" << shippingCost;

	return EXIT_SUCCESS;
}