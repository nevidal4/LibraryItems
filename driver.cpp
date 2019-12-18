#include "driver.h"
#include <iostream>
#include <fstream>
using namespace std;
ofstream csis;
const int NUM_ITEMS = 5;
const int BUFFER_SIZE = 50;
int main() {
	//Andrews Samuel
	//008559913
	Item** it;
	it = new Item*[NUM_ITEMS];
	csis.open("csis.txt");
	getInfo(it);
	cout << "\nHere are the items:" << endl;
	csis << "\nHere are the items:" << endl;
	for (int j = 0; j < NUM_ITEMS; ++j) {
		it[j]->output();
		delete it[j];
	}
	delete[] it;
	csis.close();
	return 0;
}
void getInfo(Item** ia) {
	cout << "Enter items to be stored in a list:" << endl;
	csis << "Enter items to be stored in a list:" << endl;
	char choice;
	int num;
	char title[BUFFER_SIZE];
	char creator[BUFFER_SIZE];
	char format[BUFFER_SIZE];
	for (int i = 0; i < NUM_ITEMS; ++i) {
		cout << "Enter 'B' for book or 'R' for recording: ";
		csis << "Enter 'B' for book or 'R' for recording: ";
		cin >> choice;
		cin.getline(title, sizeof(title));
		csis << choice << endl;
		choice = toupper(choice);
		if (choice == 'R') {
			cout << "\nEnter album title: ";
			csis << "\nEnter album title: ";
			cin.getline(title, sizeof(title));
			csis << title << endl;
			cout << "\nEnter artist: ";
			csis << "\nEnter artist: ";
			cin.getline(creator, sizeof(creator));
			csis << creator << endl;
			cout << "\nEnter file format: (1)MP3, (2)WAV, (3)AIFF: ";
			csis << "\nEnter file format: (1)MP3, (2)WAV, (3)AIFF: ";
			cin >> num;
			csis << num << endl;
			*format = '\0';
			switch (num) {
			case 1: strcpy(format, "MP3"); break;
			case 2: strcpy(format, "WAV"); break;
			case 3: strcpy(format, "AIFF");
			}

			cout << "\nEnter ID number: ";
			csis << "\nEnter ID number: ";
			cin >> num;
			csis << num << endl;
			cout << endl;
			Album* a = new Album(num, title, creator, format);
			ia[i] = a;
		}
		else if (choice == 'B') {
			cout << "\nEnter book title: ";
			csis << "\nEnter book title: ";
			cin.getline(title, sizeof(title));
			csis << title << endl;
			cout << "\nEnter book author: ";
			csis << "\nEnter book author: ";
			cin.getline(creator, sizeof(creator));
			csis << creator << endl;
			cout << "\nEnter ID number: ";
			csis << "\nEnter ID number: ";
			cin >> num;
			csis << num << endl;
			cout << endl;
			Book* b = new Book(num, title, creator);
			ia[i] = b;
		}
		else {
			cout << "\nPlease be kind and cooperate so we can go home." << endl;
			csis << "\nPlease be kind and cooperate so we can go home." << endl;
			--i;
			continue;
		}
	}
}