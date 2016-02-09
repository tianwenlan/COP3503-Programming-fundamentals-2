#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include "Proj4.h"

using namespace std;

template <class T> MySet<T>::MySet():location(0) {
}

template <class T> 
void MySet<T>::clear() {current.clear();}


template <class T> 
void MySet<T>::print() {
	for (int i = 0; i < this->current.size(); ++i)
	{
		cout << this->current[i];
	}
}


template <class T> 
bool MySet<T>::find(T item) {
	for (int i = 0; i < current.size(); i++){
		if (current[i] == item) {
			location = i;
			return true;;
		}
	}
	return false;
}

template <class T> 
void MySet<T>::addElt(T item) {
	if (!find(item)){
		current.push_back(item);
	}
}

template <class T> 
bool MySet<T>::deleteElt(T item) {
	bool found = find(item);
	if (found){
		current.erase(current.begin()+location);
	}
	return found;
}

template <class T> 
int MySet<T>::compare(MySet<T> & yourSet) {
	if(*this==yourSet){
		return 0;
	}else if((*this < yourSet)==1){
		return -1;
	}else if((yourSet < *this)==1){
		return 1;
	}else {
		return 2;
	}
}


template <class T> 
T MySet<T>::get_name(int i) {
	return current[i];
}

template <class T> 
int MySet<T>::size() {
	return this->current.size();
}

template <class T> 
int MySet<T>::get_location() {
	return location;
}

//operator overloading

//union
template <class T> 
MySet<T> MySet<T>::operator+(const MySet<T> & yourSet) const {

	MySet <T> mySet;
	for (int i =0; i< this->current.size(); i++){
		mySet.current.push_back(this->current[i]);
	}


	for (int i =0; i < yourSet.current.size(); i++){
		bool found = false;

		for (int j=0; j < mySet.current.size(); j++){
			if (yourSet.current[i]==mySet.current[j]){
				found = true;
			}
		}

		if(found==false){
			mySet.current.push_back(yourSet.current[i]);
		}
	}
		
	if (!silent){
		cout << "Union completed" << endl;
	}
	
	return mySet;
}

//subtraction
template <class T> 
MySet<T> MySet<T>::operator-(const MySet<T> & yourSet) const{

	MySet <T> mySet;

	for (int i =0; i< this->current.size(); i++){
		mySet.current.push_back(this->current[i]);
	}

	for (int i =0; i < yourSet.current.size(); i++){

		for (int j=0; j < mySet.current.size(); j++){
			if (yourSet.current[i]==mySet.current[j]){
				mySet.current.erase(mySet.current.begin()+j);
			}
		}

	}
		
	if (!silent){
		cout << "Subtract completed" << endl;
	}
	
	return mySet;

}

 //intersect
template <class T> 
MySet<T> MySet<T>::operator*(const MySet<T> & yourSet) const{
	MySet <T> mySet;

	for (int i =0; i < yourSet.current.size(); i++){

		for (int j=0; j < this->current.size(); j++){
			if (yourSet.current[i]==this->current[j]){
				mySet.current.push_back(yourSet.current[i]);
			}
		}

	}

		
	if (!silent){
		cout << "Intersect completed" << endl;
	}
	
	return mySet;


}

//difference
template <class T> 
MySet<T> MySet<T>::operator^(const MySet<T> & yourSet) const{
	MySet <T> mySet;

	for (int i =0; i < yourSet.current.size(); i++){
		bool found = false;

		for (int j=0; j < this->current.size(); j++){
			if (yourSet.current[i]==this->current[j]){
				found = true;
			}
		}

		if(!found){
			mySet.current.push_back(yourSet.current[i]);
		}

	}

	for (int i =0; i < this->current.size(); i++){
		bool found = false;

		for (int j=0; j < yourSet.current.size(); j++){
			if (this->current[i]==yourSet.current[j]){
				found = true;
			}
		}

		if(!found){
			mySet.current.push_back(this->current[i]);
		}
	}

		
	if (!silent){
		cout << "Difference completed" << endl;
	}
	
	return mySet;

}

//deep copy
template <class T> 
MySet<T> & MySet<T>::operator=(const MySet<T> & yourSet){
	this->clear();

	for(int i =0; i< yourSet.current.size();i++){
		this->current.push_back(yourSet.current[i]);
	}
	return *this;
}

//equality
template <class T> 
int operator==(const MySet<T> & mySet, const MySet<T> & yourSet){

	if(mySet.current.size()!=yourSet.current.size()){
		return 0;
	}else{
		for(int i =0; i< mySet.current.size(); i++){
			bool found = false;
			for(int j =0; j< yourSet.current.size(); j++){
				if(mySet.current[i]==yourSet.current[j]){
					found = true;
				}
			}
			if(!found){
				return 0;
			}			
		}
		return 1;

	}
	
}

//proper subset
template <class T> 
int operator < (const MySet<T> & mySet,const MySet<T> & yourSet){

	if(mySet.current.size() < yourSet.current.size()){
		for(int i =0; i< mySet.current.size(); i++){
			bool found = false;
			for(int j =0; j< yourSet.current.size(); j++){
				if(mySet.current[i]==yourSet.current[j]){
					found = true;
				}
			}
			if(!found){
				return 0;
			}			
		}
		return 1;

	}else{
		return 0;
	}


}


template <class T> 
ostream & operator<<(ostream & os, const MySet<T> mySet){
	for (int i = 0; i < mySet.current.size(); i++){
		os << mySet.current[i] << endl;
	}
	return os;

}
template <class T> 
istream & operator>>(istream & is, MySet<T> &mySet){

	T temp;
	is >> temp;
	mySet.current.push_back(temp);
	return is;
}

