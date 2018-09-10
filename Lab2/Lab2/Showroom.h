#pragma once
#include "Vehicle.h"

class Showroom {
public:
	//Constructors
	Showroom();
	Showroom(const char* name, int maxCapacity);
	~Showroom();
	Showroom(const Showroom& s);

	Showroom operator=(const Showroom &v);

	//Store a Vehicle in the first available spot
	void AddVehicle(const Vehicle* v);

	//Show the name of this object and all of its vehicles
	void ShowInventory() const;

	//Accessors
	const Vehicle* GetVehicleList() const;
	unsigned int GetCapacity() const;
	unsigned int GetCount() const;
	const char* GetName() const;

private:
	const char* name;
	Vehicle* vehicles;
	int maxCapacity;
	int numVehicles;
	void set(const Showroom &s);
};