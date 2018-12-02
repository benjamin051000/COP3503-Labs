// Lexer.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <fstream> //necessary in main? it's already in WordInfo.h
#include <string>
#include <sstream>
#include "WordInfo.h"
#include <map>
#include <unordered_map>
using namespace std;

int main()
{
	// TODO: Load words_to_ignore.txt, store those in a vector of strings to pass to your class objects

	cout << "1-4: Which file to open? (0 to open testfile.txt)" << endl;
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

   // TODO: Create a WordInfo object and set the list of words to ignore
	WordInfo wordinfo;

	ifstream ignoreWords;
	ignoreWords.open("words_to_ignore.txt");
	if (ignoreWords.is_open()) {
		
		string line;
		vector<string> ignore;

		while (ignoreWords >> line) { //how does this delimit properly?
			ignore.push_back(line);
		}
		
		wordinfo.SetIgnoreWords(ignore);
	}

	// Read the words from the file
	wordinfo.ReadWordsFromFile(filename.c_str());

	// Show the stats
	wordinfo.DisplayStats();
	return 0;
	// Show the most frequent words, NOT using the ignore list (lots of "a" "of" "the" entries here)

	// Show the most frequent words, using the ignore list (to ignore the universally common words)
   
   // (Show a number of common words based on the selected file + 1. First file shows 2 common words, second shows 3, 4th shows 5, etc)

   // Get and then show the longest words
	vector<string> longestWords;
	
   // Get input for a word, and do an exact match search for that word. (Convert input to lowercase first!)
   cout << "Enter a word for an exact search: ";
	
	//cout << '\'' << searchTerm << "' was found " << count << " times in the list.\n";

	// Ditto for partial search...
	cout << "Enter a word for a partial search: ";

	//if (no matches found)
	//	cout << "\nNo entries match '" << searchTerm << '\'' << endl;
	//else
	{
	//	cout << "\nWords containing '" << thesearchterm << '\'' << endl;

      // print list o' matches
	}

	return 0;
}

