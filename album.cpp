#include "Album.h"
#include <iostream>
#include <fstream>
using namespace std;
extern ofstream csis;
Album::Album(int n, char* t, char* a, char* f) : Item(n, t) {
	artist = new char[strlen(a) + 1];
	*artist = '\0';
	strcpy(artist, a);
	format = new char[strlen(f) + 1];
	*format = '\0';
	strcpy(format, f);
}
Album::Album(const Album& a) : Item(a) {
	artist = new char[strlen(a.artist) + 1];
	*artist = '\0';
	strcpy(artist, a.artist);
	format = new char[strlen(a.format) + 1];
	*format = '\0';
	strcpy(format, a.format);
}
Album::~Album() {
	delete[] artist;
	delete[] format;
}
void Album::output() {
	cout << "\"" << title << "\"" << " " << artist << " " << "(" << format << ")" << " " << num << endl;
	csis << "\"" << title << "\"" << " " << artist << " " << "(" << format << ")" << " " << num << endl;
}