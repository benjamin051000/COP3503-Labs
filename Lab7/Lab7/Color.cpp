#include "Color.h"

string Color::getHexRep(uint8_t input) const {
	switch (input) {
	case 10: return "A";
		break;
	case 11: return "B";
		break;
	case 12: return "C";
		break;
	case 13: return "D";
		break;
	case 14: return "E";
		break;
	case 15: return "F";
		break;
	default: return to_string(input);
	}
}

void Color::SetName(string newName) {
	name = newName;
}

void Color::SetValue(int newValue) {
	value = newValue;
}

unsigned char Color::GetR() const {
	return value >> 16 & 255;
}

unsigned char Color::GetG() const {
	return value >> 8 & 255;
}

unsigned char Color::GetB() const {
	return value & 255;
}

string Color::GetHexValue() const {
	uint8_t r = GetR(), g = GetG(), b = GetB(); //essentially unsigned chars (8-bit u ints)
	string hexValue = "#";

	/* (val / 16) is the tens place in hex,
	(val % 16) is the ones place.*/
	hexValue += getHexRep(r / 16) + getHexRep(r % 16);
	hexValue += getHexRep(g / 16) + getHexRep(g % 16);
	hexValue += getHexRep(b / 16) + getHexRep(b % 16);
	return hexValue;
}

string Color::GetName() const {
	return name;
}
