#include "Shapes.h"

const float PI = 3.14159f;

void Shape2D::Display() const {
	ShowArea();
}

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
	base = 0;
	height = 0;
}

Rectangle::Rectangle(float base, float height) {
	this->base = base;
	this->height = height;
}

void Rectangle::Scale(float scaleFactor) {
	base *= scaleFactor;
	height *= scaleFactor;
}

float Rectangle::Area() const {
	return base * height;
}

void Rectangle::ShowArea() const {
	cout << "Rectangle:\n\tBase: " << base << "\n\tHeight: " 
		<< height << "\n\tArea: " << Area() << endl;
}

float Rectangle::GetBase() const {
	return base;
}

float Rectangle::GetHeight() const {
	return height;
}

Square::Square() : Rectangle(0, 0) {

}

Square::Square(float side) : Rectangle(side, side) {
}

void Square::ShowArea() const {
	cout << "Square:\n\tSide: " << GetBase() << "\n\tArea: " << Area() << endl;
}

Triangle::Triangle() {
	base = 0;
	height = 0;
}

Triangle::Triangle(float b, float h) {
	base = b;
	height = h;
}

void Triangle::Scale(float scaleFactor) {
	base *= scaleFactor;
	height *= scaleFactor;
}

float Triangle::Area() const {
	return 0.5f * base * height;
}

void Triangle::ShowArea() const {
	cout << "Triangle:\n\tBase: " << base << "\n\tHeight: "
		<< height << "\n\tArea: " << Area() << endl;
}

float Triangle::GetBase() const {
	return base;
}

float Triangle::GetHeight() const {
	return height;
}

Circle::Circle() : Ellipse(0, 0) {
}

Circle::Circle(float r) : Ellipse(r, r) {
}

void Circle::ShowArea() const {
	cout << "Circle:\n\tRadius: " << GetSmaj() << "\n\tArea: " << Area() << endl;
}

float Circle::GetRadius() const {
	return GetSmaj();
}

Ellipse::Ellipse() {
	smaj = 0;
	smin = 0;
}

Ellipse::Ellipse(float maj, float min) {
	smaj = maj;
	smin = min;
}

void Ellipse::Scale(float scaleFactor) {
	smaj *= scaleFactor;
	smin *= scaleFactor;
}

float Ellipse::Area() const {
	return PI * smaj * smin;
}

void Ellipse::ShowArea() const {
	cout << "Ellipse:\n\tSemi-major Axis: " << smaj << "\n\tSemi-minor Axis: "
		<< smin << "\n\tArea: " << Area() << endl;
}

float Ellipse::GetSmaj() const {
	return smaj;
}

Trapezoid::Trapezoid() {
	bottomLength = 0;
	topLength = 0;
	height = 0;
}

Trapezoid::Trapezoid(float bl, float tl, float h) {
	bottomLength = bl;
	topLength = tl;
	height = h;
}

void Trapezoid::Scale(float scaleFactor) {
}

float Trapezoid::Area() const {
	return 0.5f * (bottomLength + topLength) * height;
}

void Trapezoid::ShowArea() const {
	cout << "Trapezoid:\n\tBottom Length: " << bottomLength << "\n\tTop Length: "
		<< topLength << "\n\tHeight" << height << "\n\tArea: " << Area() << endl;
}

Sector::Sector() {
	angle = 0;
	radius = 0;
}

Sector::Sector(float r, float a) {
	radius = r;
	angle = a;
}

void Sector::Scale(float scaleFactor) {
	radius *= scaleFactor;
}

float Sector::Area() const {
	return 0.5f *  pow(radius, 2) * angle;
}

void Sector::ShowArea() const {
	cout << "Sector:\n\tRadius: " << radius << "\n\tAngle: "
		<< angle << "\n\tArea: " << Area() << endl;
}

TriangularPyramid::TriangularPyramid() : Triangle(0, 0) {
	height = 0;
}

TriangularPyramid::TriangularPyramid(float l, float w, float h) : Triangle(l, w) {
	height = h;
}

float TriangularPyramid::Volume() const {
	return (1.f / 3.f) * Triangle::Area() * height;
}

void TriangularPyramid::ShowVolume() const {
	cout << "Triangular Pyramid:\n\tBase: " << Triangle::GetBase() << "\n\tTop Length: "
		<< Triangle::GetHeight() << "\n\tHeight: " << height << "\n\tArea: " << Volume() << endl;
}

void TriangularPyramid::Scale(float scaleFactor) {
}

void Shape3D::Display() const {
	ShowVolume();
}

RectangularPyramid::RectangularPyramid() : Rectangle(0, 0) {
	height = 0;
}

RectangularPyramid::RectangularPyramid(float l, float w, float h) : Rectangle(l, w) {
	height = h;
}

void RectangularPyramid::Scale(float scaleFactor) {
}

float RectangularPyramid::Volume() const {
	return (1.f / 3.f) * Rectangle::Area() * height;
}

void RectangularPyramid::ShowVolume() const {
	cout << "Triangular Pyramid:\n\tLength: " << Rectangle::GetBase() << "\n\tWidth: "
		<< Rectangle::GetHeight() << "\n\tHeight: " << height << "\n\tVolume: " << Volume() << endl;
}

Cylinder::Cylinder() : Circle(0) {
	height = 0;
}

Cylinder::Cylinder(float r, float h) : Circle(r) {
	height = h;
}

void Cylinder::Scale(float scaleFactor) {
}

float Cylinder::Volume() const {
	return PI * pow(Circle::GetRadius(), 2) * height;
}

void Cylinder::ShowVolume() const {
	cout << "Cylinder:\n\tRadius: " << Circle::GetRadius() << "\n\tHeight: "
		 << height << "\n\tVolume: " << Volume() << endl;
}

Sphere::Sphere() : Circle(0) {
}

Sphere::Sphere(float r) : Circle(r) {
}

void Sphere::Scale(float scaleFactor) {
}

float Sphere::Volume() const {
	return (4.f / 3.f) * PI * pow(Circle::GetRadius(), 3);
}

void Sphere::ShowVolume() const {
}
