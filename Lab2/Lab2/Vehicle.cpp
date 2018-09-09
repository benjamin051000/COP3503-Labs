#include "Vehicle.h"
#include <iostream>

Vehicle::Vehicle(string make = "", string model = "", int year = -1, int price = -1, int miles = 0)
{
	make = make;
	model = model;
	year = year;
	price = price;
	miles = miles;
}

Vehicle::Vehicle() {
	make = "";
	model = "";
	year = -1;
	price = -1;
	miles = 0;
}

Vehicle::Vehicle(Vehicle &v) //copy constructor
{
	this->make = v.make;
	this->model = v.model;
	this->year = v.year;
	this->miles = v.miles;
	this->price = v.price;
}

//Vehicle::~Vehicle() //not really necessary, as there isn't any dynamic allocation in Vehicle class
//{
//	delete &make;
//	delete &model;
//	delete &year;
//	delete &miles;
//	delete &price;
//
//	std::cout << "Vehicle destroyed.";
//}

//Verify with zyLabs to correct output
void Vehicle::Display() const
{
	std::cout << GetYearMakeModel() << " " << miles << " $" << price << std::endl;
}

string Vehicle::GetYearMakeModel() const
{
	return year + " " + make + " " + model;
}

int Vehicle::GetPrice() const
{
	return price;
}
