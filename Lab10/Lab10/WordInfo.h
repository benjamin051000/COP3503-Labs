#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <vector>
#include <map>
using namespace std;

class WordInfo {
	map<string, int> wordOccurrences;
	vector<string> ignoredWords;

public:
	WordInfo();

	/*Open and read the indicated file, storing the words
	in the file and how many times they appear*/
	void ReadWordsFromFile(const char *filename);

	/*Print out the number of words, number of unique 
	words, and average word length*/
	void DisplayStats() const;

	/*Print out the "count" most frequently found words in the file.
	The optional boolean variable indicates whether to use
	the list of very common words to ignore*/
	void MostCommonWords(int count, bool ignoreCommonFile = false) const;

	/*Finds the longest word(s) and stores them in the output parameter*/
	void LongestWords(vector<string> &words) const;
	
	/*Set a list of words to ignore when searching for
	frequently occurring words in the file*/
	void SetIgnoreWords(vector<string> &ignore);

	/*Find search for an exact match, return the number of occurrences.
	Return 0 if no occurrences are found.*/
	int SearchForWord(const char *word) const;

};