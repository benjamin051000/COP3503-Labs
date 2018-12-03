#include "WordInfo.h"

WordInfo::WordInfo() {
}

void WordInfo::ReadWordsFromFile(const char * filename) { 
	ifstream file;
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

			/*Remove outer non-letters*/
			char firstChar = word[0];
			while (firstChar != '\0' && !isalpha(firstChar)) {
				word.erase(word.begin());
				firstChar = word[0];
			}

			if (word != "") {
				char lastChar = word[word.length() - 1];
				while (lastChar != '\0' && !isalpha(lastChar) && lastChar != '\'') {
					
					word.pop_back();
					lastChar = word[word.length() - 1];
				}
			}

			/*Convert to lowercase*/
			for (unsigned int i = 0; i < word.length(); i++) {
				word[i] = tolower(word[i]);
			}

			wordOccurrences[word] += 1;
			totalWords++;
		}

	}
	totalWords -= wordOccurrences[""];
	wordOccurrences.erase("");

	/*Generate wordFrequencies from wordOccurrences*/
	for (unordered_map<string, int>::const_iterator it = wordOccurrences.begin();
		it != wordOccurrences.end(); it++) {
		wordFrequencies.emplace(it->second, it->first);
	}

	

	cout << endl;
}

void WordInfo::DisplayStats() const {
	cout << "Total number of words: " << totalWords << endl;
	cout << "Number of unique words: " << wordOccurrences.size() << endl;
	cout << "Average word length: " << AvgLength() << endl;
	vector<string> longest;
	LongestWords(longest);
	cout << "Longest word: " << longest[0] << endl;
}

void WordInfo::MostCommonWords(int count, bool ignoreCommonFile) const {
	cout << count << " most frequent words";
	if (ignoreCommonFile) {
		cout << " (ignoring most commonly used): " << endl;
	}
	else {
		cout << ": " << endl;
	}

	int i = 1;
	for (multimap<int, string>::const_reverse_iterator it = wordFrequencies.rbegin(); 
		it != wordFrequencies.rend(); it++) {
		
		/*Guard from the ignored words if it is enabled*/
		if (ignoreCommonFile) {
			if (find(ignoredWords.begin(), ignoredWords.end(), it->second) != ignoredWords.end()) {
				continue;
			}
		}
		
		if (i <= count) {
			cout << it->second << ' ' << it->first << endl;
			i++;
		}
		else {
			break;
		}
	}
	cout << endl;
}

void WordInfo::LongestWords(vector<string>& words) const {
	string max = "";
	for (unordered_map<string, int>::const_iterator it = wordOccurrences.begin(); it != wordOccurrences.end(); it++) {
		if (it->first.length() > max.length()) {
			max = it->first;
		}
	}

	for (unordered_map<string, int>::const_iterator it = wordOccurrences.begin(); it != wordOccurrences.end(); it++) {
		if (it->first.length() == max.length()) {
			words.push_back(it->first);
		}
	}

}

void WordInfo::SetIgnoreWords(vector<string>& ignore) {
	ignoredWords = ignore;
}

int WordInfo::SearchForWord(string& keyword) const {
	/*Lowercase the keyword*/
	for (unsigned int i = 0; i < keyword.length(); i++) {
		keyword[i] = tolower(keyword[i]);
	}

	if (wordOccurrences.find(keyword) != wordOccurrences.end()) {
		return wordOccurrences.at(keyword);
	}
	else return 0;
}

vector<string> WordInfo::PartialSearch(const char * word) const {
	vector<string> output;
	for (unordered_map<string, int>::const_iterator it = wordOccurrences.begin(); it != wordOccurrences.end(); it++) {
		if (it->first.find(word) != string::npos) {
			output.push_back(it->first);
		}
	}
	return output;
}

int WordInfo::AvgLength() const { //broken!!!
	unsigned int totalChars = 0;
	for (unordered_map<string, int>::const_iterator it = wordOccurrences.begin(); it != wordOccurrences.end(); it++) {
		totalChars += (it->first.length() * it->second);
	}
	return totalChars / totalWords;
}
