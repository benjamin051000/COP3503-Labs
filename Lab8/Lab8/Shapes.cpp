#include "Shapes.h"

const float PI = 3.14159f;

Shape::~Shape() {}

bool Shape2D::operator>(const Shape2D& rhs) const {
	return this->Area() > rhs.Area();
}

bool Shape2D::operator<(const Shape2D & rhs) const {
	return this->Area() < rhs.Area();
}

bool Shape2D::operator==(const Shape2D & rhs) const {
	return this->Area() == rhs.Area();
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
	cout << "The area of the Rectangle is : " << Area() << endl;
}

void Rectangle::Display() const {
	ShowArea();
	cout << "Length: " << base << "\nWidth: " << height << endl;
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
	cout << "The area of the Square is : " << Area() << endl;
}

void Square::Display() const {
	ShowArea();
	cout << "Length of side: " << Rectangle::GetBase() << endl;
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
	cout << "The area of the Triangle is : " << Area() << endl;
}

void Triangle::Display() const {
	ShowArea();
	cout << "Base: " << base << "\nHeight: " << height << endl;
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
	cout << "The area of the Circle is : " << Area() << endl;
}

void Circle::Display() const {
	ShowArea();
	cout << "Radius: " << GetSmaj() << endl;
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
	cout << "The area of the Ellipse is : " << Area() << endl;
}

void Ellipse::Display() const {
	ShowArea();
	cout << "Length of semi-major axis: " << smaj
		<< "\nLength of semi-minor axis: " << smin << endl;
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
	bottomLength *= scaleFactor;
	topLength *= scaleFactor;
	height *= scaleFactor;
}

float Trapezoid::Area() const {
	return 0.5f * (bottomLength + topLength) * height;
}

void Trapezoid::ShowArea() const {
	cout << "The area of the Trapezoid is : " << Area() << endl;
}

void Trapezoid::Display() const {
	ShowArea();
	cout << "Length of side A: " << bottomLength <<
		"\nLength of side B: " << topLength << "\nHeight: " << height << endl;
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
	angle *= scaleFactor;
}

float Sector::Area() const {
	return 0.5f *  pow(radius, 2) * GetRads();
}

void Sector::ShowArea() const {
	cout << "The area of the Sector is : " << Area() << endl;
}

void Sector::Display() const {
	ShowArea();
	cout << "Radius: " << radius << "\nAngle in radians: " << GetRads()
		<< "\nAngle in degrees: " << angle << endl;
}

float Sector::GetRads() const {
	return angle * PI / 180.f;
}

TriangularPyramid::TriangularPyramid() : Triangle(0, 0) {
	height = 0;
}

TriangularPyramid::TriangularPyramid(float h, float l, float w) : Triangle(l, w) {
	height = h;
}

float TriangularPyramid::Volume() const {
	return (1.f / 3.f) * Triangle::Area() * height;
}

void TriangularPyramid::ShowVolume() const {
	cout << "The volume of the Triangular Pyramid is : " << Volume() << endl;
}

void TriangularPyramid::Display() const {
	ShowVolume();
	cout << "The height is: " << height << endl;
	Triangle::Display();
}

void TriangularPyramid::Scale(float scaleFactor) {
	Triangle::Scale(scaleFactor);
	height *= scaleFactor;
}

bool Shape3D::operator>(const Shape3D& rhs) const {
	return this->Volume() > rhs.Volume();
}

bool Shape3D::operator<(const Shape3D& rhs) const {
	return this->Volume() < rhs.Volume();
}

bool Shape3D::operator==(const Shape3D& rhs) const {
	return this->Volume() == rhs.Volume();
}

RectangularPyramid::RectangularPyramid() : Rectangle(0, 0) {
	height = 0;
}

RectangularPyramid::RectangularPyramid(float h, float l, float w) : Rectangle(l, w) {
	height = h;
}

void RectangularPyramid::Scale(float scaleFactor) {
	Rectangle::Scale(scaleFactor);
	height *= scaleFactor;
}

float RectangularPyramid::Volume() const {
	return (1.f / 3.f) * Rectangle::Area() * height;
}

void RectangularPyramid::ShowVolume() const {
	cout << "The volume of the Rectangular Pyramid is : " << Volume() << endl;
}

void RectangularPyramid::Display() const {
	ShowVolume();
	cout << "The height is: " << height << endl;
	Rectangle::Display();
}

Cylinder::Cylinder() : Circle(0) {
	height = 0;
}

Cylinder::Cylinder(float h, float r) : Circle(r) {
	height = h;
}

void Cylinder::Scale(float scaleFactor) {
	Circle::Scale(scaleFactor);
	height *= scaleFactor;
}

float Cylinder::Volume() const {
	return PI * pow(Circle::GetRadius(), 2) * height;
}

void Cylinder::ShowVolume() const {
	cout << "The volume of the Cylinder is : " << Volume() << endl;
}

void Cylinder::Display() const {
	ShowVolume();
	cout << "The height is: " << height << endl;
	Circle::Display();
}

Sphere::Sphere() : Circle(0) {
}

Sphere::Sphere(float r) : Circle(r) {
}

void Sphere::Scale(float scaleFactor) {
	Circle::Scale(scaleFactor);
}

float Sphere::Volume() const {
	return (4.f / 3.f) * PI * pow(Circle::GetRadius(), 3);
}

void Sphere::ShowVolume() const {
	cout << "The volume of the Sphere is : " << Volume() << endl;
}

void Sphere::Display() const {
	ShowVolume();
	Circle::Display();
}
