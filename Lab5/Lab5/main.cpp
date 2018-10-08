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
		return os << "Name: " << set.name << "\nNumber: " << set.setNumber << "\nTheme: " << set.theme
			<< "\nPrice: $" << set.price << "\nMinifigures: " << set.numMiniFigs
			<< "\nPiece count: " << set.numPieces;
	}
};
void loadData(vector<string>& a);

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
	vector<string> loadqueue;

	cout << std::fixed << setprecision(2);
	cout << "Which file(s) to open?\n";
	cout << "1. lego1.csv" << endl;
	cout << "2. lego2.csv" << endl;
	cout << "3. lego3.csv" << endl;
	cout << "4. All 3 files" << endl;
	int option;
	cin >> option;

	
	bool sample = true;
	

	/*======= Load data from file(s) =======*/
	switch (option) {
	case 1: sample ? loadqueue.push_back("SAMPLE_lego1.csv") : loadqueue.push_back("lego1.csv");
		break;
	case 2: sample ? loadqueue.push_back("SAMPLE_lego2.csv") : loadqueue.push_back("lego2.csv");
		break;
	case 3: sample ? loadqueue.push_back("SAMPLE_lego3.csv") : loadqueue.push_back("lego3.csv");
		break;
	case 4: sample ? loadqueue = { "SAMPLE_lego1.csv", "SAMPLE_lego2.csv", "SAMPLE_lego3.csv" } : loadqueue = { "lego1.csv", "lego2.csv", "lego3.csv" };
		break;
	default: cout << "Invalid input." << endl;
		return 0;
	}

	loadData(loadqueue);

	/*======= Print out how many sets were loaded =======*/
	cout << "Total number of sets: " << parsedData.size() << endl << endl;
	
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

	return 0;
}

void loadData(vector<string>& a) {
	ifstream file;
	for (string filename : a) {
		file.open(filename);

		if (!file.is_open()) {
			cout << "Could not open " << filename << "." << endl;
			return;
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
			try {
				anumMiniFigs = sstoken == "" ? 0 : stoi(sstoken);
			}
			catch (invalid_argument& a) {
				anumMiniFigs = 0;
			}

			getline(ss, sstoken, ',');
			try {
				anumPieces = sstoken == "" ? 0 : stoi(sstoken);
			}
			catch (invalid_argument& a) {
				anumPieces = 0;
			}

			getline(ss, sstoken, ',');
			try {
				aprice = sstoken == "" ? 0 : stof(sstoken);
			}
			catch (invalid_argument& a) {
				aprice = 0;
			}
			
			//make a new lego instance and put it in the vector
			parsedData.push_back(Lego(asetNumber, atheme, aname, anumMiniFigs, anumPieces, aprice));
		}

		file.close();
	}
}

void mostExpensiveSet() {
	Lego mostExpensiveSet;

	for (Lego set: parsedData) {
		if (set.price > mostExpensiveSet.price && set.price != 0) {
			mostExpensiveSet = set;
		}
	}
	cout << "The most expensive set is:\n" << mostExpensiveSet << endl << endl;
}

void largestPieceCount() {
	Lego mostPieces; //will this work?

	for (Lego set : parsedData) {
		if (set.numPieces > mostPieces.numPieces && set.numPieces != 0) {
			mostPieces = set;
		}
	}
	cout << "The set with the highest parts count:\n" << mostPieces << endl << endl;
}

void searchName() {
	vector<Lego> found;
	//cout << "Input a keyword: ";
	string input;
	getline(cin, input);
	
	for (Lego set : parsedData) {
		if (set.name.find(input) != string::npos) {
			found.push_back(set);
		}
	}
	
	if (found.size() > 0) {
		cout << "Sets matching \"" << input << "\":" << endl;
		for (Lego set : found) {
			cout << set.setNumber << " " << set.name << " $" << set.price << " " << endl;
		}
	}
	else {
		cout << "No sets found matching that search term";
	}
	cout << endl;
}

void searchTheme() {
	vector<Lego> found;
	//cout << "Input a keyword: ";
	string input;
	getline(cin, input);

	for (Lego set : parsedData) {
		
		if (set.theme.find(input) != string::npos) {
			found.push_back(set);
		}
	}

	if (found.size() > 0) {
		cout << "\nSets matching \"" << input << "\":" << endl;
		for (Lego set : found) {
			cout << set.setNumber << " " << set.name << " $" << set.price << endl;
		}
	}
	else {
		cout << "No sets found matching that search term";
	}
	cout << endl;
}

void partCountInfo() {
	int total = 0, count = 0;
	Lego least = parsedData.at(0), greatest;

	for (Lego set : parsedData) {
		if (set.numPieces == 0) continue;

		total += set.numPieces;
		count++;
		if (set.numPieces < least.numPieces) {
			least = set;
		}
		if (set.numPieces > greatest.numPieces) {
			greatest = set;
		}
	}
	cout << "Average part count for " << parsedData.size() << " sets: " << total / count << endl << endl;
	cout << "Set with the smallest part count:\n" << least << endl << endl;
	cout << "Set with the largest part count:\n" << greatest << endl << endl;
}

void priceInfo() {
	float total = 0;
	int count = 0;
	Lego least, greatest;

	for (Lego set : parsedData) {
		if (set.price == 0) continue;

		total += set.price;
		count++;

		if (set.price > greatest.price) {
			greatest = set;
		}
	}

	least = greatest;

	for (Lego set : parsedData) {
		if (set.price == 0) continue;

		if (set.price < least.price) {
			least = set;
		}
	}

	cout << "Average price for " << count << " sets: $" << total / count << endl << endl;
	cout << "Least expensive set:\n" << least << endl << endl;
	cout << "Most expensive set:\n" << greatest << endl << endl;
}

void minifigInfo() {
	int total = 0;
	int count = 0;
	Lego least = parsedData.at(0), greatest;

	for (Lego set : parsedData) {
		if (set.numMiniFigs == 0) continue;

		count++;
		total += set.numMiniFigs;
		
		if (set.numMiniFigs > greatest.numMiniFigs) {
			greatest = set;
		}
	}
	least = greatest;
	for (Lego set : parsedData) {
		if (set.numMiniFigs == 0) continue;

		if (set.numMiniFigs < least.numMiniFigs) {
			least = set;
		}
	}
	cout << "Average number of minifigures: " << total / count << endl << endl;
	cout << "Set with the most minifigures:\n" << greatest << endl << endl;
	cout << "Set with the fewest minifigures:\n" << least << endl << endl;
}

void buyItAll() {
	cout << "If you bought one of everything..." << endl;
	float totalPrice = 0;
	int totalPieces = 0, totalMinifigs = 0;

	for (Lego set : parsedData) {
		totalPrice += set.price;
		totalPieces += set.numPieces;
		totalMinifigs += set.numMiniFigs;
	}

	cout << "It would cost: $" << totalPrice << endl;
	cout << "You would have " << totalPieces << " pieces in your collection" << endl;
	cout << "You would have an army of " << totalMinifigs << " minifigures!" << endl;
}