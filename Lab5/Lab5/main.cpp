#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Lego {
	int setNumber = 0;
	string theme = "";
	string name = "";
	int numMiniFigs = 0;
	int numPieces = 0;
	float price = 0.0f;

	Lego() {}

	Lego(int setNumber, string theme, string name, int numMiniFigs, int numPieces, float price) {
		this->setNumber = setNumber;
		this->theme = theme;
		this->name = name;
		this->numMiniFigs = numMiniFigs;
		this->numPieces = numPieces;
		this->price = price;
	}

	friend ostream& operator<<(ostream& os, Lego& set) {
		/*os << "Name: " << this->name << "\nNumber: " << this->setNumber << "\nTheme: " << this->theme
			<< "\nPrice: $" << this->price << "\nMinifigures: " << this->numMiniFigs
			<< "\nPiece count: " << this->numPieces;*/
		os << "Name: " << name << "\nNumber: " << setNumber << "\nTheme: " << theme
			<< "\nPrice: $" << price << "\nMinifigures: " << numMiniFigs
			<< "\nPiece count: " << numPieces;
		return os;
	}
};

void mostExpensiveSet();
void largestPieceCount();
void searchName();
void searchTheme();
void partCountInfo();
void priceInfo();
void minifigInfo();
void buyItAll();

vector<Lego> parsedData;

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
	

	/*======= Load data from file(s) =======*/
	switch (option) {
	case 1: filename = sample ? "SAMPLE_lego1.csv" : "lego1.csv";
		break;
	case 2: filename = sample ? "SAMPLE_lego2.csv" : "lego2.csv";
		break;
	case 3: filename = sample ? "SAMPLE_lego3.csv" : "lego3.csv";
		break;
	case 4: filename = "lego4.csv"; //should open every file
		break;
	default: cout << "Invalid input." << endl;
		return 0;
	}

	file.open(filename);
	if (!file.is_open()) {
		cout << "Could not open " << filename << "." << endl;
		return -1;
	}

	//Load vector with each Lego instnace

	//Attributes
	int asetNumber;
	string atheme;
	string aname;
	int anumMiniFigs;
	int anumPieces;
	float aprice;

	//used to parse the data
	string line, sstoken;
	
	//skip the first line
	getline(file, line, '\n'); 

	while (getline(file, line, '\n')) {

		stringstream ss(line);

		//load each individual variable
		getline(ss, sstoken, ','); 
		asetNumber = stoi(sstoken); 

		getline(ss, sstoken, ',');
		atheme = sstoken;
		
		getline(ss, sstoken, ',');
		aname = sstoken;
		
		getline(ss, sstoken, ',');
		anumMiniFigs = sstoken == "" ? 0 : stoi(sstoken);

		getline(ss, sstoken, ',');
		anumPieces = sstoken == "" ? 0 : stoi(sstoken);

		getline(ss, sstoken, ',');
		aprice = sstoken == "" ? 0.0f : stof(sstoken);

		//make a new lego instance and put it in the vector
		parsedData.push_back(Lego(asetNumber, atheme, aname, anumMiniFigs, anumPieces, aprice));
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
	do {
		cin >> choice;
		cin.get();  // Clear newline character for any later input

		/*======= Based on the choice, execute the appropriate task and show the results =======*/
		switch (choice) {
		case 1: mostExpensiveSet();
			break;
		case 2:largestPieceCount();
			break;
		case 3: searchName();
			break;
		case 4: searchTheme();
			break;
		case 5: partCountInfo();
			break;
		case 6: priceInfo();
			break;
		case 7: minifigInfo();
			break;
		case 8: buyItAll();
			break;
		case 0:
			break;
		default:
			break;
		}
	} while (choice != 0); //better way to do this?

	file.close();
	return 0;
}

void mostExpensiveSet() {
	Lego mostExpensiveSet; //will this work?

	for (Lego set: parsedData) {
		if (set.price > mostExpensiveSet.price) {
			mostExpensiveSet = set;
		}
	}
	cout << "Most expensive set costs $" << mostExpensiveSet << endl;
}

void largestPieceCount() {
}

void searchName() {
}

void searchTheme() {
}

void partCountInfo() {
}

void priceInfo() {
}

void minifigInfo() {
}

void buyItAll() {
}
