#include "Color.h"

void Color::SetName(string newName) {
	name = newName;
}

void Color::SetValue(int newValue) {
	value = newValue;
}

unsigned char Color::GetR() const {
	int val = value >> 16;
	return val & 255;
}

unsigned char Color::GetG() const {
	int val = value >> 8;
	return val & 255;
}

unsigned char Color::GetB() const {
	return value & 255;
}

string Color::GetHexValue() const {
	return string();
}

string Color::GetName() const {
	return name;
}
