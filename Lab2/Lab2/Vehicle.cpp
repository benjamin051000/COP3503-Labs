#include "pch.h"
#include "Vehicle.h"
#include <iostream>

Vehicle::Vehicle(string make, string model, int year, int price, int miles) {
	this->make = make;
	this->model = model;
	this->year = year;
	this->price = price;
	this->miles = miles;
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
	using namespace std;
	cout << year << " \t" << make << ' ' << model << " \t$" << price << '\t' << miles << endl;
}

string Vehicle::GetYearMakeModel() const {
	//return this->year + " " + this->make + " " + this->model;
	return "" + year + '\t' + make + '\t' + model;
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
