#pragma once
#include "Showroom.h"
#include <string> //unecessary? Showroom -> vehicle has it

class Dealership {
public:
	Dealership();
	~Dealership();
	Dealership(Dealership &d);
	Dealership(string name, int maxCapacity);
	void AddShowroom(const Showroom* s);
	void ShowInventory();
	unsigned int GetAveragePrice();


private:
	Showroom* showrooms;
	string name;
	int numShowrooms;
	int maxCapacity;
};