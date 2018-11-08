#include "Shapes.h"

bool Shape2D::operator>(const Shape2D & rhs) const {
	return false;
}

bool Shape2D::operator<(const Shape2D & rhs) const {
	return false;
}

bool Shape2D::operator==(const Shape2D & rhs) const {
	return false;
}

Rectangle::Rectangle(float width, float height) {
	this->width = width;
	this->height = height;
}

void Rectangle::Scale(float scaleFactor) {
}

void Rectangle::Display() const {
}

float Rectangle::Area() const {
	return width * height;
}

void Rectangle::ShowArea() const {
}
