#ifndef BOOK_H
#define BOOK_H
#include "item.h"
//using namespace std;
class Book : public Item {
private:
	char* author;
public:
	Book(int n, char* t, char* a);
	Book(const Book& b);
	virtual ~Book();
	virtual void output();
};
#endif
