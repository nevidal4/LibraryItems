#ifndef ALBUM_H
#define ALBUM_H
#include "item.h"
//using namespace std;
class Album : public Item {
private:
	char* artist;
	char* format;
public:
	Album(int n, char* t, char* a, char* f);
	Album(const Album& a);
	virtual ~Album();
	virtual void output();
};
#endif
