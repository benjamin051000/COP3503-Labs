#pragma once
#include <math.h>
#include <iostream>
using namespace std;

class Shape {
	virtual void Scale(float scaleFactor) = 0;
	virtual void Display() const = 0;
};

class Shape2D : public Shape {
	virtual float Area() const = 0;
	virtual void ShowArea() const = 0;
	bool operator>(const Shape2D& rhs) const;
	bool operator<(const Shape2D& rhs) const;
	bool operator==(const Shape2D& rhs) const;
};

class Rectangle : public Shape2D {
	float base, height;
public:
	Rectangle();
	Rectangle(float base, float height);

	void Scale(float scaleFactor);
	void Display() const;
	float Area() const;
	void ShowArea() const;
};

class Square : public Rectangle {
public:
	Square();
	Square(float side);
	void Scale(float scaleFactor);
	void Display() const;
	float Area() const;
	void ShowArea() const;
};

class Triangle : public Shape2D {
	float base, height;
public:
	Triangle();
	Triangle(float b, float h);

	void Scale(float scaleFactor);
	void Display() const;
	float Area() const;
	void ShowArea() const;
};

class Ellipse : public Shape2D {
	float smaj, smin;
public:
	Ellipse();
	Ellipse(float maj, float min);

	void Scale(float scaleFactor);
	void Display() const;
	float Area() const;
	void ShowArea() const;
};

class Circle : public Ellipse {
	float radius;
public:
	Circle();
	Circle(float r);

	void Scale(float scaleFactor);
	void Display() const;
	float Area() const;
	void ShowArea() const;
};

class Trapezoid : public Shape2D {
	float bottomLength, topLength, height;
public:
	Trapezoid();
	Trapezoid(float bl, float tl, float h);

	void Scale(float scaleFactor);
	void Display() const;
	float Area() const;
	void ShowArea() const;
};