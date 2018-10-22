#include<iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

struct Hero {

	struct Item {
		string name;
		int value;
		float weight;

		Item(string name, int value, float weight) {
			this->name = name;
			this->value = value;
			this->weight = weight;
		}
	};

	//Hero attributes
	string name;
	short strength, intelligence, agility;
	int hp, maxhp;
	float armor, magicArmor;
	vector<Item> inventory;

	Hero(string name, short strength, short intelligence, short agility, int hp, 
		int maxhp, float armor, float magicArmor, vector<Item> inventory) {
		this->name = name;
		this->strength = strength;
		this->intelligence = intelligence;
		this->agility = agility;
		this->hp = hp;
		this->maxhp = maxhp;
		this->armor = armor;
		this->magicArmor = magicArmor;
		this->inventory = inventory;
	}

	void print() {
		cout << "Name: " << name << endl;
		cout << "Str: " << strength << endl;
		cout << "Int: " << intelligence << endl;
		cout << "Agi: " << agility << endl;
		cout << "HP: " << hp << " / " << maxhp << endl;
		cout << "Armor: " << armor * 100 << "%" << endl;
		cout << "Magic armor: " << magicArmor * 100 << "%" << endl;
		cout << "Inventory: " << endl;
		if (inventory.size() == 0) {
			cout << "Inventory empty." << endl;
		}
		else {
			for (Hero::Item item : inventory) {
				cout << item.name << ", " << item.value << ", " << item.weight << endl;
			}
		}
		cout << endl;
	}

	size_t numItems() {
		return inventory.size();
	}

	int getTotalItemValue() {
		int totalValue = 0;
		for (Item item : inventory) {
			totalValue += item.value;
		}
		return totalValue;
	}
};

string readName(ifstream& file) {
	int nameLength; //used to determine the length of the name (for reading purposes)
	file.read((char*)&nameLength, sizeof(nameLength));
	char* nameTemp = new char[nameLength]; // NUL terminator '\0' included in nameLength, string type manages its own mem
	file.read(nameTemp, nameLength); //Is casting necessary here? VS says so.
	string name = nameTemp;
	delete[] nameTemp;
	return name;
}

void loadData(vector<string>& loadQueue, vector<Hero>& heroList) {
	/*---Load each file's heroes from the loadQueue and store each object in heroList---*/
	for (string fileName : loadQueue) {

		ifstream currentFile(fileName, ios_base::binary);

		if (!currentFile.is_open()) {
			throw;
		}

		/*---number of heroes to load---*/
		int numHeroesinFile;
		currentFile.read((char*)&numHeroesinFile, sizeof(numHeroesinFile));
		
		//Create each individual hero and store in heroList
		for (int i = 0; i < numHeroesinFile; i++) {
			
			/*---Name---*/
			string name = readName(currentFile);


			/*---Strength, Intelligence, Agility---*/
			short strength, intelligence, agility;
			currentFile.read((char*)&strength, sizeof(strength));
			currentFile.read((char*)&intelligence, sizeof(intelligence));
			currentFile.read((char*)&agility, sizeof(agility));

			/*---HP, maximum HP---*/
			int hp, maxhp;
			currentFile.read((char*)&hp, sizeof(hp));
			currentFile.read((char*)&maxhp, sizeof(maxhp));

			/*---Armor, maximum armor---*/
			float armor, magicArmor;
			currentFile.read((char*)&armor, sizeof(armor));
			currentFile.read((char*)&magicArmor, sizeof(magicArmor));

			/*---Inventory---*/
			int numItems;
			currentFile.read((char*)&numItems, sizeof(numItems));
			vector<Hero::Item> inventory; //Only way  to access the items is like this, requires public access
			
			//Load in each individual item
			for (int i = 0; i < numItems; i++) {
				
				/*---Item name---*/
				string itemName = readName(currentFile);

				/*---value---*/
				int value;
				currentFile.read((char*)&value, sizeof(value));

				/*---weight---*/
				float weight;
				currentFile.read((char*)&weight, sizeof(weight));

				Hero::Item item(itemName, value, weight);
				inventory.push_back(item);
			}

			Hero hero(name, strength, intelligence, agility, hp, maxhp, armor, magicArmor, inventory);
			heroList.push_back(hero);
		}
		currentFile.close();
	}
}

