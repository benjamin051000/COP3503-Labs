#pragma once
#include <string>
using namespace std;

class Color {
	string name; //Called a const char in the pdf. Is this important? Prob not
	unsigned char r, g, b;

public:
	void SetName(string newName);
	void SetValue(int newValue);

	//Accessors
	unsigned char GetR() const;
	unsigned char GetG() const;
	unsigned char GetB() const;
	string GetHexValue() const;
	string GetName() const;
};