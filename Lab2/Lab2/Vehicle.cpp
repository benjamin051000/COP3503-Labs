#include "Vehicle.h"
#include <iostream>

Vehicle::Vehicle()
{
	make = "";
	model = "";
	year = -1;
	miles = -1;
	price = -1.0f;
}

Vehicle::Vehicle(string make, string model, int year, int miles, float price)
{
	make = make;
	model = model;
	year = year;
	miles = miles;
	price = price;
}

Vehicle::Vehicle(Vehicle &car) //probably broken lol
{
	make = car.make;
	model = car.model;
	year = car.year;
	miles = car.miles;
	price = car.price;
}

Vehicle::~Vehicle()
{
	std::cout << "Vehicle destructor invoked.";
}

void Vehicle::Display() const
{
}

string Vehicle::GetYearMakeModel() const
{
	return year + " " + make + " " + model;
}

float Vehicle::GetPrice() const
{
	return price;
	//return this->price; ?
}
