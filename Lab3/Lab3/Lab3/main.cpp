#include <iostream>
#include <vector>
#include <string>
#include "DynamicArray.h"
using namespace std;

// Sample class, to show a template can work with anything
class Hero
{
	string name_;
	int hitpoints_;
	int maxHP_;
public:
	Hero() {}
	Hero(const char *name, int hp, int maxHP)
	{
		name_ = name;
		hitpoints_ = hp;
		maxHP_ = maxHP;
	}
	void SetName(const char *name)
	{
		name_ = name;
	}
	string GetName()
	{
		return name_;
	}
	friend ostream &operator<<(ostream &os, const Hero &h)
	{
		cout << h.name_ << " Hitpoints: " << h.hitpoints_ << " / " << h.maxHP_;
		return os;
	}
};

void TestOne();
void TestTwo();
void TestThree();
void TestFour();

int main()
{
	cout << "**** Testing the Dynamic Array ****" << endl << endl;
	//TestOne();
	TestTwo();
	//TestThree();
	//TestFour();

	return 0;
}

void TestOne()
{
	cout << "Integer container: Initial capacity of 0" << endl;
	DynamicArray<int> data(0);
	cout << "Adding 5 items..." << endl;
	for (int i = 1; i < 32; i *= 2)
		data.Add(i);
	data[4] = 500;
	for (unsigned int i = 0; i < data.GetSize(); i++)
		cout << data[i] << endl;

	cout << "Capacity: " << data.GetCapacity() << endl;
	cout << "Size: " << data.GetSize() << endl;
}
void TestTwo()
{
	DynamicArray<float> data2(10);
	cout << "\nFloat container: Initial capacity of 10" << endl;
	cout << "Adding 5 items..." << endl;

	for (int i = 0; i < 5; i++)
		data2.Add((float)101 / (i + 2));
		
	for (unsigned int i = 0; i < data2.GetSize(); i++)
		cout << data2[i] << endl;

	cout << "Capacity: " << data2.GetCapacity() << endl;
	cout << "Size: " << data2.GetSize() << endl;

	cout << "\nShrinking container to 2 elements..." << endl;
	data2.Resize(2);

	for (unsigned int i = 0; i < data2.GetSize(); i++)
		cout << data2[i] << endl;
	cout << "Capacity: " << data2.GetCapacity() << endl;
	cout << "Size: " << data2.GetSize() << endl;

	cout << "Attempting to access index[50]...";
	try { cout << data2[50] << endl; }
	catch (const char *msg)
	{
		cout << msg << endl;
	}
}
void TestThree()
{
	DynamicArray<int> data3;

	data3.Add(100);
	data3.Add(999);
	data3.Add(200);
	data3.Add(300);
	data3.Add(400);

	for (unsigned int i = 0; i < data3.GetSize(); i++)
		cout << data3[i] << endl;

	cout << "Removing '999' from the list... " << endl;
	data3.Remove(1);

	for (unsigned int i = 0; i < data3.GetSize(); i++)
		cout << data3[i] << endl;

	cout << "Creating a copy of the list (testing the copy constructor)... " << endl;
	auto data4 = data3;

	cout << "\nPrinting copy of dynarray..." << endl;
	for (unsigned int i = 0; i < data4.GetSize(); i++)
		cout << data4[i] << endl;

	cout << "\nAttempting to remove index[100]..." << endl;
	try { data3.Remove(100); }
	catch (const char *msg)
	{
		cout << msg << endl;
	}

}
void TestFour()
{
	DynamicArray<Hero> heroes;
	heroes.Add(Hero("Conan", 100, 120));
	heroes.Add(Hero("Thor", 150, 150));
	heroes.Add(Hero("Merlin", 80, 85));
	heroes.Add(Hero("Bob", 25, 26));
	cout << "\nPrinting heroes from dynarray..." << endl;

	for (unsigned int i = 0; i < heroes.GetSize(); i++)
		cout << heroes[i] << endl;

	DynamicArray<Hero> heroClones;
	cout << "\nCloning our heroes (testing the assignment operator)... ";
	heroClones = heroes;

	cout << "\nPrinting cloned heroes from dynarray (and changing their names)..." << endl;
	for (unsigned int i = 0; i < heroClones.GetSize(); i++)
	{
		string name = "Evil " + heroClones[i].GetName();
		heroClones[i].SetName(name.c_str());
		cout << heroClones[i] << endl;
	}
}