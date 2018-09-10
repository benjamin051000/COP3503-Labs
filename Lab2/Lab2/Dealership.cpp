#include "pch.h"
#include "Dealership.h"
#include <iostream>

Dealership::Dealership()
{
	name = nullptr;
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
	set(d);
}

Dealership::Dealership(const char* name, int maxCapacity)
{
	name = name;
	showrooms = new Showroom[maxCapacity];
}

void Dealership::AddShowroom(const Showroom* s)
{
	if (numShowrooms < maxCapacity)
	{
		showrooms[numShowrooms] = *s;
		numShowrooms++;
	}
}

void Dealership::ShowInventory() const
{
	using namespace std; //only in this scope
	//cout << *name << endl;
	for (int i = 0; i < maxCapacity; i++) {
		for (int j = 0; j < showrooms[i].GetCapacity(); j++) {
			showrooms[i].ShowInventory();
		}
	}
}

unsigned int Dealership::GetAveragePrice()
{
	int sum = 0;
	int total = 0;
	for (int i = 0; i < maxCapacity; i++) {
		for (int j = 0; j < showrooms[i].GetCapacity(); j++) {
			sum += showrooms[i].GetVehicleList()[j].GetPrice();
			total++;
		}
	}

	std::cout << total << std::endl << sum << std::endl;
	return sum / total;
}

Dealership Dealership::operator=(const Dealership &d)
{
	set(d);
	return *this;
}

void Dealership::set(const Dealership &d)
{
	this->name = d.name;
	this->numShowrooms = 0;
	this->maxCapacity = d.maxCapacity;
	
	showrooms = new Showroom[maxCapacity];
	//copy each individual showroom
	for (int i = 0; i < maxCapacity; i++) {
		this->showrooms[i] = d.showrooms[i];
	}
}
