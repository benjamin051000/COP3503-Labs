#pragma once
#include "Showroom.h"
#include <string> //unecessary? Showroom -> vehicle has it

class Dealership {
public:
	//Constructors
	Dealership();
	~Dealership();
	Dealership(Dealership& d);
	Dealership(const char* name, int maxCapacity);

	Dealership operator=(const Dealership &d);

	void AddShowroom(const Showroom* s);
	void ShowInventory() const;
	unsigned int GetAveragePrice();

private:
	
	const char* name;
	int numShowrooms;
	int maxCapacity;
	Showroom* showrooms;
	void set(const Dealership &d);
};