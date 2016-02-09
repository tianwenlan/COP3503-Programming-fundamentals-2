#include <string>
#include <iostream>
using namespace std;

template <typename T>

int compare(const T &v1, const T &v2){

	if (v1<v2) return -1;
	if (v2<v1) return 1;
	return 0;
}

int main(){
	int a=10;
	int b =21;
	char c = 'c';
	char d = 'd';
	string e= "desk"; 
	string f = "chair";

	int r=0;

	r=compare(a,b);
	cout << r << endl;

	r=compare(c,d);
	cout <<	r << endl;

	r=compare(e,f);
	cout << r << endl;
}


