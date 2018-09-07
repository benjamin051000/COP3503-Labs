#pragma once
#include <string>
using std::string;

class Vehicle {
public:
	Vehicle();
	Vehicle(string make, string model, int year, int miles, float price); //not sure if order is correct
	Vehicle(Vehicle &);
	~Vehicle();
	//Print all the information on a single line
	void Display() const;
	//Return a string in the form of "1970 Ford Mustang"
	string GetYearMakeModel() const;
	//How much to buy this?
	float GetPrice() const;

private:
	string make;
	string model;
	int year;
	float price;
	int miles;
};