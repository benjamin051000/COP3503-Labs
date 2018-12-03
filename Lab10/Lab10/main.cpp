#include <iostream>
#include <fstream> 
#include <string>
#include <sstream>
#include "WordInfo.h"
#include <map>
#include <unordered_map>
using namespace std;

int main() {
	cout << "1-4: Which file to open?" << endl;
	int option;
	cin >> option;

	string filename = "file";

	switch (option) {
	case 0: filename = "testfile.txt";
		break;
	case 1: filename += "1.txt";
		break;
	case 2: filename += "2.txt";
		break;
	case 3: filename += "3.txt";
		break;
	case 4: filename += "4.txt";
		break;
	default: cout << "Enter a value between 1 and 4." << endl;
	}

	WordInfo wordinfo;

	ifstream ignoreWords;
	ignoreWords.open("words_to_ignore.txt");
	if (ignoreWords.is_open()) {

		string line;
		vector<string> ignore;

		while (ignoreWords >> line) {
			ignore.push_back(line);
		}

		wordinfo.SetIgnoreWords(ignore);
	}

	// Read the words from the file
	wordinfo.ReadWordsFromFile(filename.c_str());

	// Show the stats
	wordinfo.DisplayStats();


	// Show the most frequent words, NOT using the ignore list (lots of "a" "of" "the" entries here)
	// (Show a number of common words based on the selected file + 1. First file shows 2 common words, second shows 3, 4th shows 5, etc)
	wordinfo.MostCommonWords(option + 1);
	// Show the most frequent words, using the ignore list (to ignore the universally common words)
	wordinfo.MostCommonWords(option + 1, true);


	// Get and then show the longest words
	vector<string> longestWords;
	wordinfo.LongestWords(longestWords);

	cout << "Longest word(s): " << endl;
	for (string s : longestWords) { //should this loop include the count instead?
		cout << s << endl;
	}
	
	// Get input for a word, and do an exact match search for that word. (Convert input to lowercase first!)
	cout << "Enter a word for an exact search: ";
	string searchTerm;
	cin >> searchTerm;
	int count = wordinfo.SearchForWord(searchTerm);
	cout << '\'' << searchTerm << "' was found " << count << " times in the list.\n";

	// Ditto for partial search...
	cout << "Enter a word for a partial search: ";
	cin >> searchTerm;

	vector<string> results = wordinfo.PartialSearch(searchTerm.c_str());
	if (results.size() == 0)
		cout << "\nNo entries match '" << searchTerm << '\'' << endl;
	else
	{
		cout << "\nWords containing '" << searchTerm << '\'' << endl;

		for (string s : results) {
			cout << s << endl;
		}
		
	}

	return 0;
}

