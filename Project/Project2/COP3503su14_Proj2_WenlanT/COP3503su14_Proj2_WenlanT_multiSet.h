#ifndef proj2_multiSet_H
#define proj2_multiSet_H
#include <string>
#include <vector>
#include <stdlib.h>
#include "COP3503su14_Proj2_WenlanT_object.h"

using namespace std;

class MultiSet{
	private:
	vector <Object> multiSet;
	int size;

	public:
	int reset();
	void print();
	int printToFile();
	int  findItem(string);
	void getInsert(string &, int &);
	int insertItem(string, int); 
	int deleteItem(string);
	int reduceItem(string, int);
	int inputFile(string ); 
	int unionSets();
	int subtractSets();
	int differenceSets();
	int intersectSets();
	int maxSets();

	MultiSet();
	
	bool verbose;
	bool silent;
};

#endif
