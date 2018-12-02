#include "WordInfo.h"

WordInfo::WordInfo() {
}

void WordInfo::ReadWordsFromFile(const char * filename) {
	ifstream file;
	cout << "Opening " << filename << "..." << endl;
	file.open(filename);
	
	if (!file.is_open()) {
		cout << "Failed to open " << filename << endl;
		return;
	}
	
	string line;
	while (getline(file, line, '\n')) {
		stringstream token(line);
		string word;

		while (getline(token, word, ' ')) {
			/*If the word is a null string (from multiple consecutive 
			spaces occurring in the file), skip over it.*/
			if (word == "") {
				continue;
			}

			/*Remove outer non-letters*/
			char firstChar = word[0];
			while (!isalpha(firstChar)) {
				word.erase(word.begin());
				firstChar = word[0];
			}

			char lastChar = word[word.length() - 1];
			while (!isalpha(lastChar)) {
				word.pop_back();
				lastChar = word[word.length() - 1];
			}

			/*Convert to lowercase*/
			for (unsigned int i = 0; i < word.length(); i++) {
				word[i] = tolower(word[i]);
			}

			wordOccurrences[word] += 1;
		}
		
	}
	cout << endl;
}

void WordInfo::DisplayStats() const {
	cout << "Ignored words: ";
	for (string s : ignoredWords) {
		cout << s << ' ';
	}
	cout << endl;
	for (map<string, int>::const_iterator it = wordOccurrences.begin(); it != wordOccurrences.end(); it++) {
		cout << it->first << ": " << it->second << endl;
	}
}

void WordInfo::MostCommonWords(int count, bool ignoreCommonFile) const {

}

void WordInfo::SetIgnoreWords(vector<string>& ignore) {
	ignoredWords = ignore;
}
