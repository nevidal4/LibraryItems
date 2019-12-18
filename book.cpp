#include "Book.h"
#include <iostream>
#include <fstream>
using namespace std;
extern ofstream csis;
Book::Book(int n, char* t, char* a) : Item(n, t) {
	author = new char[strlen(a) + 1];
	*author = '\0';
	strcpy(author, a);
}
Book::Book(const Book& b) : Item(b) {
	author = new char[strlen(b.author) + 1];
	*author = '\0';
	strcpy(author, b.author);
}
Book::~Book() {
	delete[] author;
}
void Book::output() {
	cout << "\"" << title << "\"" << " " << author << " " << num << endl;
	csis << "\"" << title << "\"" << " " << author << " " << num << endl;
}