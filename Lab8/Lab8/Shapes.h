#pragma once
#include <math.h>
#include <iostream>
using namespace std;

class Shape {
public:
	virtual void Scale(float scaleFactor) = 0;
	virtual void Display() const = 0;
	virtual ~Shape() = 0;
};

class Shape2D : public Shape {
public:
	virtual float Area() const = 0;
	virtual void ShowArea() const = 0;

	bool operator>(const Shape2D& rhs) const;
	bool operator<(const Shape2D& rhs) const;
	bool operator==(const Shape2D& rhs) const;
	~Shape2D() {}
};

class Rectangle : public Shape2D {
	float base, height;
public:
	Rectangle();
	Rectangle(float base, float height);

	void Scale(float scaleFactor);
	float Area() const;
	void ShowArea() const;
	void Display() const;
	float GetBase() const;
	float GetHeight() const;
};

class Square : public Rectangle {
public:
	Square();
	Square(float side);
	void ShowArea() const;
	void Display() const;
};

class Triangle : public Shape2D {
	float base, height;
public:
	Triangle();
	Triangle(float b, float h);

	void Scale(float scaleFactor);
	float Area() const;
	void ShowArea() const;
	void Display() const;
	float GetBase() const;
	float GetHeight() const;
};

class Ellipse : public Shape2D {
	float smaj, smin;
public:
	Ellipse();
	Ellipse(float maj, float min);

	void Scale(float scaleFactor);
	float Area() const;
	void ShowArea() const;
	void Display() const;
	float GetSmaj() const;
};

class Circle : public Ellipse {
public:
	Circle();
	Circle(float r);
	void ShowArea() const;
	void Display() const;
	//Area() and Scale() taken care of in Ellipse class

	float GetRadius() const;
};

class Trapezoid : public Shape2D {
	float bottomLength, topLength, height;
public:
	Trapezoid();
	Trapezoid(float bl, float tl, float h);

	void Scale(float scaleFactor);
	float Area() const;
	void ShowArea() const;
	void Display() const;
};

class Sector : public Shape2D {
	float angle, radius;
public:
	Sector();
	Sector(float r, float a);

	void Scale(float scaleFactor);
	float Area() const;
	void ShowArea() const;
	void Display() const;

	float GetRads() const;
};

//////////////////////////////////////////////////////////////////////


class Shape3D : public Shape {//should this be virtual public?
	public:
		virtual float Volume() const = 0;
		virtual void ShowVolume() const = 0;		

		bool operator>(const Shape3D& rhs) const;
		bool operator<(const Shape3D& rhs) const;
		bool operator==(const Shape3D& rhs) const;
		~Shape3D() {}
};

class TriangularPyramid : public Shape3D, private Triangle {
	float height;
public:
	TriangularPyramid();
	TriangularPyramid(float base, float height, float length);

	void Scale(float scaleFactor);
	float Volume() const;
	void ShowVolume() const;
	void Display() const;
};

class RectangularPyramid : public Shape3D, private Rectangle {
	float height;
public:
	RectangularPyramid();
	RectangularPyramid(float l, float w, float h);

	void Scale(float scaleFactor);
	float Volume() const;
	void ShowVolume() const;
	void Display() const;
};

class Cylinder : public Shape3D, private Circle {
	float height;
public:
	Cylinder();
	Cylinder(float r, float h);

	void Scale(float scaleFactor);
	float Volume() const;
	void ShowVolume() const;
	void Display() const;
};

class Sphere : public Shape3D, private Circle {
public:
	Sphere();
	Sphere(float r);

	void Scale(float scaleFactor);
	float Volume() const;
	void ShowVolume() const;
	void Display() const;
};