#include "pch.h"
#include "Dealership.h"
#include <iostream>
#include <iomanip> //used for rounding the average price (todo)

Dealership::Dealership() {
	name = "";
	numShowrooms = 0;
	maxCapacity = 1;
	//showrooms = nullptr;
}

Dealership::~Dealership() {
	delete[] showrooms;
}

Dealership::Dealership(Dealership& d) {
	set(d);
}

Dealership::Dealership(const char* name, int maxCapacity) {
	this->name = name;
	this->maxCapacity = maxCapacity;
	this->numShowrooms = 0;
	this->showrooms = new Showroom[maxCapacity];
}

void Dealership::AddShowroom(const Showroom* s) {
	if (numShowrooms < maxCapacity) {
		showrooms[numShowrooms] = *s;
		this->numShowrooms++;
	}
}

void Dealership::ShowInventory() const {
	for (int i = 0; i < numShowrooms; i++) {
		showrooms[i].ShowInventory();
	}
}

float Dealership::GetAveragePrice() {
	int sum = 0, total = 0;

	for (int i = 0; i < maxCapacity; i++) {
		for (unsigned int j = 0; j < showrooms[i].GetCapacity(); j++) {
			sum += showrooms[i].GetVehicleList()[j].GetPrice();
			total++;
		}
	}

	//std::cout << "total: " << total << std::endl << "sum: " << sum << std::endl << "avg: " << ((float)(sum) / (float)(total)) << std::endl;
	return ((float)(sum) / (float)(total));
}

Dealership Dealership::operator=(const Dealership &d) {
	set(d);
	return *this;
}

void Dealership::set(const Dealership &d) {
	this->name = d.name;
	this->numShowrooms = 0;
	this->maxCapacity = d.maxCapacity;
	
	showrooms = new Showroom[maxCapacity];

	//copy each individual showroom
	for (int i = 0; i < d.numShowrooms; i++) {
		this->showrooms[i] = d.showrooms[i];
		this->numShowrooms++;
	}
}
