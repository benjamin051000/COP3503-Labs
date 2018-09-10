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

const char* Showroom::GetName() const
{
	return name;
}

Showroom::Showroom()
{
	name = nullptr;
	numVehicles = 0;
	maxCapacity = 0;
}

Showroom::Showroom(const char* name, int maxCapacity)
{
	name = name;
	maxCapacity = maxCapacity;
	vehicles = new Vehicle[maxCapacity];
}

Showroom::~Showroom()
{
	std::cout << "Showroom decon called." << std::endl;
	std::cout << "." << std::endl;
	delete &maxCapacity;
	delete &numVehicles;
	//delete[] vehicles; //access violation
	vehicles = nullptr;
	std::cout << "Showroom destroyed." << std::endl;
}

Showroom::Showroom(const Showroom& s) {set(s);}

Showroom Showroom::operator=(const Showroom &s)
{
	set(s);
	return *this;
}

void Showroom::set(const Showroom & s)
{
	this->maxCapacity = s.maxCapacity;
	this->numVehicles = s.maxCapacity;
	
	vehicles = new Vehicle[maxCapacity];
	//Copy over each vehicle
	for (int i = 0; i < maxCapacity; i++) {
		this->vehicles[i] = s.vehicles[i];
	}
}
