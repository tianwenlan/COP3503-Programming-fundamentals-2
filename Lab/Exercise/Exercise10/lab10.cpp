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
	//constructors/destructor
	DynamicArray();
	DynamicArray(int);
	~DynamicArray();

	//dynamic array functions
	bool insert(string);
	string remove();
	string remove(int);
	void remove(string);
	int index_of(string);
	string item_at(int);
	int size();
	int capacity();
	void clear();

	//operator overloading
	DynamicArray & operator=(const DynamicArray &);
	const DynamicArray operator+(const DynamicArray &) const;
	string & operator[](const int);
	friend ostream & operator<<(ostream &, const DynamicArray);
};


DynamicArray::DynamicArray():mySize(0), myCapacity(5), arr(new string[myCapacity]){
	for(int i =0; i< myCapacity; i++){
		arr[i] = "";
	}
}

DynamicArray::DynamicArray(int capacity):mySize(0),myCapacity(capacity), arr(new string[myCapacity]){
	for(int i =0; i< myCapacity; i++){
		arr[i] = "";
	}

}

//////////When use deconstruct, the program crashed. Why????????//////////
DynamicArray::~DynamicArray(){
	cout << "I am dying!!!" << endl;
//	delete []arr;
}

bool DynamicArray::insert(string str){
	if(mySize < myCapacity){
		arr[mySize] = str;
		mySize++;
	}else{
		grow();
		arr[mySize] = str;
		mySize ++;
	}
	return true;
}

string DynamicArray::remove(){
	if(mySize > 0){
		mySize--;
		return arr[mySize];
	}else{
		return "";
	}
}

string DynamicArray::remove(int index){
	string result;
	if(mySize > 0 && index == mySize -1){
		mySize --;
		return arr[index];
	}else if (mySize > 0 && index < mySize-1 && index>0){
		result = arr[index];
		for(int i = index; i < mySize-1; i++){
			arr[i] = arr[i+1];
		}
		mySize --;
		return result;
	}else{
		return "";
	}
}

void DynamicArray::remove(string str){
	int index = 0;
	bool found = false;
	for(int i =0; i< mySize; i++){
		if(arr[i]==str){
			index =i;
			found = true;
		}
	}

	if(index == mySize -1){
		mySize --;
	}else if (index< mySize-1){
		for(int i = index; i < mySize-1; i++){
			arr[i] = arr[i+1];
		}
		mySize --;
	}

	if(found == false){
		return;
	}
}

//5
int DynamicArray::index_of(string str){
	bool found = false;
	for(int i =0; i< mySize; i++){
		if(arr[i]==str){
			found = true;
			return i;
		}
	}

	if(found == false){
		return -1;
	}
}

//6  good
string DynamicArray::item_at(int index){
	if(index >= 0 && index < mySize){
		return arr[index];
	}else{
		return "";
	}

}

int DynamicArray::size(){
	return mySize;
}
	
int DynamicArray::capacity(){
	return myCapacity;
}

void DynamicArray::clear(){
	delete []arr;
	mySize = 0;
	myCapacity =0;
}

void DynamicArray::grow(){
	string *tempArr = new string[2*myCapacity];
	for(int i =0; i<mySize; i++){
		tempArr[i]=arr[i];
	}
	arr = tempArr;
	myCapacity = 2*myCapacity;
}

DynamicArray & DynamicArray::operator=(const DynamicArray & rhs){
	if(this!=&rhs){
		this->clear();
		this->myCapacity = rhs.mySize;
		this->arr = new string[this->myCapacity];
	
		for(int i=0; i< rhs.mySize;i++){
			this->insert(rhs.arr[i]);
		}
	}
/*

	if(this!=&rhs){
		myCapacity = rhs.myCapacity;
		mySize = rhs.mySize;
		arr = new string[myCapacity];

		for(int i=0; i< rhs.mySize;i++){
		arr[i] =rhs.arr[i];
		}
	}
	*/
	return *this;
}

DynamicArray::DynamicArray(DynamicArray & da){
this->arr = da.arr;
this->mySize = da.mySize;
this->myCapacity = da.myCapacity;
}

const DynamicArray DynamicArray::operator+(const DynamicArray & rhs) const{

	DynamicArray temp;
//	DynamicArray a2 = temp;

	temp.myCapacity = this->mySize+rhs.mySize;

	temp.arr = new string[temp.myCapacity];

	for(int i =0; i<this->mySize;i++){
		temp.insert(arr[i]);
	}

	for(int i= 0;i< rhs.mySize;i++){
		temp.insert(rhs.arr[i]);
	}

	return temp;
}

