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
	//todo: show all the vehicles too
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
	delete[] vehicles;
	std::cout << "Showroom destroyed.";
}
