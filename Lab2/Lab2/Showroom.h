#pragma once
#include "Vehicle.h"
#include <string>

class Showroom {
public:
	//Store a Vehicle in the first available spot
	void AddVehicle(const Vehicle* v);
	//Show the name of this object and all of its vehicles
	void ShowInventory() const;

	//Accessors
	const Vehicle* GetVehicleList() const;
	unsigned int GetCapacity() const;
	unsigned int GetCount() const;
	const char* GetName() const;

	//Constructors
	Showroom();
	Showroom(std::string name, int maxCapacity);
	~Showroom();
	Showroom(const Showroom& s);



private:
	std::string name;
	Vehicle* vehicles; //pointer to the array of vehicles
	int maxCapacity;
	int numVehicles;
};