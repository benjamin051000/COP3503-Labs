#pragma once
#include "Showroom.h"
#include <string> //unecessary? Showroom -> vehicle has it

class Dealership {
public:
	Dealership();
	~Dealership();
	Dealership(Dealership& d);
	Dealership(const char* name, int maxCapacity);
	void AddShowroom(const Showroom* s);
	void ShowInventory() const;
	unsigned int GetAveragePrice();
	Dealership operator=(const Dealership &d);

private:
	
	char* name;
	int numShowrooms;
	int maxCapacity;
	Showroom* showrooms;
	void set(const Dealership &d);
};