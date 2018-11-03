#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "Color.h"
using namespace std;

void ReadFile(const char *filename, vector<Color> &outVector);
void SortColors(vector<Color> &colors);
void PrintColors(const vector<Color> &colors);

int main() {
	cout << "1. Load colors1.txt" << endl;
	cout << "2. Load colors2.txt" << endl;
	cout << "3. Load colors3.txt" << endl;
	cout << "4. Load all 3 files.txt" << endl;
	int choice;
	cin >> choice;

	vector<Color> colors;
	// Load the selected files
	if (choice >= 1 && choice <= 3) {
		string file = "colors" + to_string(choice) + ".txt";
		
		ReadFile(file.c_str(), colors);
	}
	else if (choice == 4) {
		for (int i = 1; i <= 3; i++) {
			string file = "colors" + to_string(i) + ".txt";
			ReadFile(file.c_str(), colors);
		}
	}

	// Sort and print the loaded data
	SortColors(colors);
	PrintColors(colors);

	//Color c;
	//c.SetName("Black");
	//c.SetValue(0); //16777215 is white
	//cout << c.GetName() << " " << c.GetHexValue() << " " << (int)c.GetR() << " " << (int)c.GetB() << " " << (int)c.GetG() << endl;

	return 0;
}

void ReadFile(const char *filename, vector<Color> &outVector) {
	fstream file(filename, ios_base::in);

	if (!file.is_open()) {
		cout << "Error opening " << filename << endl;
		return;
	}

	string line, sstoken;
	while (getline(file, line, '\n')) {
	
		stringstream ss(line);
		getline(ss, sstoken, ' ');
		string name = sstoken;

		getline(ss, sstoken);
		int value = stoi(sstoken);

		Color c;
		c.SetName(name);
		c.SetValue(value);
		
		outVector.push_back(c);
	}

	file.close();
}

void SortColors(vector<Color> &colors) {
	// TODO: Sort the colors in ascending order by name.
}

void PrintColors(const vector<Color> &colors) {
	for (unsigned int i = 0; i < colors.size(); i++) {
		cout << colors[i].GetName();
		for (unsigned int j = 0; j < 3 - colors[i].GetName().size() / 8; j++)
			cout << "\t";
		cout << colors[i].GetHexValue() << '\t' << (int)colors[i].GetR() << "," 
			<< (int)colors[i].GetG() << "," << (int)colors[i].GetB() << endl;
	}
	cout << "Number of colors: " << colors.size() << endl;
}
