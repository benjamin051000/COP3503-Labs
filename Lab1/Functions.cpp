#include "pch.h"
#include "Functions.h"
#include <iostream>
#include <math.h>
using namespace std;

void menu()
{
	int input;
	bool validInput = false;
	
	while (!validInput)
	{
		cout << "1. Quadratic Root\n2. Grade Calculator\n3. Credit Card Validator\nEnter a number:\n";
		cin >> input;
		
		if (cin && input >= 1 && input <= 3)
		{
			validInput = true;
		}
		else
		{
			//Clear cin and start over
			cout << "\nPlease enter an integer between 1 and 3." << endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}

	//input is certainly either 1, 2, or 3 at this point
	//Apply the cooresponding function
	switch (input)
	{
	case 1: QuadraticRoot();
		break;
	case 2: GradeCalculator();
		break;
	case 3: CreditCardValidator();
		break;
	default: cout << "Something went wrong.";
	}
}

void QuadraticRoot()
{
	cout << "Enter a, b, c: ";
	double a, b, c;
	cin >> a; //Check if they're integers?
	cin >> b;
	cin >> c;

	//Compute discriminant
	double discriminant = b * b - 4 * a * c; //Faster than pow(b, 2)
	bool twoRoots = false;

	if (discriminant > 0) {
		cout << "The equation has two roots: ";
		twoRoots = true;
	}
	else if (discriminant == 0) {
		cout << "The equation has one root: ";
	}
	else {
		cout << "The equation has no real roots";
		return;
	}

	//Compute the roots
	//Positive root
	double posRoot = (-b + sqrt(discriminant)) / 2 * a;
	cout << posRoot;

	//Negative root
	if (twoRoots) {
		double negRoot = (-b - sqrt(discriminant)) / 2 * a;
		cout << " and " << negRoot;
	}
	cout << endl;
}

void GradeCalculator()
{

}

void CreditCardValidator()
{
	
}