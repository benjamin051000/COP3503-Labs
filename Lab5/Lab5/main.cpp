#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Lego {
	int setNumber;
	string theme;
	string name;
	int numMiniFigs;
	int numPieces;
	float price;

public:
	
};

int main() {
	cout << std::fixed << setprecision(2);
	cout << "Which file(s) to open?\n";
	cout << "1. lego1.csv" << endl;
	cout << "2. lego2.csv" << endl;
	cout << "3. lego3.csv" << endl;
	cout << "4. All 3 files" << endl;
	int option;
	cin >> option;
	string filename;
	ifstream file;
	bool sample = true;
	vector<Lego> parsedData;

	/*======= Load data from file(s) =======*/
	switch (option) {
	case 1: filename = sample ? "SAMPLE_lego1.csv" : "lego1.csv";
		break;
	case 2: filename = sample ? "SAMPLE_lego2.csv" : "lego2.csv";
		break;
	case 3: filename = sample ? "SAMPLE_lego3.csv" : "lego3.csv";
		break;
	case 4: filename = "lego4.csv";
		break;
	default: cout << "Invalid input." << endl;
		return 0;
	}

	file.open(filename);
	if (!file.is_open()) {
		cout << "Could not open " << filename << "." << endl;
		return -1;
	}

	//load em up
	int setNumber;
	string theme;
	string name;
	int numMiniFigs;
	int numPieces;
	float price;
	string line;
	while (getLine(file, line)) {

	}


	/*======= Print out how many sets were loaded =======*/
	cout << parsedData.size() << " sets loaded." << endl;

	/* Imagine your program had a menu like this:
	cout << "1. Most Expensive set" << endl;
	 cout << "2. Largest piece count" << endl;
	 cout << "3. Search for set name containing..." << endl;
	 cout << "4. Search themes..." << endl;
	 cout << "5. Part count information" << endl;
	 cout << "6. Price information" << endl;
	 cout << "7. Minifigure information" << endl;
	 cout << "8. If you bought one of everything..." << endl;
	 cout << "0. Exit" << endl;
	*/
	int choice;
	cin >> choice;
	cin.get();  // Clear newline character for any later input

	/*======= Based on the choice, execute the appropriate task and show the results =======*/
	switch(choice) {
	case 1: 
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	case 8:
		break;
	case 0: return 0;
		break;
	default:
	}

	file.close();
	return 0;
}

