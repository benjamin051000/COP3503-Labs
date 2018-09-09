#include "Dealership.h"
#include <iostream>

Dealership::Dealership()
{
	name = "";
	numShowrooms = 0;
	maxCapacity = 0;
	showrooms = nullptr;
}

Dealership::~Dealership()
{
	delete[] showrooms;
	std::cout << "Dealership destroyed." << std::endl;
}

Dealership::Dealership(Dealership& d)
{
	this->name = d.name;
	this->numShowrooms = d.numShowrooms;
	this->maxCapacity = d.maxCapacity;

	showrooms = new Showroom[maxCapacity];
	//copy each individual showroom
	for (int i = 0; i < maxCapacity; i++) {
		showrooms[i] = d.showrooms[i]; //does this need the operator= ?
	}
}

Dealership::Dealership(string name, int maxCapacity)
{
	name = name;
	showrooms = new Showroom[maxCapacity];
	
}

void Dealership::AddShowroom(const Showroom* s)
{
	if (numShowrooms < maxCapacity)
	{
		showrooms[numShowrooms] = *s;
		maxCapacity++;
	}
}

void Dealership::ShowInventory()
{

}

unsigned int Dealership::GetAveragePrice()
{
	int sum = 0;
	return 0;
}
