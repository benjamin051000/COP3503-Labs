#include "pch.h"
#include "Showroom.h"
#include <iostream>

void Showroom::AddVehicle(const Vehicle* v)
{
	if (numVehicles < maxCapacity) {
		vehicles[numVehicles] = *v;
		numVehicles++;
	}
}

void Showroom::ShowInventory() const
{
	std::cout << name << std::endl;
	for (int i = 0; i < maxCapacity; i++) {
		vehicles[i].Display();
	}
}

const Vehicle* Showroom::GetVehicleList() const
{
	return vehicles;
}

unsigned int Showroom::GetCapacity() const
{
	return maxCapacity;
}

unsigned int Showroom::GetCount() const
{
	return numVehicles;
}

const char * Showroom::GetName() const
{
	return nullptr;
}

Showroom::Showroom()
{
	name = "";
	numVehicles = 0;
	maxCapacity = 0;
}

Showroom::Showroom(std::string name = "", int maxCapacity = 0)
{
	name = name;
	maxCapacity = maxCapacity;
	vehicles = new Vehicle[maxCapacity];
}

Showroom::~Showroom()
{
	delete &maxCapacity;
	delete &numVehicles;
	if (vehicles == nullptr) {
		delete[] vehicles; //breaks!
		vehicles = nullptr;
	}
	std::cout << "Showroom destroyed.";
}

Showroom::Showroom(const Showroom& s)
{
	this->maxCapacity = s.maxCapacity;
	this->numVehicles = s.numVehicles;
	vehicles = new Vehicle[maxCapacity];
	//Copy over each vehicle
	for (int i = 0; i < maxCapacity; i++) {
		this->vehicles[i] = s.vehicles[i];
	}
}
