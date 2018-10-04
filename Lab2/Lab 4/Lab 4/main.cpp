#include "ABS.h"
#include <iostream>
#include <chrono>
using namespace std;

void test();

int main() {

	if (true) {
		test();
		return 0;
	}

	/*cout << "Making integer ABS...\n";
	ABS<int> intABS;
	cout << "Size: " << intABS.getSize() << endl;
	cout << "Max Capacity: " << intABS.getMaxCapacity() << endl;
	cout << "\nPushing items...\n";
	for (int i = 1; i < 10; i++) {
		intABS.push(i);
		cout << "\nPushed " << intABS.peek() << endl;
		cout << "New Size: " << intABS.getSize() << endl;
		cout << "New Max Capacity: " << intABS.getMaxCapacity() << endl;
	}
	
	cout << "\nPopping items...\n";
	for (int i = 1; i < 10; i++) {
		cout << "\nPopped " << intABS.pop() << endl;
		cout << "New Size: " << intABS.getSize() << endl;
		cout << "New Max Capacity: " << intABS.getMaxCapacity() << endl;
	}

	cout << "\nMaking float ABS...\n";
	ABS<float> floatABS(10);
	cout << "Size: " << floatABS.getSize() << endl;
	cout << "Max Capacity: " << floatABS.getMaxCapacity() << endl;
	cout << "\nPushing items...\n";
	for (float i = 1; i < 5; i += 0.5f) {
		floatABS.push(i);
		cout << "\nPushed " << floatABS.peek() << endl;
		cout << "New Size: " << floatABS.getSize() << endl;
		cout << "New Max Capacity: " << floatABS.getMaxCapacity() << endl;
	}

	cout << "\nPopping items...\n";
	for (float i = 1; i < 5; i += 0.5f) {
		cout << "\nPopped " << floatABS.pop() << endl;
		cout << "New Size: " << floatABS.getSize() << endl;
		cout << "New Max Capacity: " << floatABS.getMaxCapacity() << endl;
	}

	return 0;*/
}

void test() {
	const float scaleFactors[] = { 1.5f, 2.0f, 3.0f, 10.0f, 100.0f };
	const unsigned int caps[] = { 10000000, 30000000, 50000000, 75000000, 100000000 };

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; i++) {
			ABS<int> testabs(scaleFactors[j]);
			cout << "Running test: Size = " << caps[i] << ", Scale Factor: " << scaleFactors[j] << endl;

			//start timer
			auto start = chrono::steady_clock::now();
			
			//push
			for (unsigned int i = 0; i < caps[i]; i++) {
				testabs.push(i);
				//cout << "Pushed" << testabs.peek();
			}

			//pop
			for (unsigned int i = 0; i < testabs.getSize(); i++) {
				testabs.pop();
			}

			//stop timer
			auto end = chrono::steady_clock::now();

			//display stats
			cout << "Elapsed time: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " nanoseconds" << endl;
			cout << "Number of resizes: " << testabs.getResizes() << endl << endl;
			
		}
	}
}