#include "pch.h"
#include "Showroom.h"
#include <iostream>

void Showroom::AddVehicle(const Vehicle* v) {
	if (numVehicles < maxCapacity) {
		vehicles[numVehicles] = *v;
		numVehicles++;
	}
}

void Showroom::ShowInventory() const {
	//std::cout << name << ", " << maxCapacity << "..." << std::endl;
	for (int i = 0; i < maxCapacity; i++) {
		vehicles[i].Display();
	}
}

const Vehicle* Showroom::GetVehicleList() const {
	return vehicles;
}

unsigned int Showroom::GetCapacity() const {
	return this->maxCapacity;
}

unsigned int Showroom::GetCount() const {
	return this->numVehicles;
}

const char* Showroom::GetName() const {
	return name;
}

Showroom::Showroom() {
	this->name = nullptr;
	this->vehicles = nullptr;
	this->numVehicles = 0;
	this->maxCapacity = 0;
}

Showroom::Showroom(const char* name, int maxCapacity) {
	this->name = name;
	this->maxCapacity = maxCapacity;
	vehicles = new Vehicle[maxCapacity];
}

Showroom::~Showroom() {
	delete[] vehicles; //access violation
	vehicles = nullptr;
	//std::cout << "Showroom destroyed." << std::endl;
}

Showroom::Showroom(const Showroom& s) { set(s); }

Showroom Showroom::operator=(const Showroom &s) {
	set(s);
	return *this;
}

void Showroom::set(const Showroom &s) {
	this->maxCapacity = s.maxCapacity;
	this->numVehicles = 0;
	this->name = s.name;
	
	vehicles = new Vehicle[maxCapacity];
	//Copy over each vehicle
	for (int i = 0; i < maxCapacity; i++) {
		this->vehicles[i] = s.vehicles[i];
		this->numVehicles++;
	}
}
