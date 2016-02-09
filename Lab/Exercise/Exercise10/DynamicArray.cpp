#include <iostream>
#include <string>
#include "DynamicArray.h"

using namespace std;

DynamicArray::DynamicArray():mySize(0), myCapacity(5), arr(new string[myCapacity]){
}

DynamicArray::DynamicArray(int capacity):mySize(0),myCapacity(capacity), arr(new string[myCapacity]){
}

//////////When use deconstruct, the program crashed. Why????????//////////
DynamicArray::~DynamicArray(){
	cout << "I am dying!!!" << endl;
//	delete[] arr;
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

	return *this;
}

const DynamicArray DynamicArray::operator+(const DynamicArray & rhs) const{

	DynamicArray temp;

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