string & DynamicArray::operator[](const int index){
	return this->arr[index];
}

ostream & operator<<(ostream & os, const DynamicArray da){
	os << "[" << flush;
	for(int i =0; i < da.mySize-1; i++){

		os << da.arr[i] << ','<<flush;
	}
	os << da.arr[da.mySize-1] << "]" << flush;

	return os;
}


void pop_da(DynamicArray & da, string * str, int n){
    for(int i=0; i<n; i++)
        da.insert(str[i]);
    cout << endl;
}

void do_some_testing(string * first, int n1){
    static int run = 1;

    DynamicArray da1;

    cout << "-----------------------------------" << endl;
    cout << "              TEST " << run++ << endl;
    cout << "-----------------------------------" << endl;
    pop_da(da1, first, n1);

    cout << "Inserting done" << endl;

    cout << "initial size:                 " << flush;
    cout << (n1 == da1.size() ? "Good" : "FAIL") << endl;
    cout << "index of second to last el:   " << flush;
    cout << (n1-2 == da1.index_of(first[n1-2]) ? "Good" : "FAIL") << endl;
    cout << "item at 0:                    " << flush;
    cout << (first[0] == da1.item_at(0) ? "Good" : "FAIL") << endl;
    cout << "item at end:                  " << flush;
    cout << (first[n1-1] == da1.item_at(n1-1) ? "Good" : "FAIL") << endl;
    cout << "remove:                       " << flush;
    cout << (first[n1-1] == da1.remove() ? "Good" : "FAIL") << endl;
    cout << "remove index 1:               " << flush;
    cout << (first[1] == da1.remove(1) ? "Good" : "FAIL") << endl;
    cout << "new item at 1:                " << flush;
    cout << (first[2] == da1.item_at(1) ? "Good" : "FAIL") << endl;
    cout << "removing new 1, tesing new 2: " << flush;
    da1.remove(first[2]);
    cout << (first[4] == da1.item_at(2) ? "Good" : "FAIL") << endl;
    cout << "final size:                   " << flush;
    cout << (n1-3 == da1.size() ? "Good" : "FAIL") << endl;
    cout << "Inserting pickle:             " << flush;
    da1.insert("pickle");
    cout << (n1-3 == da1.index_of("pickle") ? "Good" : "FAIL") << endl;
    cout << "Index of invalid:             " << flush;
    cout << (-1 == da1.index_of("sdjdjkskdskj") ? "Good" : "FAIL") << endl;
    cout << "Invalid index big:            " << flush;
    cout << ("" == da1.item_at(10000) ? "Good" : "FAIL") << endl;
    cout << "Invalid index big remove:     " << flush;
    cout << ("" == da1.remove(10000) ? "Good" : "FAIL") << endl;
    cout << "Invalid index small:          " << flush;
    cout << ("" == da1.item_at(-1000) ? "Good" : "FAIL") << endl;
    cout << "Invalid index small remove:   " << flush;
    cout << ("" == da1.remove(-1) ? "Good" : "FAIL") << endl;
    cout << "Testing capacity:             " << da1.capacity() << endl; 

}

int main(){
    string test[] = {"The","Magic","Words","Are","Squeamish","Ossifrage.","You","better","believe","it", "useless", "words"};

    string letters[] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};

    string numbers[] = {"0","1","2","3","4","5","6","7","8","9"};

    string symbols[] = {"!","@","#","$","?","^","&","*","(",")" };
    
    string * big_test = new string[1000];
    for(int i=0;i<1000;i++){
        big_test[i] = to_string(i);
    }

    do_some_testing(test, 12);
    cout << endl;
    do_some_testing(letters, 26);
    cout << endl;
    do_some_testing(big_test, 1000);

    DynamicArray na;
    DynamicArray la;
    DynamicArray sa;
    pop_da(na, numbers, 10);
    pop_da(la, letters, 26);
    pop_da(sa, symbols, 10);

    cout << "Numbers: " << na << endl;
    cout << "Letters: " << la << endl;
    cout << "Symbols: " << sa << endl;

    cout << "Numbers + letters: " << (na + la) << endl;

    cout << "Numbers + letters + symbols: " << (na + la + sa) << endl;

    DynamicArray combo;
    combo = na;

    cout << "combo n: " << combo << endl;

    combo = na + combo;

    cout << "combo n + combo: " << combo << endl;

    for(int i=0; i<10; i++){
        cout << combo[i] << " " << flush;
    }
    cout << endl;

}
