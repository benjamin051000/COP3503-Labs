#include "Showroom.h"
#include <iostream>

void Showroom::AddVehicle(const Vehicle * v)
{
}

void Showroom::ShowInventory() const
{
}

const Vehicle * Showroom::GetVehicleList() const
{
	return nullptr;
}

unsigned int Showroom::GetCapacity() const
{
	return 0;
}

unsigned int Showroom::GetCount() const
{
	return 0;
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

Showroom::Showroom(std::string name, int maxCapacity)
{
	name = name;
	maxCapacity = maxCapacity;
	//Initialize vector somehow
}

Showroom::~Showroom()
{
	std::cout << "Showroom destructor invoked.";
}
