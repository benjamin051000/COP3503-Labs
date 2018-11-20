#include <iostream>
#include <map>
#include <random>
#include <ctime>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

mt19937 random_mt;

int Random(int min, int max) {
	uniform_int_distribution<int> dist(min, max);
	return dist(random_mt);
}

void RollDice(int numberOfRolls, int numberOfSides) {
	map<int, int> results;
	for (int i = 1; i <= numberOfSides; i++) {
		results[i] = 0;
	}
	for (int i = 0; i < numberOfRolls; i++) {
		results[Random(1, numberOfSides)]++;
	}
	for (map<int, int>::iterator iter = results.begin(); iter != results.end(); iter++) {
		cout << iter->first << ": " << iter->second << endl;
	}
}

class State {
	string name;
	int perCapitaIncome;
	int population;
	int medHouseholdIncome;
	int numHouseholds;

public:
	State() {}

	State(string n, int pc, int p, int m, int h) {
		name = n;
		perCapitaIncome = pc;
		population = p;
		medHouseholdIncome = m;
		numHouseholds = h;
	}

	void Print() {
		cout << name;
		cout << "\nPopulation: " << population;
		cout << "\nPer Capita Income: " << perCapitaIncome;
		cout << "\nMedian Household Income: " << medHouseholdIncome;
		cout << "\nNumber of Households: " << numHouseholds << endl;
	}
};

void LoadStates(map<string, State>& map) {
	ifstream file("states.csv");

	if (!file.is_open()) {
		cout << "Error opening file." << endl;
		return;
	}

	string line;
	getline(file, line); //Skip first line
	while (getline(file, line)) {
		stringstream ss(line);
		string sstoken;

		string name;
		int attributes[4];
		
		/*Name*/
		getline(ss, name, ',');
		
		/*Anonymous function that converts string to int, throws*/
		/*auto toInt = [](string str) {
			try {
				return stoi(str);
			}
			catch (exception e) {
				cout << "An error occurred while reading the file." << endl;
			}
		};*/

		for (int i = 0; i <= 3; i++) {
			getline(ss, sstoken, ',');
			try {
				attributes[i] = stoi(sstoken);
			}
			catch (exception e) {
				cout << "An error occurred while reading the file." << endl;
			}
		}

		map.emplace( name, State(name, attributes[0], attributes[1], 
								attributes[2], attributes[3]) );
	}
}

void PrintAllStates(map<string, State>& states) {
	for (map<string, State>::iterator iter = states.begin(); iter != states.end(); iter++) {
		iter->second.Print();
		cout << endl;
	}
}

int main() {
	cout << "1. Random Numbers\n";
	cout << "2. State Info\n";

	int option;
	cin >> option;

	if (option == 1) {
		int randomSeed;
		cout << "Random seed value: ";
		cin >> randomSeed;
		random_mt.seed(randomSeed);

		cout << "Number of times to roll the die: ";
		int numRolls;
		cin >> numRolls;

		cout << "Number of sides on this die: ";
		int numSides;
		cin >> numSides;

		RollDice(numRolls, numSides);
	}
	else if (option == 2) {
		map<string, State> states;
		LoadStates(states);

		cout << "1. Print all states\n2. Search for a state" << endl;
		cin >> option;

		if (option == 1) {
			PrintAllStates(states);
		}
		else if (option == 2) {
			string keyword;
			cin >> keyword;
			if (states.count(keyword) > 0) {
				states[keyword].Print();
			}
			else {
				cout << "No match found for " << keyword << endl;
			}
		}
	}

	return 0;
}
