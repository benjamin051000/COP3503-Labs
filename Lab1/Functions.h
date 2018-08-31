#pragma once

void menu();
void QuadraticRoot();
void CreditCardValidator();
void GradeCalculator();

//Functions that make up CreditCardValidator()

//Return true if the card number is valid.
bool isValid(long long number);

//Get the result of step 2
int sumOfDoubleEvenPlace(long long number);

//Return this number if it is a single digit;
//Otherwise, return the sum of the two digits.
int getDigit(int number);

//Return sum of odd-place digits in number.
int sumOfOddPlace(long long number);

//Return true if the digit is a prefix for this number.
bool prefixMatched(long long number, int digit);

//Return the number ofdigits in number
int getSize(long long number);

//Return the first numDigits digits from number. If the # of
//digits in number is less than numDigits, return number.
long getPrefix(long long number, int numDigits);