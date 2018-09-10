#include "pch.h"
#include "Dealership.h"
#include <iostream>
#include <iomanip> //used for rounding the average price (todo)

Dealership::Dealership() {
	name = "";
	numShowrooms = 0;
	maxCapacity = 1;
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
	std::cout << "Inventory of " << name << std::endl;
	for (int i = 0; i < numShowrooms; i++) {
		showrooms[i].ShowInventory();
	}
	std::cout << "Average price of the cars in the dealership: $" << std::fixed << std::setprecision(2);
	std::cout << GetAveragePrice() << std::endl;
}

float Dealership::GetAveragePrice() const {
	int sum = 0, total = 0;

	for (int s = 0; s < numShowrooms; s++) {
		for (unsigned int v = 0; v < showrooms[s].GetCount(); v++) {
			sum += showrooms[s].GetVehicleList()[v].GetPrice();
			total++;
		}
	}

	
	return (float)(sum) / total; //casts entire expression to float
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
