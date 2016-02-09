#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
#include <iostream>
#include <string>

using namespace std;


class DynamicArray{
	private:
	int mySize;
	int myCapacity;
	string *arr;
	void grow();

	public:

	DynamicArray();
	DynamicArray(int);
	~DynamicArray();
	bool insert(string);
	string remove();
	string remove(int);
	void remove(string);
	int index_of(string);
	string item_at(int);
	int size();
	int capacity();
	void clear();
	DynamicArray & operator=(const DynamicArray &);
	const DynamicArray operator+(const DynamicArray &) const;
	string & operator[](const int);
	friend ostream & operator<<(ostream &, const DynamicArray);
};

#endif

