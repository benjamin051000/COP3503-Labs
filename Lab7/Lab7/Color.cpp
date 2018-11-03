#include "Color.h"

void Color::SetName(string newName) {
	name = newName;
}

void Color::SetValue(int newValue) {
	b = newValue & 255; // b is the last 8 digits of newValue
	newValue >> 8; // shift right 8 bits
	g = newValue & 255;
	newValue >> 8;
	r = newValue & 255;
}

unsigned char Color::GetR() const {
	return r;
}

unsigned char Color::GetG() const {
	return g;
}

unsigned char Color::GetB() const {
	return b;
}

string Color::GetHexValue() const {
	return string();
}

string Color::GetName() const {
	return string();
}
