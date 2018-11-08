#pragma once
#include <math.h>

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
	float width, height;
public:
	Rectangle(float width, float height);

	void Scale(float scaleFactor);
	void Display() const;
	float Area() const;
	void ShowArea() const;
};

class Square : public Rectangle {
	float side;
public:
	Square(float side);
	void Scale(float scaleFactor);
	void Display() const;
	float Area() const;
	void ShowArea() const;
};