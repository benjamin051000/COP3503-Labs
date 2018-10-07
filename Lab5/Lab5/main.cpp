#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	cout << std::fixed << setprecision(2);
	cout << "Which file(s) to open?\n";
	cout << "1. lego1.csv" << endl;
	cout << "2. lego2.csv" << endl;
	cout << "3. lego3.csv" << endl;
	cout << "4. All 3 files" << endl;
	int option;
	cin >> option;

	/*======= Load data from file(s) =======*/
	/*======= Print out how many sets were loaded =======*/

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

	return 0;
}


