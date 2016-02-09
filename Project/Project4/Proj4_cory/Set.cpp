#include "Set.h"
#include <iostream>

template <class T> Set<T>::Set() {
}

template <class T> void Set<T>::reset() {current.clear();}

template <class T> void Set<T>::print() {
	for (int i = 0; i < current.size(); ++i)
	{
		cout << current[i];
	}
}

template <class T> bool Set<T>::find_item(T item) {
	for (int i = 0; i < current.size(); i++){
		if (current[i] == item) {
			location = i;
			return true;;
		}
	}
	return false;
}

template <class T> void Set<T>::insert_item(T item) {
	if (!find_item(item)){
		current.push_back(item);
	}
}

template <class T> bool Set<T>::delete_item(T item) {
	bool found = find_item(item);
	if (found){
		current.erase(current.begin()+location);
	}
	return found;
}

template <class T> T Set<T>::get_name(int i) {return current[i];}

template <class T> int Set<T>::get_size() {return current.size();}

template <class T> int Set<T>::get_location() {return location;}

//operator overloading
//
//union
const Set template <class T> Set<T>::operator+(const Set & yourSet) const{

		vector<T> tempYourSet;

		for (int i =0; i < yourSet.size();i++){
			tempYourSet.push_back(yourSet[i]);
		}

		for (int i =0; i < yourSet.size(); i++){
			for (int j=0; j < current.size(); j++){
				if (yourSet[i]==current[j]){
					tempYourSet.erase(tempYourSet.begin()+i);
				}
			}
		}

		for (int i =0; i < tempYourSet.size();i++){
			current.push_back(tempYourSet[i]);
		}
		
		if (!silent){
			cout << inFileName << " union completed" << endl;
		}

		return current;
}

//subtraction
const Set template <class T> Set<T>::operator-(const Set & yourSet) const;  
const Set template <class T> Set<T>::operator*(const Set & yourSet) const;  //intersect
const Set template <class T> Set<T>::operator^(const Set & yourSet) const;  //difference

Set & template <class T> Set<T>::operator=(const Set & yourSet);  //deep copy
Set & template <class T> Set<T>::operator==(const Set & yourSet);  //equality
Set & template <class T> Set<T>::operator<(const Set & yourSet);  //proper subset
Set & template <class T> Set<T>::operator<=(const Set & yourSet);  //subset

ostream & template <class T> Set<T>::operator<<(ostream & os, const Set mySet){
	for (int i = 0; i < this->current.size(); i++){
		os << this->current[i] << endl;
	}

}
istream & template <class T> Set<T>::operator>>(istream & is, const Set mySet){
	for (int i = 0; i < mySet.size(); i++){
		this->current[i] = mySet,current[i];
	}

}

