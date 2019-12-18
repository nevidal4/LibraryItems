#ifndef ITEM_H
#define ITEM_H
//using namespace std;
class Item {
protected:
	int num;
	char* title;
public:
	Item(int n, char* t);
	Item(const Item& it);
	virtual ~Item();
	virtual void output() = 0;
};
#endif
