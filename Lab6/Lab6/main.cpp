#include<iostream>
using namespace std;

int main() {
	cout << "Which file(s) to open?\n";
	cout << "1. fantasyheroes.dat" << endl;
	cout << "2. superheroes.dat" << endl;
	cout << "3. Both files" << endl;
	int option;
	cin >> option;

	/* Load hero files here */

	cout << "1. Print all heroes" << endl;
	cout << "2. Hero with the most items" << endl;
	cout << "3. Strongest hero" << endl;
	cout << "4. Heroes with greater than 18 intelligence" << endl;
	cout << "5. 2 clumsiest heroes" << endl;
	cout << "6. Hero with the most valuable stuff" << endl << endl;

	cin >> option;

	/* Work your magic here */

	return 0;
}

//file.read(length)
//char* temp = new char[lengthOfName];
//tempHero.name = temp;
//delete[] temp;

/*
int: 4 bytes
short: 2 bytes
float: 4 bytes
double: 8 bytes (?)
*/