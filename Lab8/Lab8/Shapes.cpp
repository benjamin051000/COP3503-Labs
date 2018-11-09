#include "Shapes.h"

const float PI = 3.14159f;

bool Shape2D::operator>(const Shape2D & rhs) const {
	return false;
}

bool Shape2D::operator<(const Shape2D & rhs) const {
	return false;
}

bool Shape2D::operator==(const Shape2D & rhs) const {
	return false;
}

Rectangle::Rectangle() {
}

Rectangle::Rectangle(float base, float height) {
	this->base = base;
	this->height = height;
}

void Rectangle::Scale(float scaleFactor) {
	base *= scaleFactor;
	height *= scaleFactor;
}

void Rectangle::Display() const {
	cout << "Rectangle:\n Width: " << base << "\nHeight: " 
		<< height << "\nArea: " << Area() << endl;
}

float Rectangle::Area() const {
	return base * height;
}

void Rectangle::ShowArea() const {
	cout << "Area of rectangle: " << Area() << endl;
}

Square::Square() {
}

Square::Square(float side) : Rectangle(side, side) {
	cout << "Square created." << endl;
}

void Square::Scale(float scaleFactor) {
}

void Square::Display() const {
}

float Square::Area() const {
	return 0.0f;
}

void Square::ShowArea() const {
}

Triangle::Triangle() {
}

Triangle::Triangle(float b, float h) {
	base = b;
	height = h;
}

void Triangle::Scale(float scaleFactor) {
}

void Triangle::Display() const {
}

float Triangle::Area() const {
	return 0.5f * base * height;
}

void Triangle::ShowArea() const {
}


Circle::Circle() {
}

Circle::Circle(float r) {
	radius = r;
}

void Circle::Scale(float scaleFactor) {
	r *= scaleFactor;
}

void Circle::Display() const {
}

float Circle::Area() const {
	return PI * radius * radius;
}

void Circle::ShowArea() const {
}


//Circle::~Circle() {
//}

Ellipse::Ellipse() {
}

Ellipse::Ellipse(float maj, float min) {
	smaj = maj;
	smin = min;
}

void Ellipse::Scale(float scaleFactor) {
	smaj *= scaleFactor;
	smin *= scaleFactor;
}

void Ellipse::Display() const {
}

float Ellipse::Area() const {
	return PI * smaj * smin;
}

void Ellipse::ShowArea() const {
}

Trapezoid::Trapezoid() {
}

Trapezoid::Trapezoid(float bl, float tl, float h) {
	bottomLength = bl;
	topLength = tl;
	height = h;
}

void Trapezoid::Scale(float scaleFactor) {
}

void Trapezoid::Display() const {
}

float Trapezoid::Area() const {
	return 0.5f * (bottomLength + topLength) * height;
}

void Trapezoid::ShowArea() const {
}
