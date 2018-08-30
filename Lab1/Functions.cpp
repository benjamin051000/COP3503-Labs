#include "pch.h"
#include "Functions.h"
#include <iostream>
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
}

void CreditCardValidator()
{

}

void GradeCalculator()
{

}
