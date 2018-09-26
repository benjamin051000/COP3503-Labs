#include <iostream>
using namespace std;

void testOne() {
	cout << "Inventory of COP3503 Vehicle Emporium" << endl
		<< "Vehicles in Primary Showroom" << endl
		<< "1973 	Ford Mustang 	$9500	113000" << endl
		<< "2017 	Mazda CX - 5 	$24150	5900" << endl << endl

		<< "Vehicles in Fuel - Efficient Showroom" << endl
		<< "2018 	Telsa Model S 	$74500	31" << endl
		<< "2015 	Toyota Prius 	$17819	22987" << endl
		<< "2016 	Nissan Leaf 	$12999	16889" << endl
		<< "2015 	Chevrolet Volt 	$16994	12558" << endl << endl

		<< "Average car price : $25993.67" << endl;

}
void testTwo() {

}

int main() {
	int input;
	cin >> input;

	switch (input) {
	case 1: testOne();
		break;
	case 2: testTwo();
		break;
	}
	return 0;
}