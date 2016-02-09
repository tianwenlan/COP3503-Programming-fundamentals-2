#ifndef proj2_object_H
#define proj2_object_H
#include <string>
#include <vector>

using namespace std;

class Object{
	private:
	string name;
	int count;

	public:
	string getName();
	int getCount();
	void setName(string);
	void setCount(int);
};

#endif
