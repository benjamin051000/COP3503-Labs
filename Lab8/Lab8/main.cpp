// main.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <iomanip>
#include "Shapes.h"
using namespace std;
void TestOne();
void TestTwo();
void TestThree();
void TestFour();
void TestFive();
void TestSix();
void TestSeven();

int main()
{
	cout << std::fixed << setprecision(2);
	int testNum{};
	cin >> testNum;
	
	if (testNum == 1)
		TestOne();
	else if (testNum == 2)
		TestTwo();
	else if (testNum == 3)
		TestThree();
	else if (testNum == 4)
		TestFour();
	else if (testNum == 5)
		TestFive();
	else if (testNum == 6)
		TestSix();
	else if (testNum == 7)
		TestSeven();

	return 0;
}

// Testing default constructors and Display() for basic shapes
void TestOne()
{
	// Basic shapes and their constructors
	Shape *shapes[] =
	{
		new Square,
		new Rectangle,
		new Triangle,
		new Circle,
		new Ellipse,
		new Trapezoid,
		new Sector
	};
	
	for (int i = 0; i < 7; i++)
	{
		shapes[i]->Display();
		cout << endl;
	}
	for (int i = 0; i < 7; i++)
		delete shapes[i];
}

// Testing 
void TestTwo()
{
	Shape *shapes[] =
	{
		new Square(2.4f),
		new Rectangle(3, 5),
		new Triangle(4.2f, 6),
		new Circle(2),
		new Ellipse(1, 3),
		new Trapezoid(2, 6, 2.3f),
		new Sector(2, 35)
	};

	for (int i = 0; i < 7; i++)
	{
		shapes[i]->Display();
		cout << endl;
	}
	for (int i = 0; i < 7; i++)
		delete shapes[i];
}

 //Testing 3D shapes and their default constructors
void TestThree()
{
	Shape *shapes[] =
	{
		(Shape3D *)new TriangularPyramid,
		(Shape3D *)new RectangularPyramid,
		(Shape3D *)new Cylinder,
		(Shape3D *)new Sphere,
	};
	for (int i = 0; i < 4; i++)
	{
		shapes[i]->Display();
		cout << endl;
	}
	for (int i = 0; i < 4; i++)
		delete shapes[i];
}

// Testing 3D shapes and their constructors
void TestFour()
{
	Shape *shapes[] =
	{
		(Shape3D *)new TriangularPyramid(3, 2, 5),
		(Shape3D *)new RectangularPyramid(5.13f, 2, 4),
		(Shape3D *)new Cylinder(4.2f, 6),
		(Shape3D *)new Sphere(1),
	};
	for (int i = 0; i < 4; i++)
	{
		shapes[i]->Display();
		cout << endl;
	}
	for (int i = 0; i < 4; i++)
		delete shapes[i];
}

// Testing all shapes and their Scale() functions
void TestFive()
{
	Shape *shapes[] =
	{
		new Square(1.93f),
		new Rectangle(2.8f, 5.4f),
		new Triangle(3.85f, 6.1f),
		new Circle(3.02f),
		new Ellipse(2.1f, 3.3f),
		new Trapezoid(2, 6, 2.3f),
		new Sector(3, 18),
		(Shape3D *)new TriangularPyramid(4.5f, 1, 4),
		(Shape3D *)new RectangularPyramid(3.23f, 2, 3),
		(Shape3D *)new Cylinder(3.86f, 4),
		(Shape3D *)new Sphere(2.3f),
	};

	for (int i = 0; i < 11; i++)
	{
		shapes[i]->Display();
		cout << endl;
	}
	cout << "Scaling by 2.5..." << endl << endl;
	for (int i = 0; i < 11; i++)
	{
		shapes[i]->Scale(2.5f);
		shapes[i]->Display();
		cout << endl;
	}
	for (int i = 0; i < 11; i++)
		delete shapes[i];

}

void TestSix()
{
	Shape2D *shapes[] =
	{
		new Square(1.93f),
		new Rectangle(2.8f, 5.4f),
		new Triangle(3.85f, 6.1f),
		new Circle(3.02f),
		new Ellipse(2.1f, 3.3f),
		new Trapezoid(2, 6, 2.3f),
		new Sector(3, 18),
	};
	for (int i = 0; i < 7; i++)
		shapes[i]->ShowArea();

	Shape2D *smallestShape = shapes[0];
	Shape2D *largestShape = shapes[0];

	// Find the largest and smallest shapes
	for (int i = 1; i < 7; i++)
	{
		if (*smallestShape > *shapes[i])
			smallestShape = shapes[i];
		if (*largestShape < *shapes[i])
			largestShape = shapes[i];
	}
	cout << endl << "***** The smallest shape *****" << endl;
	smallestShape->Display();
	
	cout << endl << "***** The largest shape *****" << endl;
	largestShape->Display();
	
	for (int i = 0; i < 7; i++)
		delete shapes[i];
}

void TestSeven()
{
	Shape3D *shapes[] =
	{
		new TriangularPyramid(4.5f, 2, 4.87),
		new RectangularPyramid(3.23f, 2, 3),
		new Cylinder(3.86f, 4),
		new Sphere(2.3f),
	};

	Shape3D *smallestShape = shapes[0];
	Shape3D *largestShape = shapes[0];
	for (int i = 0; i < 4; i++)
		shapes[i]->ShowVolume();

	// Find the largest and smallest shapes
	for (int i = 1; i < 4; i++)
	{
		if (*smallestShape > *shapes[i])
			smallestShape = shapes[i];
		if (*largestShape < *shapes[i])
			largestShape = shapes[i];
	}
	cout << endl << "***** The smallest shape *****" << endl;
	smallestShape->Display();

	cout << endl << "***** The largest shape *****" << endl;
	largestShape->Display();

	for (int i = 0; i < 4; i++)
		delete shapes[i];
}