#include "pch.h"
#include "Vehicle.h"
#include <iostream>

Vehicle::Vehicle(string make, string model, int year, int price, int miles) {
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

Vehicle::Vehicle(const Vehicle &v) {set(v);}

//Verify with zyLabs to correct output
void Vehicle::Display() const {
	std::cout << GetYearMakeModel() << " " << miles << " $" << price << std::endl;
}

string Vehicle::GetYearMakeModel() const {
	return year + " " + make + " " + model;
}

int Vehicle::GetPrice() const {
	return price;
}

Vehicle Vehicle::operator=(const Vehicle &v) {
	set(v);
	return *this;
}

void Vehicle::set(const Vehicle & v) {
	this->make = v.make;
	this->model = v.model;
	this->year = v.year;
	this->price = v.price;
	this->miles = v.miles;
}
