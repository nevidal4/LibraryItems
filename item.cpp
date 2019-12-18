#include "item.h"
#include <iostream>
using namespace std;
Item::Item(int n, char* t) {
	num = n;
	title = new char[strlen(t) + 1];
	*title = '\0';
	strcpy(title, t);
}
Item::Item(const Item& it) {
	num = it.num;
	title = new char[strlen(it.title) + 1];
	*title = '\0';
	strcpy(title, it.title);
}
Item::~Item() {
	delete[] title;
}
