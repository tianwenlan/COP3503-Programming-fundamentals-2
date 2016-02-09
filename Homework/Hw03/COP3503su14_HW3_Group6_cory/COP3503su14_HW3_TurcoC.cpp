#include <iostream>
#include <limits>
#include <vector>
#include <time.h>
using namespace std;

void move(int, int, vector<int> *, vector<int> *, vector<int> *, bool);
void swap(vector<int> *, vector<int> *);
void print(vector<int> *, vector<int> *, vector<int> *);

int main (int argc, char ** argv) {

	int n, d;
	vector<int> a, b, c;
	bool silent = false;
	clock_t t1,t2;

	for (int i =0; i < argc; i++){
		if (string(argv[i]) == "-s") {
			silent = true;
		}
	}

	cout << "Enter the number of disks: ";
	cin >> n;
	//checks that the user actually input an integer (uses <limit> library)
	while(cin.fail()){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cerr << "Number invalid: only positive integers are accepted" << endl << ">";
		cin >> n;
	}
	//creating initial stack
	for (int i = n; i > 0; i--){
		a.push_back(i);
	}
	print(&a, &b, &c);
	t1 = clock();			//actual start of solving puzzle
	//determines direction of moving plate 1
		//if n is even
	if (n % 2 == 0) {
		d = 1; //down
	} else {
		d = 0; //up
	}
	move(d, n, &a, &b, &c, silent);
	t2 = clock(); 			//actual end of solving puzzle
	print(&a, &b, &c);
	//timing used for graph will be silent mode runs only
	double diff ((double)t2 - (double)t1);
	float sec = diff/CLOCKS_PER_SEC;
	cout << sec << endl;
	return 0;
};

void move(int d, int n, vector<int> * a, vector<int> * b, vector<int> * c, bool silent){
	//end case
	if (c->size() == n - 1 && c->back() != 1) {
		c->push_back(1);
		if(a->size() != 0) {
			a->pop_back();
		}
		else {
			b->pop_back();
		}
		return;
	};
	//iteration
	int temp;
	switch(d) {

		case 0: 
			if (a->back() == 1) {
				a->pop_back();
				c->push_back(1);
				if(!silent) print(a, b, c);
				swap(a, b);
			}
			else if (b->back() == 1) {
				b->pop_back();
				a->push_back(1);
				if(!silent) print(a, b, c);
				swap(b, c);
			}
			else if (c->back() == 1) {
				c->pop_back();
				b->push_back(1);
				if(!silent) print(a, b, c);
				swap(c, a);
			}
			break;

		case 1: 
			if (a->back() == 1) {
				a->pop_back();
				b->push_back(1);
				if(!silent) print(a, b, c);
				swap(a, c);
			}
			else if (b->back() == 1) {
				b->pop_back();
				c->push_back(1);
				if(!silent) print(a, b, c);
				swap(b, a);
			}
			else if (c->back() == 1) {
				c->pop_back();
				a->push_back(1);
				if(!silent) print(a, b, c);
				swap(c, b);
			}
			break;
	}
	if(!silent) print(a, b, c);
	move(d, n, a, b, c, silent);
}
//makes only logical move after 1 has been moved
void swap(vector<int> * a, vector<int> * b) {
	if(b->size() == 0) {
		b->push_back(a->back());
		a->pop_back();
	}
	else if (a->size() == 0) {
		a->push_back(b->back());
		b->pop_back();
	}
	else if (a->back() > b->back()) {
		a->push_back(b->back());
		b->pop_back();
	}
	else {
		b->push_back(a->back());
		a->pop_back();
	}
}
//print helper function
void print(vector<int> * a, vector<int> * b, vector<int> * c) {
	cout << "===================" << endl << "Tower 0: ";
	for (int i = 0; i < a->size(); i++) {
		cout << a->at(i) << " ";
	}
	cout << endl << "Tower 1: ";
	for (int i = 0; i < b->size(); i++) {
		cout << b->at(i) << " ";
	}
	cout << endl << "Tower 2: ";
	for (int i = 0; i < c->size(); i++) {
		cout << c->at(i) << " ";
	}
	cout << endl;
}