#pragma once
#include <string>
using std::string;

class Vehicle {
public:
	Vehicle(); //Not necessary, constructor has def values
	Vehicle(string make, string model, int year, int price, int miles); //not sure if order is correct
	Vehicle(Vehicle &v);
	
	void Display() const; //Print all the information on a single line
	string GetYearMakeModel() const; //Return a string in the form of "1970 Ford Mustang"
	int GetPrice() const; //How much to buy this?

private:
	string make;
	string model;
	int year;
	int price;
	int miles;
};