void PrintHeroList(vector<Hero>& heroList);
void MostItems(vector<Hero>& heroList);
void StrongestHero(vector<Hero>& heroList);
void ListIntellects(vector<Hero>& heroList);
void ListClumsiest(vector<Hero>& heroList);
void MostValuableStuff(vector<Hero>& heroList);

int main() {
	cout << "Which file(s) to open?\n";
	cout << "1. fantasyheroes.dat" << endl;
	cout << "2. superheroes.dat" << endl;
	cout << "3. Both files" << endl;
	int option;
	cin >> option;

	vector<string> loadQueue;
	string fileNames[] = { "fantasyheroes.dat", "superheroes.dat" };

	switch (option) {
	case 1: loadQueue.push_back(fileNames[0]);
		break;
	case 2: loadQueue.push_back(fileNames[1]);
		break;
	case 3: loadQueue = { "fantasyheroes.dat", "superheroes.dat" };
			break;
	case 4: loadQueue.push_back("SAMPLE_heroes.dat"); break; //for testing purposes only-- delete this line before submission
	default: cout << "Invalid input." << endl;
		return -1;
	}

	/* Load hero files here */
	vector<Hero> heroList;
	loadData(loadQueue, heroList);
	

	cout << "1. Print all heroes" << endl;
	cout << "2. Hero with the most items" << endl;
	cout << "3. Strongest hero" << endl;
	cout << "4. Heroes with greater than 18 intelligence" << endl;
	cout << "5. 2 clumsiest heroes" << endl;
	cout << "6. Hero with the most valuable stuff" << endl << endl;

	cin >> option;

	/* Work your magic here */
	switch (option) {
	case 1: PrintHeroList(heroList);
		break;
	case 2: MostItems(heroList);
		break;
	case 3: StrongestHero(heroList);
		break;
	case 4: ListIntellects(heroList);
		break;
	case 5: ListClumsiest(heroList);
		break;
	case 6: MostValuableStuff(heroList);
		break;
	default: cout << "Invalid input." << endl;
		return -1;
	}

	return 0;
}

void PrintHeroList(vector<Hero>& heroList) {
	for (Hero hero : heroList) {
		hero.print();
	}
}

void MostItems(vector<Hero>& heroList) {
	Hero heroWithMostItems = heroList.at(0);
	for (Hero hero : heroList) {
		if (hero.numItems() > heroWithMostItems.numItems()) {
			heroWithMostItems = hero;
		}
	}
	heroWithMostItems.print();
}

void StrongestHero(vector<Hero>& heroList) {
	Hero strongestHero = heroList.at(0);
	for (Hero hero : heroList) {
		if (hero.strength > strongestHero.strength) {
			strongestHero = hero;
		}
	}
	strongestHero.print();
}

void ListIntellects(vector<Hero>& heroList) {
	vector<Hero> intellects;
	for (Hero hero : heroList) {
		if (hero.intelligence > 18) {
			intellects.push_back(hero);
		}
	}
	//Print intellects
	for (Hero hero : intellects) {
		hero.print();
	}
}

void ListClumsiest(vector<Hero>& heroList) {
	vector<Hero> copy(heroList); //Copies the vector

	Hero clumsiest = heroList.at(0),
		secondClumsiest = heroList.at(0);
	unsigned int idx = 0;
	//Get the clumsiest first
	for (unsigned int i = 0; i < heroList.size(); i++) {
		if (heroList.at(i).agility < clumsiest.agility) {
			clumsiest = heroList.at(i);
			idx = i;
		}
	}
	cout << "Clumsiest hero:" << endl;
	clumsiest.print();

	//Get rid of clumsiest
	

	//Second clumsiest
	for (unsigned int i = 0; i < heroList.size(); i++) {
		if (heroList.at(i).agility < secondClumsiest.agility && i != idx) {
			secondClumsiest = heroList.at(i);
		}
	}
	cout << "Second clumsiest hero: " << endl;
	secondClumsiest.print();
}

void MostValuableStuff(vector<Hero>& heroList) {
	Hero richestHero = heroList.at(0);
	for (Hero hero : heroList) {
		if (hero.getTotalItemValue() > richestHero.getTotalItemValue()) {
			richestHero = hero;
		}
	}
	richestHero.print();
}
