#include "pch.h"
#include "Functions.h"
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

void menu()
{
	int input;
	cout << "1. Quadratic Root\n2. Grade Calculator\n3. Credit Card Validator\nEnter a number: ";
	cin >> input;

	if (!cin)
	{
		//it's not an int
		//Clear cin and start over
		cout << "\nInvalid input!";
		cin.clear();
		cin.ignore(1000, '\n');
		return;
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
	default: cout << "\nInput out of range!";
	}
}

void QuadraticRoot()
{
	cout << "Enter a, b, c: \n";
	double a, b, c;
	cin >> a; //Check if they're integers?
	cin >> b;
	cin >> c;

	if (!cin) {
		//Clear cin and start over
		cout << "\nInvalid input!" << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		return;
	}

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
		cout << "The equation has no real roots.";
		return;
	}

	//Compute the roots
	//Positive root
	double posRoot = (-b + sqrt(discriminant)) / (2 * a);
	cout << posRoot;

	//Negative root
	if (twoRoots) {
		double negRoot = (-b - sqrt(discriminant)) / (2 * a);
		cout << " and " << negRoot;
	}
	cout << endl;
}

void GradeCalculator()
{
	cout << "\nEnter the number of students: ";
	int studentNum;
	cin >> studentNum;

	if (!cin) {
		//Clear cin and start over
		cout << "\nInvalid input!" << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		return;
	}

	vector<int> scores(studentNum);
	vector<char> grades(studentNum);

	//cout << "Enter " << studentNum << " scores: ";

	int best = -1;
	for (int i = 0; i < studentNum; i++) {
		cin >> scores[i];
		if (!cin) {
			//Clear cin and start over
			cout << "\nInvalid input!" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			return;
		}
		if (best < scores[i]) {
			best = scores[i];
		}
	}

	for (int i = 0; i < studentNum; i++) {
		if (scores[i] >= best - 10) {
			grades[i] = 'A';
		}
		else if (scores[i] >= best - 20) {
			grades[i] = 'B';
		}
		else if (scores[i] >= best - 30) {
			grades[i] = 'C';
		}
		else if (scores[i] >= best - 40) {
			grades[i] = 'D';
		}
		else {
			grades[i] = 'F';
		}
		cout << "\nStudent " << i + 1 << " - Score: " << scores[i] << ", Letter: " << grades[i];
	}
	cout << endl;
}

void CreditCardValidator()
{
	long long cardNum;
	cout << "\nEnter a credit card number: ";

	cin >> cardNum;

	if (!cin) {
		//Clear cin and start over
		cout << "\nInvalid input!" << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		return;
	}

	if (isValid(cardNum)) {
		cout << cardNum << " is valid.";
	}
	else {
		cout << cardNum << " is invalid.";
	}
}

bool isValid(long long number)
{
	int numSize = getSize(number);

	if (numSize > 16 || numSize < 13) {
		return false;
	}

	int sum = sumOfDoubleEvenPlace(number) + sumOfOddPlace(number);

	if (sum % 10 != 0) {
		return false;
	}

	if (prefixMatched(number, 4) || prefixMatched(number, 5)
		|| prefixMatched(number, 37) || prefixMatched(number, 6)) {
		return true;
	}

	return false;
}

int sumOfDoubleEvenPlace(long long number)
{
	int sum = 0;

	while (number > 0) {
		int digit = (int)((number % 100) / 10);
		number /= 100;

		sum += getDigit(2 * digit);
	}
	return sum;
}

int getDigit(int number)
{
	return (number / 10) + (number % 10);
}

int sumOfOddPlace(long long number)
{
	int sum = 0;
	while (number > 0) {
		int digit = (int)(number % 10);
		number /= 100;

		sum += getDigit(digit);
	}
	return sum;
}

bool prefixMatched(long long number, int digit)
{
	return getPrefix(number, getSize(digit)) == digit;
}

int getSize(long long number)
{
	int digits = 0;
	while (number > 0) {
		number /= 10;
		digits++;
	}
	return digits;
}

long getPrefix(long long number, int numDigits)
{
	int numberSize = getSize(number);

	int decMovements = numberSize - numDigits;

	while (decMovements-- > 0) {
		number /= 10;
	}

	return number;
}