#pragma once
#include <string>
using std::string;

class Vehicle {
public:
	Vehicle();
	Vehicle(string make, string model, int year, int price, int miles); //not sure if order is correct
	Vehicle(const Vehicle &v);
	
	//Print all the information on a single line
	void Display() const;

	//Return a string in the form of "1970 Ford Mustang"
	string GetYearMakeModel() const;

	//How much to buy this?
	int GetPrice() const;

	Vehicle operator=(const Vehicle &v);

private:
	string make;
	string model;
	int year;
	int price;
	int miles;
	void set(const Vehicle &v);
};