#include "Dealership.h"

Dealership::Dealership()
{
}

Dealership::~Dealership()
{
}

Dealership::Dealership(Dealership & d)
{
}

Dealership::Dealership(string name, int maxCapacity)
{
	name = name;
	showrooms = new Showroom[maxCapacity];
}

void Dealership::AddShowroom(const Showroom* s)
{

}

void Dealership::ShowInventory()
{
}

unsigned int Dealership::GetAveragePrice()
{
	return 0;
}
